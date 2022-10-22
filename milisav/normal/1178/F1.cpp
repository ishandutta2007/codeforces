#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long dp[1000][1000];
int n,m;
int c[1000];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&c[i]);
    }
    for(int i=0;i<=n+1;i++) {
        for(int j=0;j<=i;j++) dp[i][j]=1;
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i+k<=n;i++) {
            int j=i+k;
            int u=i;
            for(int l=i;l<=j;l++){
                if(c[l]<c[u]) {
                    u=l;
                }
            }
            long long rs=dp[u+1][j];
            for(int l=u+1;l<=j;l++) {
                rs=(rs+(dp[l+1][j]*dp[u+1][l])%mod)%mod;
            }
            long long ls=dp[i][u-1];
            for(int l=u-1;l>=i;l--) {
                ls=(ls+(dp[i][l-1]*dp[l][u-1])%mod)%mod;
            }
            dp[i][j]=(ls*rs)%mod;
        }
    }

    printf("%lld",dp[1][n]);
    return 0;
}