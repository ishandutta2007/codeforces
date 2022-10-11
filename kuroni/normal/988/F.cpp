#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const long long INF = 1E12 + 7;

int a, n, m, l, r, p[N], mi[N];
long long dp[N][N];
bool vis[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        for (int j = l; j < r; j++) {
            vis[j] = true;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> l >> p[i];
        if (mi[l] == 0 || p[mi[l]] > p[i]) {
            mi[l] = i;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= m; j++) {
            // not-pick
            if (!(j == 0 && vis[i])) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + p[j]);
            }
            // pick
            if (mi[i] != 0) {
                dp[i + 1][mi[i]] = min(dp[i + 1][mi[i]], dp[i][j] + p[mi[i]]);
            }
            // remove
            if (!vis[i]) {
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][j]);
            }
        }
    }
    long long ans = *min_element(dp[a], dp[a] + m + 1);
    if (ans == INF) {
        cout << -1;
    } else {
        cout << ans << '\n';
    }
}