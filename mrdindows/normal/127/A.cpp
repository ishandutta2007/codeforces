#include <iostream>
#include <math.h>
using namespace std;
int main ()
 {  int n,k,j,i;
    double s,x,y,a,b;
    cin>>n>>k;
    cin>>x>>y;
    s=0;
    for (i=1;i<n;i++) { cin>>a>>b; s+=sqrt(pow(x-a,2)+pow(y-b,2)); x=a; y=b;}
     cout.setf(ios::fixed,ios::floatfield);
    cout<<k*s/50;
    
    return 0;   
         }