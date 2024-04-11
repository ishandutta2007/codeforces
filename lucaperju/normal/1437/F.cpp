#include <bits/stdc++.h>

using namespace std;

//*
const long long mod = 998244353;
//*
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
//*/
int dp[5005];
int v[5005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,n,r,m,s,k,j,q;
    init();
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    if(v[n-1]*2>v[n])
    {
        cout<<0;
        return 0;
    }
    dp[n]=1;
    j=n-1;
    for(i=n-1;i>=1;--i)
    {
        while(j>=1 && v[j]*2>v[i])
            --j;
        int nrc=n-i;
        /// not taking v[i]:
        dp[i]=(dp[i]+dp[i+1]*1LL*nrc%mod)%mod;
        /// taking v[i]:
        if(j+1<i)
            dp[j+1]=(dp[j+1]+dp[i+1]*1LL*fct[nrc-1+(i-j-1)]%mod*1LL*invfct[nrc-1]%mod)%mod;
        else
            dp[i]=(dp[i]+dp[i+1])%mod;
    }
    cout<<dp[1];
    return 0;
}