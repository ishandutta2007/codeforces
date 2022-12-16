#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int l=n/2;
cout<<l*(n-l)<<endl;
for(int i=1;i<=l;i++)
    for(int j=l+1;j<=n;j++)
        cout<<i<<" "<<j<<endl;
return 0;
}