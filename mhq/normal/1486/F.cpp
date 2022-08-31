#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e5 + 10;
int n, m;
const int LOG = 20;
int up[LOG][maxN];
vector<int> g[maxN];
int h[maxN];
void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) continue;
        up[0][to] = v;
        h[to] = h[v] + 1;
        dfs(to, v);
    }
}
vector<pair<pair<int,int>,int>> pairs[maxN];
int jump(int v, int k) {
    if (k < 0) return v;
    for (int i = LOG - 1; i >= 0; i--) {
        if ((k >> i) & 1) v = up[i][v];
    }
    return v;
}
int lca(int x, int y) {
    if (h[x] < h[y]) swap(x, y);
    x = jump(x, h[x] - h[y]);
    if (x == y) return x;
    for (int k = LOG - 1; k >= 0; k--) {
        if (up[k][x] != up[k][y]) {
            x = up[k][x];
            y = up[k][y];
        }
    }
    return up[0][x];
}
int a[maxN], b[maxN];
int add[LOG][maxN];
void do_add(int v, int k) {
    if (k < 0) return;
    for (int i = LOG - 1; i >= 0; i--) {
        if ((k >> i) & 1) {
            add[i][v]++;
            v = up[i][v];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, -1);
    for (int k = 0; k + 1 < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            up[k + 1][i] = up[k][up[k][i]];
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        int lc = lca(a[i], b[i]);
        int v1 = jump(a[i], h[a[i]] - h[lc] - 1);
        int v2 = jump(b[i], h[b[i]] - h[lc] - 1);
        pairs[lc].emplace_back(make_pair(v1, v2), 1);
        if (a[i] != lc) {
            pairs[a[i]].emplace_back(make_pair(a[i], up[0][a[i]]), 1);
            do_add(a[i], h[a[i]] - h[lc] - 1);
        }
        if (b[i] != lc) {
            pairs[b[i]].emplace_back(make_pair(b[i], up[0][b[i]]), 1);
            do_add(b[i], h[b[i]] - h[lc] - 1);
        }
    }
    for (int i = LOG - 1; i > 0; i--) {
        for (int x = 1; x <= n; x++) {
            add[i - 1][x] += add[i][x];
            add[i - 1][up[i - 1][x]] += add[i][x];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (add[0][i] > 0) {
            assert(h[i] >= 2);
            int par = up[0][i];
            int parpar = up[0][par];
            pairs[par].emplace_back(make_pair(i, parpar), add[0][i]);
        }
    }
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        map<int,int> mp;
        map<pair<int,int>, int> pp;
        int sz = 0;
        for (auto it : pairs[i]) {
            if (it.first.first > it.first.second) swap(it.first.first, it.first.second);
            sz += it.second;
            if (it.first.first != i) {
                mp[it.first.first] += it.second;
            }
            if (it.first.second != i) {
                mp[it.first.second] += it.second;
            }
            if (it.first.first != i && it.first.second != i) {
                pp[make_pair(it.first.first, it.first.second)] += it.second;
            }
        }
        tot += (1LL * sz * (sz - 1)) / 2;
        for (auto& it : mp) {
            tot -= (1LL * it.second * (it.second - 1)) / 2;
        }
        for (auto& it : pp) {
            tot += (1LL * it.second * (it.second - 1)) / 2;
        }
//        cout << " AFTER " << tot << endl;
    }
    cout << tot;
    return 0;
}