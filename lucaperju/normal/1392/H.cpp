#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long fct[4000003],invfct[4000003],inv[4000003];
long long dp[2000003];
long long cmb (long long n, long long k)
{
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
long long invcmb (long long n, long long k)
{
    return invfct[n]*1LL*fct[k]%mod*1LL*fct[n-k]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int q,m,i,j,l,r,t,n;
    cin>>n>>m;
    inv[1]=1;
    for(i=2;i<=n+m+1;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod;
    fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(i=2;i<=n+m+1;++i)
    {
        fct[i]=i*1LL*fct[i-1]%mod;
        invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
    }
    dp[0]=0;
    for(i=1;i<=n;++i)
    {
        /**
        dp[i] =>  a=i, b=n-i, c=m
        dp[i] = c / (a + c) * (1 + b / (a + c + 1) + dp[i])
              + a / (a + c) * (1 + b / (a + c + 1) + X)

        X = dp[i-1] + ( b / (a + c + 1) - (b + 1) / (a + c) ) * ( 1 / cmb(a+c-1,a-1) ) * cmb(a+c,a-1)
        =>
        dp[i] = ( 1 + b / (a + c + 1) ) + a * X / (a + c) + c / (a + c) * dp[i]   | * (a + c)
        (a + c) * dp[i] = (a + c) * (1 + b / (a + c + 1) ) + a * X + c * dp[i]

        a * dp[i] = (a + c) * (1 + b / (a + c + 1) ) + a * X
        */
        long long a=i, b=n-i, c=m;
        long long X;
        if(i==1)
            X = (1 + b *1LL* inv[a+c+1]%mod)%mod;
        else
            X = dp[i-1] + (b *1LL* inv[a+c+1]%mod - (b+1) *1LL* inv[a+c]%mod + mod)%mod *1LL* invcmb(a+c-1, a-1)%mod *1LL* cmb(a+c,a-1)%mod;
        dp[i]=( (a+c) *1LL* (1 + b *1LL* inv[a+c+1]%mod)%mod + a *1LL* X%mod)%mod*1LL*inv[a]%mod;
    }
    cout<<dp[n];
    return 0;
}