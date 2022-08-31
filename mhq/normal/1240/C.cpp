#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5 * (int)1e5 + 100;
int n, k;
vector < ll > dp[maxN];
vector < pair < int, ll > > g[maxN];
int out_deg[maxN];
const ll INF = 2e12;
bool cmp(pair < ll, ll >& a, pair < ll, ll >& b) {
    return a.first - a.second > b.first - b.second;
}
void dfs(int v, int p) {
    out_deg[v] = 0;
    vector < pair < ll, ll > > add;
    ll sm = 0;
    for (auto it : g[v]) {
        int to = it.first;
        if (to == p) continue;
        ll w = it.second;
        dfs(to, v);
        out_deg[v]++;
        pair < ll, ll > t = {-INF, -INF};
        for (int c = 0; c <= out_deg[to]; c++) {
            t.second = max(t.second, dp[to][c]);
            if (c + 1 <= k) t.first = max(t.first, dp[to][c] + w);
        }
        sm += t.second;
        add.emplace_back(t);
    }
    out_deg[v] = min(out_deg[v], k);
    dp[v].resize(out_deg[v] + 1, 0);
    sort(add.begin(), add.end(), cmp);
    for (int i = 0; i < min(add.size(), dp[v].size()); i++) {
        dp[v][i] = sm;
        sm += add[i].first - add[i].second;
    }
    if (dp[v].size() > add.size()) dp[v][add.size()] = sm;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        dp[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }
    dfs(1, -1);
    ll best = -INF;
    for (int i = 0; i <= out_deg[1]; i++) best = max(best, dp[1][i]);
    cout << best << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}