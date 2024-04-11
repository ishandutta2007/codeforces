#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2 * (int)1e5 + 100;
int deg[maxN];
vector < int > g[maxN];
ll x, y;
int dp[maxN][3];
const int INF = (int)1e9;
void dfs(int v, int p) {
    for (int i = 0; i < 3; i++) dp[v][i] = -INF;
    dp[v][0] = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        int ndp[3];
        for (int i = 0; i < 3; i++) ndp[i] = -INF;
        for (int was = 0; was < 3; was++) {
            for (int he = 0; he < 3; he++) {
                if (was < 2 && he < 2) {
                    ndp[was + 1] = max(ndp[was + 1], dp[v][was] + dp[to][he] + 1);
                }
                ndp[was] = max(ndp[was], dp[v][was] + dp[to][he]);
            }
        }
        for (int i = 0; i < 3; i++) dp[v][i] = ndp[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    if (x > y) {
        //
        int mx = 0;
        for (int i = 1; i <= n; i++) mx = max(mx, deg[i]);
        int at_least = 0;
        if (mx == n - 1) at_least++;
        cout << y * (n - 1 - at_least) + x * at_least;
        return 0;
    }
    dfs(1, -1);
    int best = 0;
    for (int i = 0; i < 3; i++) best = max(best, dp[1][i]);
    cout << x * best + y * (n - 1 - best);
    return 0;
}