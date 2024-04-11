#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
vector < int > g[maxN];
int a[maxN];
int b[maxN], c[maxN];
int n;
int tin[maxN];
int timer = 0;
int pref_min[maxN];
const int LOG = 20;
int h[maxN];
int up[maxN][LOG];
void dfs(int v, int p) {
    tin[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        h[to] = h[v] + 1;
        up[to][0] = v;
        pref_min[to] = min(a[to], pref_min[v]);
        dfs(to, v);
    }
}
int lca(int x, int y) {
    assert(x != y);
    if (h[x] < h[y]) swap(x, y);
    for (int i = LOG - 1; i >= 0; i--) {
        if ((h[x]) - (1 << i) >= h[y]) x = up[x][i];
    }
    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[x][i] != up[y][i]) {
            x = up[x][i];
            y = up[y][i];
        }
    }
    return up[x][0];
}
pair < ll, pair < int, int > > proc(int v, int p) {
    pair < int, int > t = make_pair(0, 0);
    if (b[v] != c[v]) {
        if (b[v] == 0) t.first++;
        else t.second++;
    }
    ll ans = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        auto c = proc(to, v);
        t.first += c.second.first;
        t.second += c.second.second;
        ans += c.first;
    }
    ans += 1LL * min(t.first, t.second) * pref_min[v];
    int d = min(t.first, t.second);
    t.first -= d;
    t.second -= d;
    return make_pair(ans, t);

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    pref_min[1] = a[1];
    dfs(1, -1);
    for (int i = 0; i + 1 < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i + 1] = up[up[j][i]][i];
        }
    }
    vector < pair < int, int > > all[2];
    for (int i = 1; i <= n; i++) {
        if (b[i] != c[i]) {
            all[b[i]].emplace_back(tin[i], i);
        }
    }
    ll ans = 0;
    if (all[0].size() != all[1].size()) {
        cout << -1;
        return 0;
    }
    else {
        auto pit = proc(1, -1);
        cout << 2 * proc(1, -1).first;
    }
    /*else {
        for (int x = 0; x < 2; x++) {
            sort(all[x].begin(), all[x].end());
        }
        for (int c = 0; c < all[0].size(); c++) {
            int p1 = all[0][c].second;
            int p2 = all[1][c].second;
            ans += pref_min[lca(p1, p2)];
        }
    }
    cout << ans * 2;*/
    return 0;
}