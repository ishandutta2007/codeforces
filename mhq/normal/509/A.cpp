#include <iostream>
#include <math.h>
#include <iomanip>
 using namespace std;
 
int a[20][20]; 
 int main() {
   int n; cin>> n;
   for (int i = 1 ; i<= n; i++) {
       a[i][1] = 1 ;
       a[1][i] = 1;
       }
       for (int  i = 1 ; i<= n; i++) {
           for (int j = 1 ; j <=n; j++) {
               if (a[i][j]==0){
               a[i][j]=a[i][j-1]+a[i-1][j]; }
               }
               }
               cout<< a[n][n];
     return 0;
}