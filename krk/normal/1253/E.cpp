#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 85;
const int Inf = 1000000000;

int n, m;
ii p[Maxm];
int dp[Maxn][Maxm][2];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &p[i].first, &p[i].second);
    sort(p, p + n);
    fill((int*)dp, (int*)dp + Maxn * Maxm * 2, Inf);
    dp[1][0][0] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 2; k++) if (dp[i][j][k] < Inf) {
                // other
                dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i][j][k]);
                // same
                if (p[j].first - p[j].second <= i && i <= p[j].first + p[j].second) {
                    int ni = min(m + 1, p[j].first + p[j].second + 1);
                    dp[ni][j][1] = min(dp[ni][j][1], dp[i][j][k]);
                } else if (i < p[j].first - p[j].second) {
                    int add = p[j].first - p[j].second - i;
                    int ni = min(m + 1, p[j].first + p[j].second + add + 1);
                    dp[ni][j][1] = min(dp[ni][j][1], dp[i][j][k] + add);
                } else if (k == 0) {
                    int add = i - (p[j].first + p[j].second);
                    dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][k] + add);
                } else dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][k] + 1);
            }
    int res = Inf;
    for (int j = 0; j <= n; j++)
        for (int k = 0; k < 2; k++)
            res = min(res, dp[m + 1][j][k]);
    printf("%d\n", res);
    return 0;
}