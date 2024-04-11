
#include <bits/stdc++.h>

using namespace std;


const long long mod = 1000000007;
long long fct[400005],invfct[400005],inv[400005];
long long put2[400005];
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
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=400000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}

long long dp[405][405];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,m,q,n;
    cin>>n;
    init();
    dp[1][0]=1;
    dp[1][1]=1;
    for(i=2;i<=n;++i)
    {
        dp[i][0]=1;
        for(j=1;j<=n-i+1;++j)
        {
            /// doar |
            for(int k=0;k<=j;++k)
                dp[i][j]=(dp[i][j]+dp[i-1][k]*1LL*dp[i-1][j-k]%mod)%mod;
            /// un --o--
            for(int k=1;k<=j;++k)
                dp[i][j]=(dp[i][j]+dp[i-1][k]*2LL*dp[i-1][j-k+1]%mod*k%mod*(j-k+1)%mod)%mod;
            /// un >o (sau o<)
            for(int k=2;k<=j+1;++k)
                dp[i][j]=(dp[i][j]+dp[i-1][k]*2LL*dp[i-1][j-k+1]%mod*2LL%mod*cmb(k,2)%mod)%mod;
            /// o si |
            for(int k=0;k<=j-1;++k)
                dp[i][j]=(dp[i][j]+dp[i-1][k]*1LL*dp[i-1][j-1-k]%mod)%mod;
            /// --o (sau o--)
            for(int k=1;k<=j;++k)
                dp[i][j]=(dp[i][j]+dp[i-1][k]*2LL*dp[i-1][j-k]%mod*2LL*k%mod)%mod;
        }
    }
    cout<<dp[n][1]%mod;
    return 0;
}