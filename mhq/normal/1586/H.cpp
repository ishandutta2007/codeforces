#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n, q;
const int maxN = 2e5 + 10;
int e[maxN];
vector<pair<int,int>> g[maxN];
const int LOG = 18;
int h[maxN];
int mx[LOG][maxN];
int up[LOG][maxN];
int a[maxN], b[maxN], c[maxN], t[maxN];
void dfs(int v, int p) {
    for (auto& it : g[v]) {
        if (it.first == p) continue;
        up[0][it.first] = v;
        h[it.first] = h[v] + 1;
        mx[0][it.first] = t[it.second];
        dfs(it.first, v);
    }
}
int getUp(int u, int lca) {
    int dif = h[u] - h[lca];
    int tot = 0;
    for (int k = LOG - 1; k >= 0; k--) {
        if (dif & (1 << k)) {
            tot = max(tot, mx[k][u]);
            u = up[k][u];
        }
    }
    return tot;
}
int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int k = LOG - 1; k >= 0; k--) {
        if (h[u] - (1 << k) >= h[v]) {
            u = up[k][u];
        }
    }
    if (u == v) return u;
    for (int k = LOG - 1; k >= 0; k--) {
        if (up[k][u] != up[k][v]) {
            u = up[k][u];
            v = up[k][v];
        }
    }
    return up[0][u];
}
int getMax(int u, int v) {
    int lc = lca(u, v);
    return max(getUp(u, lc), getUp(v, lc));
}
int cur_mx[maxN];
int cur_ans[maxN];
int who[maxN];
int v[maxN], x[maxN];
int p[maxN];
int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}
int val_max[maxN], val_t[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> e[i];
    }
    vector<pair<int,int>> all;
    for (int i = 1; i < n; i++)  {
        cin >> a[i] >> b[i] >> c[i] >> t[i];
        g[a[i]].emplace_back(b[i], i);
        g[b[i]].emplace_back(a[i], i);
        all.emplace_back(c[i], i);
    }
    dfs(1, -1);
    for (int k = 0; k + 1 < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            up[k + 1][i] = up[k][up[k][i]];
            mx[k + 1][i] = max(mx[k][i], mx[k][up[k][i]]);
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> v[i] >> x[i];
        all.emplace_back(v[i], ~i);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (int i = 1; i <= n; i++) {
        cur_mx[i] = e[i];
        cur_ans[i] = 0;
        who[i] = i;
        p[i] = i;
    }
    for (auto& it : all) {
        int id = it.second;
        if (id > 0) {
     //       cout << " EDGE " << a[id] << " " << b[id] << endl;
            int p1 = get(a[id]);
            int p2 = get(b[id]);
            if (cur_mx[p1] < cur_mx[p2]) {
                swap(a[id], b[id]);
                swap(p1, p2);
            }
            if (cur_mx[p1] > cur_mx[p2]) {
                p[p2] = p1;
                continue;
            }
            assert(cur_mx[p1] == cur_mx[p2]);
            cur_ans[p1] = max(cur_ans[p1], cur_ans[p2]);
            cur_ans[p1] = max(cur_ans[p1], t[id]);
            cur_ans[p1] = max(cur_ans[p1], getMax(p1, a[id]));
            cur_ans[p1] = max(cur_ans[p1], getMax(p2, b[id]));
            p[p2] = p1;
            continue;
        }
        id = ~id;
        int c = get(x[id]);
        int ans = max(cur_ans[c], getMax(c, x[id]));
       // cout << " HI " << c << " " << cur_ans[c] << endl;
        val_max[id] = cur_mx[c];
        val_t[id] = ans;
    }
    for (int i = 1; i <= q; i++) {
        cout << val_max[i] << " " << val_t[i] << '\n';
    }
    return 0;
}