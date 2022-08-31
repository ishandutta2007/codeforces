#include <iostream>
#include <algorithm>
//#include <conio.h>
#include <cmath>
using namespace std;
     
long int sto(long int *a ,long int *b, long s){
     if (*(a+2)>*(b+0)) return -1; else {
     return s*(((2*(*a)+2*(*(a+1))-1)/(*(b+1)))/(*(b+0)/(*(a+2)))+1);                
                        
     }     
     }





     
int main ()
 {  long int n,m,i,k,j,c=0;
   cin>>n;
  long int  a[n][3];
  for (i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
  cin>>m;
   long int s[m], b[m][3];
  for (i=0;i<m;i++) cin>>b[i][0]>>b[i][1]>>s[i];
  
  
   for (i=0;i<n;i++) { long cmin=9999999;
   for (j=0;j<m;j++) { long p=sto(a[i],b[j],s[j]); if (p<cmin && p>0) cmin=p;}
   c+=cmin;}
       
        
           cout<<c;
 //   getch();
    return 0;   
         }