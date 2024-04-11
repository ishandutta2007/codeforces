#include <bits/stdc++.h>
using namespace std;
long long dp[1000003];
const int mod=998244353;
long long lgput (long long val, long long exp)
{
    long long rz=1;
    while(exp)
    {
        if(exp&1)
        {
            exp^=1;
            rz=rz*1LL*val%mod;
        }
        else
        {
            exp>>=1;
            val=val*1LL*val%mod;
        }
    }
    return rz;
}
int main()
{
    long long n,i,j;
    cin>>n;
    if(n==1)
    {
        cout<<5;
        return 0;
    }
    dp[1]=1;
    dp[2]=3;
    dp[3]=10;
    for(i=4;i<=n;++i)
        dp[i]=(1+dp[i-1]+(dp[i-1]*1LL*(dp[i-1]+1)/2LL)%mod)%mod;
    /**
    -->O<--
       ^
       |
    */
    long long ans1=0,ans2=0;
    ans1=dp[n]*1LL*(dp[n]-1)%mod*1LL*(dp[n]-2)%mod*1LL*lgput(6,mod-2)%mod;
    ans1=(ans1+dp[n]*1LL*(dp[n]-1)%mod)%mod;
    ans1=(ans1+dp[n])%mod;
    --n;
    ans2=dp[n]*1LL*(dp[n]-1)%mod*1LL*(dp[n]-2)%mod*1LL*lgput(6,mod-2)%mod;
    ans2=(ans2+dp[n]*1LL*(dp[n]-1)%mod)%mod;
    ans2=(ans2+dp[n])%mod;
    ++n;
    long long ans=(ans1-ans2+mod)%mod;
    ans=ans*2LL%mod;
    /**
    -->O<--
    */
    ans=(ans + dp[n] +   (dp[n]  *1LL*(dp[n]  -1LL) / 2LL)%mod)%mod;
    ans=(ans - dp[n-1] - (dp[n-1]*1LL*(dp[n-1]-1LL) / 2LL)%mod+mod+mod)%mod;
    /**
    <--O-->
       ^
       |
    */
    ans=(ans + dp[n] +   (dp[n]  *1LL*(dp[n]  -1LL) / 2LL)%mod)%mod;
    ans=(ans - dp[n-1] - (dp[n-1]*1LL*(dp[n-1]-1LL) / 2LL)%mod+mod+mod)%mod;
    long long ansc;
    for(i=1;i<n;++i)
    {
        ansc=(       dp[n-i] +   (dp[n-i]  *1LL*(dp[n-i]  -1LL) / 2LL)%mod)%mod;
        ansc=(ansc - dp[n-i-1] - (dp[n-i-1]*1LL*(dp[n-i-1]-1LL) / 2LL)%mod+mod+mod)%mod;
        ansc=ansc*1LL*(dp[i]-dp[i-1]+mod)%mod;
        ans=(ans+ansc)%mod;
    }
    ans=(ans+(dp[n]-dp[n-1]+mod)%mod)%mod;
    cout<<ans;
    return 0;
}