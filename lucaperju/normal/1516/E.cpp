#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(int i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}

long long dp[410][210];
long long ans[203];
/// dp[#of poz][#of cycles]
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,s,n,k;
    cin>>n>>k;
    init();
    dp[0][0]=1;
    for(int i=2;i<=409;++i)
        for(int j=1;j+j<=i;++j)
            for(int szc=1;szc<i;++szc)
                dp[i][j]=(dp[i][j] + dp[i-szc-1][j-1]*1LL*cmb(i-1,szc)%mod*1LL*fct[szc]%mod)%mod;
    for(int i=0;i<=min(409LL,n);++i)
        for(int j=0;j+j<=i;++j)
        {
            long long rzc=dp[i][j];
            for(int kc=n;kc>=n-i+1;--kc)
                rzc=rzc*1LL*kc%mod;
            rzc=rzc*1LL*invfct[i]%mod;
            for(int kc=i-j;kc<=k;kc+=2)
                ans[kc]=(ans[kc]+rzc)%mod;
        }
    for(int i=1;i<=k;++i)
        cout<<ans[i]<<' ';
    return 0;
}