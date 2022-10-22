#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int n;
int c[Maxn];
int dp[Maxn][Maxn][2];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        dp[i][i][0] = dp[i][i][1] = 0;
    }
    for (int l = 1; l <= n; l++)
        for (int i = 0, j = l; j < n; i++, j++) {
            dp[i][j][0] = min(dp[i + 1][j][0] + (c[i] != c[i + 1]),
                              dp[i + 1][j][1] + (c[i] != c[j]));
            dp[i][j][1] = min(dp[i][j - 1][0] + (c[j] != c[i]),
                              dp[i][j - 1][1] + (c[j] != c[j - 1]));
        }
    printf("%d\n", min(dp[0][n - 1][0], dp[0][n - 1][1]));
    return 0;
}