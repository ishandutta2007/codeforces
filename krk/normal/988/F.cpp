#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;
const int Inf = 1000000000;

int a, n, m;
int dp[Maxn][Maxn];
bool rain[Maxn];
int w[Maxn];
ii small[Maxn];

int main()
{
    scanf("%d %d %d", &a, &n, &m);
    fill((int*)dp, (int*)dp + Maxn * Maxn, Inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int l, r; scanf("%d %d", &l, &r);
        for (int j = l; j < r; j++)
            rain[j] = true;
    }
    fill(small, small + Maxn, ii(Inf, 0));
    w[0] = Inf;
    for (int i = 1; i <= m; i++) {
        int a; scanf("%d %d", &a, &w[i]);
        small[a] = min(small[a], ii(w[i], i));
    }
    for (int i = 0; i < a; i++)
        for (int j = 0; j <= m; j++) if (dp[i][j] < Inf)
            if (rain[i]) {
                int nj = small[i].first < w[j]? small[i].second: j;
                dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + w[nj]);
            } else {
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][j]);
                int nj = small[i].first < w[j]? small[i].second: j;
                dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + w[nj]);
            }
    int res = Inf;
    for (int j = 0; j <= m; j++)
        res = min(res, dp[a][j]);
    printf("%d\n", res >= Inf? -1: res);
    return 0;
}