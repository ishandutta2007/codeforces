#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e5 + 10;
int n, q;
int p[maxN];
vector<int> g[maxN];
int le[maxN];
int ri[maxN];
int nxt_we[maxN];
int nxt[maxN];
int sz[maxN];
int get(int x) {
    if (x == p[x]) return x;
    p[x] = get(p[x]);
    return p[x];
}
int pos[maxN];
const int LOG = 20;
int mx[LOG][maxN];
int lg[maxN];
int get(int l, int r) {
    if (l > r) swap(l, r);
    if (l == r) return -1;
    assert(r > l);
    r--;
    int k = lg[r - l + 1];
    return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}
int mn_pos[4 * maxN];
int mx_pos[4 * maxN];
int all_mn[4 * maxN];
int all_mx[4 * maxN];
int lazy[4 * maxN];
void apply(int v, int x) {
    lazy[v] = x;
    if (x == 0) {
        mn_pos[v] = n + 1;
        mx_pos[v] = -1;
    }
    else {
        mn_pos[v] = all_mn[v];
        mx_pos[v] = all_mx[v];
    }
}
void push(int v, int tl, int tr) {
    if (tl != tr && lazy[v] != -1) {
        apply(2 * v, lazy[v]);
        apply(2 * v + 1, lazy[v]);
    }
    lazy[v] = -1;
}
void merge(int v) {
    mn_pos[v] = min(mn_pos[2 * v], mn_pos[2 * v + 1]);
    mx_pos[v] = max(mx_pos[2 * v], mx_pos[2 * v + 1]);
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        all_mn[v] = all_mx[v] = pos[tl];
        mn_pos[v] = n + 1;
        mx_pos[v] = -1;
        lazy[v] = -1;
        return;
    }
    int tm = (tl + tr) / 2;
    lazy[v] = -1;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    all_mn[v] = min(all_mn[2 * v], all_mn[2 * v + 1]);
    all_mx[v] = max(all_mx[2 * v], all_mx[2 * v + 1]);
    merge(v);
}
void upd(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        apply(v, x);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, x);
    upd(2 * v + 1, tm + 1, tr, l, r, x);
    merge(v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    vector<pair<int,pair<int,int>>> edges;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
//        g[u].emplace_back(v, w);
//        g[v].emplace_back(u, w);
        edges.emplace_back(w, make_pair(u, v));
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++) {
        le[i] = ri[i] = i;
        p[i] = i;
        sz[i] = 1;
    }
    for (auto& it : edges) {
        int u = it.second.first;
        int v = it.second.second;
        u = get(u);
        v = get(v);
        if (sz[u] > sz[v]) {
            swap(u, v);
        }
        sz[v] += sz[u];
        p[u] = v;
        nxt[ri[u]] = le[v];
        nxt_we[ri[u]] = it.first;
        le[v] = le[u];
        //ri[v] the same
    }
    int c = le[get(1)];
    for (int i = 1; i <= n; i++) {
//        cout << c << " " << nxt_we[c] << endl;
        pos[c] = i;
        mx[0][i] = nxt_we[c];
        c = nxt[c];
    }
//    cout << endl;
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }
    for (int k = 0; k + 1 < LOG; k++) {
        for (int i = 1; i + (1 << (k + 1)) - 1 <= n - 1; i++) {
            mx[k + 1][i] = max(mx[k][i], mx[k][i + (1 << k)]);
        }
    }
    build(1, 1, n);
    while (q--) {
        int tp;
        cin >> tp;
        if (tp <= 2) {
            int l, r;
            cin >> l >> r;
            if (tp == 1) upd(1, 1, n, l, r, 1);
            else upd(1, 1, n, l, r, 0);
        }
        else {
            int x;
            cin >> x;
            int le_1 = mn_pos[1];
            int ri_1 = mx_pos[1];
//            cout << le_1 << " " << ri_1 << " " << pos[x] << " " << get(6, 2) << endl;
            if (le_1 == n + 1) {
                assert(ri_1 == -1);
                cout << -1 << '\n';
            }
            else {
                int where = pos[x];
                cout << max(get(where, le_1), get(where, ri_1)) << '\n';
            }
        }
    }


    return 0;
}