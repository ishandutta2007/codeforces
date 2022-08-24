#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
vector<int> g[maxN];
int n;
ll l[maxN], r[maxN];
ll dp[maxN][2];
void dfs(int v, int p) {
    dp[v][0] = dp[v][1] = 0;
    ll val[2] = {l[v], r[v]};
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        for (int x = 0; x < 2; x++) {
            dp[v][x] += max(dp[to][0] + abs(l[to] - val[x]), dp[to][1] + abs(r[to] - val[x]));
        }
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}