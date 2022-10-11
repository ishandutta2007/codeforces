#include <bits/stdc++.h>
using namespace std;

const int M = 16, N = 1E4, INF = 1E9 + 7;

int n, m, ans = 0, dp[M][M][1 << M], a[M][N], crs[M][M], adj[M][M];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    if (m == 1) {
        int ans = INF;
        for (int j = 1; j < n; j++) {
            ans = min(ans, abs(a[0][j] - a[0][j - 1]));
        }
        return cout << ans, 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            adj[i][j] = crs[i][j] = INF;
            for (int k = 0; k < n; k++) {
                adj[i][j] = min(adj[i][j], abs(a[i][k] - a[j][k]));
                if (k > 0) {
                    crs[i][j] = min(crs[i][j], abs(a[i][k - 1] - a[j][k]));
                }
            }
        }
    }
    for (int msk = 0; msk < (1 << m); msk++) {
        for (int st = 0; st < m; st++) {
            if (msk >> st & 1) {
                for (int i = 0; i < m; i++) {
                    if (msk >> i & 1) {
                        for (int lst = 0; lst < m; lst++) {
                            if (lst != i && (msk >> lst & 1)) {
                                int cur = min(dp[st][lst][msk ^ (1 << i)], adj[lst][i]);
                                if (msk == (1 << m) - 1) {
                                    cur = min(cur, crs[i][st]);
                                }
                                dp[st][i][msk] = max(dp[st][i][msk], cur);
                            }
                        }
                        if (msk == (1 << st)) {
                            dp[st][i][msk] = INF;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dp[i][j][(1 << m) - 1]);
        }
    }
    cout << ans;
}