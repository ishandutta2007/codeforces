#include <bits/stdc++.h>
using namespace std;

const int Maxn = 4004;
const int Inf = 1000000007;

int T;
int n, m, k;
int a[Maxn];
int dp[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = Inf;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i <= m - 1; i++) {
            int j = m - 1 - i;
            int best = max(a[i], a[n - 1 - j]);
            dp[i][j] = min(dp[i][j], best);
        }
        int res = 0;
        for (int i = n; i >= 0; i--)
            for (int j = n; j >= 0; j--) if (dp[i][j] < Inf) {
                if (i + j <= k) res = max(res, dp[i][j]);
                if (i > 0) dp[i - 1][j] = min(dp[i - 1][j], dp[i][j]);
                if (j > 0) dp[i][j - 1] = min(dp[i][j - 1], dp[i][j]);
            }
        printf("%d\n", res);
    }
    return 0;
}