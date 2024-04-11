#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[201],l[201];
bitset<201>v;
main()
{
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)cin>>f[x];
    int ans=1,ma=0;
    for(int x=1,t=x,c=0;x<=n;ans=ans/__gcd(ans,c-l[t])*(c-l[t]),ma=max(ma,l[t]),x++,v=0,t=x,c=0)
    while(!v[t])l[t]=c,v[t]=true,t=f[t],c++;
    cout<<max(ans,(ma-1)/ans*ans+ans);
}