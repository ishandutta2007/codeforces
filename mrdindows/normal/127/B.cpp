#include <iostream>
using namespace std;
int main ()
 {  int n,k,j,i,a[101];
    for (i=0;i<101;i++) a[i]=0;
    cin>>n;
    for (i=0;i<n;i++) {cin>>k; a[k]++;}
    k=0;
    for (i=0;i<101;i++) { k+=a[i]/2;}
    cout<<k/2;
    
    return 0;   
         }