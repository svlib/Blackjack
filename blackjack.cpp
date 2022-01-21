//Sierra Libertini
//25/04/14 20:13
/*Purpose:
 * *blackjack
 */

#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <cmath>
#include <string>

   using namespace std;
   int suit,card,cardVal,total=0,deal=0,cVal[3]={0,0,21},cards=2;//global
   string StrSuit,cn,again;//global
   bool cardDrawing=true,stand=false;
   bool bust=false;//global
   string pHand[128],hHand[128];
    
    /***********************************************************
     * FUNCTION: selects the suit type of the card to be drawn *
     * ******************************************************* *
     * Input: the number for getting the suit of the card      *
     * ******************************************************* *
     * Output: returns the card suit                           *
     ***********************************************************/
    void SelectSuit (int suit){
      switch(suit){
         case 0:
            StrSuit = " \x06";
            break;
         case 1:
            StrSuit = " \x05";
            break;
         case 2:
            StrSuit = " \x03";
            break;
         case 3:
            StrSuit = " \x04";
            break;
         default:
            StrSuit = " Invalid Entry";
            break;
      }//close switch
   }//close SelectSuit
    
    /********************************************************
     * FUNCTION: selects the number of the card to be drawn *
     * **************************************************** *
     * Input: the number for getting the card number        *
     * **************************************************** *
     * Output: returns the card number                      *
     ********************************************************/
    void Cardnum (int card){
      switch(card){
         case 1:
            cn = "A ";
            cardVal=11;
            break;
         case 2:
            cn = "2 ";
            cardVal=2;
            break;
         case 3:
            cn = "3 ";
            cardVal=3;
            break;
         case 4:
            cn = "4 ";
            cardVal=4;
            break;
         case 5:
            cn = "5 ";
            cardVal=5;
            break;
         case 6:
            cn = "6 ";
            cardVal=6;
            break;
         case 7:
            cn = "7 ";
            cardVal=7;
            break;
         case 8: 
            cn = "8 ";
            cardVal=8;
            break;
         case 9:
            cn = "9 ";
            cardVal=9;
            break;
         case 10:
            cn = "10 ";
            cardVal=10;
            break;
         case 11:
            cn = "J ";
            cardVal=10;
            break;
         case 12:
            cn = "Q ";
            cardVal=10;
            break;                    
         case 13:
            cn = "K ";
            cardVal=10;
            break;
      }//close switch
   }//close Cardnum
    
    /********************************************
     * FUNCTION: chooses and displays your card *
     * **************************************** *
     * Input: nothing                           *
     * **************************************** *
     * Output: the card number and suit         *
     ********************************************/
    void cardDraw(){
      suit=rand()%4;
      SelectSuit (suit);
      //cout<<StrSuit;
      card=rand()%13;
      Cardnum(card);
   }//end cardDraw
      
      /***************************************
       * FUNCTION: asking about another card *
       * *********************************** *
       * Output: question                    *
       * *********************************** *
       * Input: response                     *
       ***************************************/
    void drawCardAgain(){
      cout<<"Do you want to hit or stand? ";
      cin>>again;
      if(again!="hit"&&again!="h")stand=true;
      if(deal==10)stand=true;
   }//end drawCardDraw
   
   
   
      /***************************
       * FUNCTION: main function *
       ***************************/            
    int main(){
      srand(time(NULL));
      while(cardDrawing==true){
         if(deal==0){
            cout<<"Dealer's hand: ";
            cardDraw();
            hHand[0]=StrSuit+cn;
            cVal[1]=cardVal+cVal[1];
            cardDraw();
            hHand[1]=StrSuit+cn;
            cVal[1]=cardVal+cVal[1];
            cout<<hHand[0]<<" "<<hHand[1]<<" <"<<cVal[1]<<">\n";
         }//end if(deal==0)
         else if(deal!=0&&stand!=true){
            cout<<"\n\nDealer's hand: ";
            /*for(int display=0;display<=deal;display++){
               cout<<hHand[display]<<" ";
               if(display==deal)cout<<"<"<<cVal[0]<<">\n";
            }//end for(int display...)*/
            cout<<hHand[0]<<" "<<hHand[1]<<" <"<<cVal[1]<<">\n";
         }//end else
         if(deal!=5&&bust!=true&&stand!=true){
            cout<<"Your hand: ";
            cardDraw();
            pHand[deal]=StrSuit+cn;
            cVal[0]=cardVal+cVal[0];
            deal++;
            if(deal==1){
               cardDraw();
               pHand[deal]=StrSuit+cn;
               cVal[0]=cardVal+cVal[0];
               cout<<pHand[deal-1]<<" "<<pHand[deal]<<" <"<<cVal[0]<<">\n";
               deal++;
            }//end if(deal==0)
            else{
               for(int rotate=0;rotate<=deal;rotate++){
                  cout<<pHand[rotate]<<" ";
                  if(rotate==deal)cout<<"<"<<cVal[0]<<">\n";
               }//close for
            }//close else
         }//close if(deal...)
         if(cVal[0]>cVal[2]||bust!=false){
            cout<<"You busted\n\n";
            bust=true;
            cardDrawing=false;
         }//end if(cVal...)
         else if(cVal[0]==cVal[2]){
            cout<<"You win";
            if(deal==2)cout<<" with blackjack!\n";
            else cout<<"!\n";
            cardDrawing=false;
         }//end else if(cVal...)
         else if(bust==false&&stand==true){
            cout<<"\nDealer's hand: ";
            cardDraw();
            hHand[cards]=StrSuit+cn;
            cVal[1]=cardVal+cVal[1];
            for(int add=0;add<cards;add++){
               cout<<hHand[add]<<" ";
               if(add==cards)cout<<"<"<<cVal[0]<<">\n";
            }//end for(int...)
            cards++;
            if(cVal[1]>21){
               cout<<"<"<<cVal[1]<<">\nDealer busted\n\n";
               cardDrawing=false;
            }//end if(cVal...)
            else if(cVal[1]==cVal[2]){
               cout<<"\nDealer wins";
               cardDrawing=false;
            }//end else if(cVal...)
         }//end if(bust...)
         else drawCardAgain();
      }//close while(cardDrawing==true)
      
      system("PAUSE");
      return 0;
   }//end main--Sierra Libertini
