#include <bits/stdc++.h>
using namespace std;
char v[200005];
const long long mod=1000000007;
long long dp[5][5];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k=0,n,q,m;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(v[i]=='?')
            ++k;
    }
    long long p3=1,p1=1,p2=1,pt=1;
    for(i=1;i<=k-3;++i)
    {
        p3=p3*3LL%mod;
    }
    for(i=1;i<=k-2;++i)
    {
        p2=p2*3LL%mod;
    }
    for(i=1;i<=k-1;++i)
    {
        p1=p1*3LL%mod;
    }
    for(i=1;i<=k;++i)
    {
        pt=pt*3LL%mod;
    }
    long long ans=0;
    for(i=1;i<=n;++i)
    {
        if(v[i]=='a')
            dp[1][0]=(dp[1][0]+1)%mod;
        if(v[i]=='b')
        {
            dp[2][0]=(dp[2][0]+dp[1][0])%mod;
            dp[2][1]=(dp[2][1]+dp[1][1])%mod;
        }
        if(v[i]=='c')
        {
            ans=(ans+dp[2][0]*1LL*pt%mod)%mod;
            ans=(ans+dp[2][1]*1LL*p1%mod)%mod;
            ans=(ans+dp[2][2]*1LL*p2%mod)%mod;
        }
        if(v[i]=='?')
        {
            ans=(ans+dp[2][0]*1LL*p1%mod)%mod;
            ans=(ans+dp[2][1]*1LL*p2%mod)%mod;
            ans=(ans+dp[2][2]*1LL*p3%mod)%mod;
            dp[2][1]=(dp[2][1]+dp[1][0])%mod;
            dp[2][2]=(dp[2][2]+dp[1][1])%mod;
            dp[1][1]=(dp[1][1]+1)%mod;
        }
    }
    cout<<ans;
    return 0;
}