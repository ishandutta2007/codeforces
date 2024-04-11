#include <iostream>
#include <algorithm>
//#include <conio.h>
#include <cmath>
using namespace std;
     
     
int main ()
 { long int n,i,a[7],s=0,k;
   cin>>n;
   for (i=0;i<7;i++) {cin>>a[i]; s+=a[i];}
      n=n%s; 
      if (n==0) {for (i=6;i>=0;i--) if  (a[i]>0) {cout<<i+1; break;}} 
      else {
   for (i=0;i<7;i++) {n-=a[i]; k=i; if (n<=0) break;}
    cout<<k+1;}
 //   getch();
    return 0;   
         }