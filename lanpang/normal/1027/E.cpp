#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
double pi = acos(-1.0);
const int maxn = 5e2+38;
const int mod = 998244353;

int n,k;
ll ksm(ll a,int n) //
{
    ll ans=1;
    for(; n; n>>=1,a=a*a%mod)
        if(n&1) ans=ans*a%mod;
    return ans;
}
ll C[maxn];
ll dp[maxn][maxn][2];
int main() {
    scanf("%d%d",&n,&k);
    C[1] = 2;
    for(int t=2;t<=n;t++){
        memset(dp,0,sizeof(dp));
        dp[1][1][0] = 2;
        for(int i=1;i<n;i++){
            for(int j=1;j<t;j++)if(j<=i){
                dp[i+1][j+1][(j+1)==t?1:0] += dp[i][j][0];
                dp[i+1][1][0] += dp[i][j][0];
            }
            for(int j=1;j<=t;j++)if(j<=i){
                if(j<t){
                    dp[i+1][j+1][1] += dp[i][j][1];
                }
                dp[i+1][1][1] += dp[i][j][1];
            }
            for(int j=1;j<=i+1;j++)
                dp[i+1][j][0]%=mod,dp[i+1][j][1]%=mod;
        }
        
        for(int j=1;j<=t;j++)
            C[t] = (C[t]+dp[n][j][1])%mod;
        //printf("%d %lld\n",t,C[t]);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(i>=k) break;
        for(int j=1;j<=min(k/i,n);j++)
            if(j*i!=k)
            ans = (ans+C[j]*C[i]%mod)%mod;
    }
    ans = (ans*ksm(2,mod-2))%mod;
    printf("%lld",ans);
}