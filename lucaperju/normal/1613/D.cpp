#include <bits/stdc++.h>

using namespace std;


/*
const long long mod = 998244353;

long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int v[500005];
long long dp[500005];
long long dp1[500005];
const int mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,i,h,k,j,n,s=0,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            ++v[i];
            dp[i]=dp1[i]=0;
        }
        dp[n+1]=dp1[n+1]=0;
        dp[n+2]=dp1[n+2]=0;
        dp[n+3]=dp1[n+3]=0;
        dp[0]=1;
        s=0;
        for(i=1;i<=n;++i)
        {
            v[i]+=2;
            s=(s+dp1[v[i]])%mod;
            dp1[v[i]]=(dp1[v[i]]+dp1[v[i]])%mod;
            v[i]-=2;
            s=(s+dp[v[i]]+dp[v[i]-1])%mod;
            dp[v[i]]=(dp[v[i]]+dp[v[i]]+dp[v[i]-1])%mod;
            if(v[i]>=2)
            {
                s=(s+dp1[v[i]]+dp[v[i]-2])%mod;
                dp1[v[i]]=(dp1[v[i]]+dp1[v[i]]+dp[v[i]-2])%mod;
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}