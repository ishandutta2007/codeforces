#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;
const int Inf = 1000000000;

int T;
int n, m;
int B[Maxn][Maxn];
ii dp[Maxn][Maxn];

void Update(ii &res, const ii &cand)
{
    res.first = min(res.first, cand.first);
    res.second = max(res.second, cand.second);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                scanf("%d", &B[i][j]);
                dp[i][j] = ii(Inf, -Inf);
            }
        dp[0][0] = ii(B[0][0], B[0][0]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (i + 1 < n)
                    Update(dp[i + 1][j], ii(dp[i][j].first + B[i + 1][j], dp[i][j].second + B[i + 1][j]));
                if (j + 1 < m)
                    Update(dp[i][j + 1], ii(dp[i][j].first + B[i][j + 1], dp[i][j].second + B[i][j + 1]));
            }
        printf("%s\n", dp[n - 1][m - 1].first % 2 == 0 && dp[n - 1][m - 1].first <= 0 && 0 <= dp[n - 1][m - 1].second? "YES": "NO");
    }
    return 0;
}