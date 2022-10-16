#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
    {
        if(exp&1)
        {
            exp^=1;
            rz=rz*1LL*a%mod;
        }
        else
        {
            exp>>=1;
            a=a*1LL*a%mod;
        }
    }
    return rz;
}
long long fct[200003];
long long invfct[200003];
long long cmb (long long n, long long k)
{
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
long long dp[100003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,j,n,t,m,p;
    fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(i=2;i<=200000;++i)
        fct[i]=i*1LL*fct[i-1]%mod;
    invfct[200000]=lgput(fct[200000],mod-2);
    for(i=200000-1;i>=2;--i)
        invfct[i]=invfct[i+1]*1LL*(i+1)%mod;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        long long rz=0;
        dp[1]=fct[n];
        for(i=2;i<=n;++i)
        {
            long long pz=1;
            pz+=(i-1)*1LL*m;
            if(pz>n)
                dp[i]=0;
            else
                dp[i]=cmb(n-pz+i,i)*1LL*fct[i]%mod*1LL*fct[n-i]%mod;
            rz=(rz+(dp[i-1]-dp[i]+mod)%mod*1LL*i%mod)%mod;
        }
        cout<<rz*1LL*invfct[n]%mod<<'\n';
    }
    return 0;
}