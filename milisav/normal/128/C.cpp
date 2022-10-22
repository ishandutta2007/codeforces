#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int n,m,k;
long long dp[maxn][maxn];
long long pref[maxn][maxn];
const long long mod=1e9+7;
int main() {
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<maxn;i++) {
        dp[i][0]=1;
        pref[i][0]=i;
    }
    for(int j=1;j<=k;j++) {
        for(int i=2;i<maxn;i++) {
            dp[i][j]=(dp[i-1][j]+pref[i-2][j-1])%mod;
            pref[i][j]=(pref[i-1][j]+dp[i][j])%mod;
        }
    }
    printf("%lld",(dp[n][k]*dp[m][k])%mod);
    return 0;
}