#include <iostream>
#include <algorithm>
using namespace std;
     
     
int main ()
 {  long int n,i;
 cin>>n;
     long a[n+1],b[n+1];
     for (i=1;i<=n;i++) {cin>>a[i];b[a[i]]=i;}
     cout<<b[1];
     for (i=2;i<=n;i++) {cout<<" "<<b[i];}
     
     
    return 0;   
         }