#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3010;
int bal[maxN];
vector < int > g[maxN];
int n, m;
const ll INF = 1e18;
pair < int, ll > dp[maxN][maxN];
int sz[maxN];
pair < int, ll > ndp[maxN];
void dfs(int u, int p) {
    for (int i = 0; i <= m; i++) dp[u][i] = make_pair(-1000000, -INF);
    dp[u][1] = make_pair(0, bal[u]);
    sz[u] = 1;
    for (int to : g[u]) {
        if (to == p) continue;
        dfs(to, u);
        for (int c = 1; c <= sz[u] + sz[to]; c++) {
            ndp[c] = make_pair(-1000000, -INF);
        }
        for (int we = 1; we <= sz[u]; we++) {
            if (dp[u][we].first < 0) continue;
            for (int he = 1; he <= sz[to]; he++) {
                if (dp[to][he].first < 0) continue;
                ndp[we + he] = max(ndp[we + he], {dp[u][we].first + dp[to][he].first + (dp[to][he].second > 0), dp[u][we].second});
                ndp[we + he - 1] = max(ndp[we + he - 1], {dp[u][we].first + dp[to][he].first, dp[u][we].second + dp[to][he].second});
            }
        }
        for (int c = 1; c <= sz[u] + sz[to]; c++) dp[u][c] = ndp[c];
        sz[u] += sz[to];
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) {
        cin >> bal[i];
    }
    for (int i = 1; i <= n; i++) {
        int x = 0;
        cin >> x;
        bal[i] -= x;
        bal[i] = -bal[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << dp[1][m].first + (dp[1][m].second > 0) << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst = 2;
    cin >> tst;
    while (tst--) solve();
    return 0;
}