#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;
const int Inf = 1000000000;

int n;
int a[Maxn];
int dp[Maxn][Maxn][Maxn];
int dp2[Maxn][Maxn];

int main()
{
    fill((int*)dp, (int*)dp + Maxn * Maxn * Maxn, -Inf);
    fill((int*)dp2, (int*)dp2 + Maxn * Maxn, -Inf);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    dp[0][1][0] = a[0];
    dp[0][0][1] = a[1];
    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j <= i + 1; j++) {
            for (int k = 0; k < n; k++) if (dp[i][j][k] >= 0) {
                // same
                dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + a[k]);
                // give up
                if (k <= i + 1)
                    dp2[i + 1][j + 1] = max(dp2[i + 1][j + 1], dp[i][j][k]); 
                else dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k]);
                // take new
                int lef = max(i + 1, k + 1);
                int rig = min(n - 1, i + 1 + j + 1);
                for (int l = lef, nj = j + 1 - (lef - i - 1); l <= rig; l++, nj--)
                    dp[i + 1][nj][l] = max(dp[i + 1][nj][l], dp[i][j][k] + a[l]);
            }
            if (dp2[i][j] < 0) continue;
            dp2[i + 1][j + 1] = max(dp2[i + 1][j + 1], dp2[i][j]);
            for (int l = i + 1, nj = j + 1; l < n && nj >= 0; l++, nj--)
                dp[i + 1][nj][l] = max(dp[i + 1][nj][l], dp2[i][j] + a[l]);
        }
    int res = -Inf;
    for (int j = 0; j <= n; j++) {
        res = max(res, dp2[n - 1][j]);
        for (int k = 0; k < n; k++)
            res = max(res, dp[n - 1][j][k]);
    }
    cout << res << endl;
    return 0;
}