#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, m;
const int maxN = 5 * (int)1e5 + 10;
const int INF = (int)1e9 + 100;
int p[maxN];
int get(int i) {
    if (p[i] == i) return i;
    p[i] = get(p[i]);
    return p[i];
}
bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (rand() & 1) swap(a, b);
    p[b] = a;
    return true;
}
vector < pair < int, bool > > g[maxN];
bool in_tree[maxN];
int a[maxN], b[maxN], w[maxN];
const int LOG = 20;
int up[LOG][maxN];
int mn[LOG][maxN];
int h[maxN];
void dfs(int v, int p) {
    up[0][v] = p;
    for (auto t : g[v]) {
        if (t.first == p) continue;
        h[t.first] = h[v] + 1;
        dfs(t.first, v);
    }
}
int lca(int a, int b) {
    if (h[a] < h[b]) swap(a, b);
    for (int i = LOG - 1; i >= 0; i--) {
        if (h[a] - (1 << i) >= h[b]) a = up[i][a];
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }
    if (a != b) return up[0][a];
    else return a;
}
void query(int from, int to, int we) {
    for (int i = LOG - 1; i >= 0; i--) {
        if (h[from] - (1 << i) >= h[to]) {
            mn[i][from] = min(mn[i][from], we);
            from = up[i][from];
        }
    }
}
bool unbound = false;
ll ans = 0;
void new_dfs(int v, int p) {
    for (auto t : g[v]) {
        if (t.first == p) {
            if (t.second == false) continue;
            if (mn[0][v] == INF) {
                unbound = true;
            }
            else {
                ans += mn[0][v];
            }
        }
        else new_dfs(t.first, v);
    }
}
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
        g[a].emplace_back(make_pair(b, true));
        g[b].emplace_back(make_pair(a, true));
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> w[i];
        if (unite(a[i], b[i])) {
            in_tree[i] = true;
            g[a[i]].emplace_back(make_pair(b[i], false));
            g[b[i]].emplace_back(make_pair(a[i], false));
        }
    }
    dfs(1, 0);
    for (int i = 0; i + 1 < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            up[i + 1][j] = up[i][up[i][j]];
            mn[i][j] = INF;
            mn[i + 1][j] = INF;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (in_tree[i]) continue;
        int lc = lca(a[i], b[i]);
        if (lc != a[i]) query(a[i], lc, w[i]);
        if (lc != b[i]) query(b[i], lc, w[i]);
    }
    for (int i = LOG - 1; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            mn[i - 1][j] = min(mn[i - 1][j], mn[i][j]);
            mn[i - 1][up[i - 1][j]] = min(mn[i - 1][up[i - 1][j]], mn[i][j]);
        }
    }
    new_dfs(1, 0);
    if (unbound) cout << -1;
    else cout << ans;
    return 0;
}