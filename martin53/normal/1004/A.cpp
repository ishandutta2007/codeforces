#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+42;
int n,d,x[nmax];
int main()
{
cin>>n>>d;
for(int i=1;i<=n;i++)cin>>x[i];
sort(x+1,x+n+1);
int ans=2;
for(int i=1;i<n;i++)
    if(x[i+1]-x[i]==2*d)ans++;
    else if(x[i+1]-x[i]>2*d)ans=ans+2;
cout<<ans<<endl;
return 0;
}