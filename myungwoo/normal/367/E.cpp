#include <stdio.h>
#include <memory.h>

#define MOD 1000000007LL
int n, m, x;
__int64 dp[2][400][400][2];
__int64 fact[100010];

int main()
{
    scanf ("%d%d%d", &n, &m, &x);

    int i, j, k, f=0, p=1;
    __int64 ans=0;

    fact[0]=1;
    for (i=1; i<=100000; i++) fact[i] = (fact[i-1]*i)%MOD;

    if (n>=m) {
        for (j=1; j<=m; j++) for (k=j; k<=m; k++) {
            if (j==x) dp[f][j][k][1] = 1;
            else dp[f][j][k][0] = 1;
        }
        for (j=1; j<=m; j++) {
            for (k=1; k<=m; k++) {
                dp[f][j][k][0] = (dp[f][j][k][0] + dp[f][j-1][k][0] + dp[f][j][k-1][0] - dp[f][j-1][k-1][0] + MOD)%MOD;
                dp[f][j][k][1] = (dp[f][j][k][1] + dp[f][j-1][k][1] + dp[f][j][k-1][1] - dp[f][j-1][k-1][1] + MOD)%MOD;
            }
        }
        f^=1, p^=1;

        for (i=1; i<n; i++) {
            for (j=0;j<=m;j++) for (k=0;k<=m;k++) dp[f][j][k][0] = dp[f][j][k][1] = 0;
            for (j=1; j<=m; j++) {
                for (k=j; k<=m; k++) {
                    if (j==x)
                        dp[f][j][k][1] = dp[p][j-1][k-1][0];
                    else {
                        dp[f][j][k][0] = dp[p][j-1][k-1][0];
                        dp[f][j][k][1] = dp[p][j-1][k-1][1];
                    }
                }
            }
            for (j=1; j<=m; j++) {
                for (k=1; k<=m; k++) {
                    dp[f][j][k][0] = (dp[f][j][k][0] + dp[f][j-1][k][0] + dp[f][j][k-1][0] - dp[f][j-1][k-1][0] + MOD)%MOD;
                    dp[f][j][k][1] = (dp[f][j][k][1] + dp[f][j-1][k][1] + dp[f][j][k-1][1] - dp[f][j-1][k-1][1] + MOD)%MOD;
                }
            }

            f^=1, p^=1;
        }
        ans=dp[p][m][m][1];
    }

    else {
        dp[f][0][0][0] = 1;
        f^=1, p^=1;

        for (i=1; i<=m; i++) {
            for (j=0;j<=n;j++) for (k=0;k<=n;k++) dp[f][j][k][0] = dp[f][j][k][1] = 0;
            for (j=0; j<=n; j++) {
                for (k=0; k<=j; k++) {
                    dp[f][j][k][0] = (dp[f][j][k][0] + dp[p][j][k][0]) % MOD;
                    dp[f][j][k][1] = (dp[f][j][k][1] + dp[p][j][k][1]) % MOD;
                    if (j+1 <= n) {
                        dp[f][j+1][k][0] = (dp[f][j+1][k][0] + dp[p][j][k][0]) % MOD;
                        dp[f][j+1][k][1] = (dp[f][j+1][k][1] + dp[p][j][k][1]) % MOD;
                        if (i==x)
                            dp[f][j+1][k][1] = (dp[f][j+1][k][1] + dp[p][j][k][0]) % MOD;
                        dp[f][j+1][k+1][0] = (dp[f][j+1][k+1][0] + dp[p][j][k][0]) % MOD;
                        dp[f][j+1][k+1][1] = (dp[f][j+1][k+1][1] + dp[p][j][k][1]) % MOD;
                        if (i==x)
                            dp[f][j+1][k+1][1] = (dp[f][j+1][k+1][1] + dp[p][j][k][0]) % MOD;
                    }
                    if (k+1 <= j) {
                        dp[f][j][k+1][0] = (dp[f][j][k+1][0] + dp[p][j][k][0]) % MOD;
                        dp[f][j][k+1][1] = (dp[f][j][k+1][1] + dp[p][j][k][1]) % MOD;
                    }
                }
            }

            f^=1, p^=1;
        }

        ans = dp[p][n][n][1];
    }

    printf ("%I64d\n", (ans*fact[n])%MOD);

    return 0;
}