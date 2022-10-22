#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define x first
#define y second
#define ull unsigned long long
#define pr pair<int, int>
#define tl tuple<int, int, int>
using namespace std;
const int N = 2e5 + 10, M = N * 42, V = 1e9;
int n, m, q, xtot;
ll ans[N], x[N];
map<pair<int, int>, pair<int, int>> lst;
vector<tl> mdf[N << 1];
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
int lc[M], rc[M], sum[M], tot = 0;
int stk[M], top = 0;
int rt[N];
int opt[N], u[N], v[N], w[N];
int newd() {
    return top > 0 ? stk[top--] : ++tot;
}
void del(int &u) {
    stk[++top] = u;
    lc[u] = rc[u] = sum[u] = 0;
    u = 0;
    return;
}
void ify(int p, int l, int r, int x, int v) {
    sum[p] += v;
    if(l == r) {

    } else {
        if(x <= mid) ify(ls, l, mid, x, v);
        else ify(rs, mid + 1, r, x, v);
    }
}
void modify(int &p, int l, int r, int x, int v) {
    if(!p) p = newd();
    sum[p] += v;
    if(l == r) {

    } else {
        if(x <= mid) modify(lc[p], l, mid, x, v);
        else modify(rc[p], mid + 1, r, x, v);
    }
    if(!sum[p]) return del(p);
}
void ins(int p, int l, int r, int L, int R, tl v) {
    if(L <= l && r <= R) {
        mdf[p].emplace_back(v);
        return;
    }
    if(L <= mid) ins(ls, l, mid, L, R, v);
    if(R > mid) ins(rs, mid + 1, r, L, R, v);
}
struct vec {
    ll a[6];
    vec() {FOR(i, 0, 5) a[i] = 1e18; }
    vec(vector<ll> b) {FOR(i, 0, 5) a[i] = 1e18; FOR(i, 0, sz(b) - 1) a[i] = b[i]; }
};
vec we[N];
vec merge(vec a, vec b) {
    vec c;
    merge(a.a, a.a + 3, b.a, b.a + 3, c.a);
    return c;
}
ll qry(int u) {
    if(we[u].a[0] > xtot || we[u].a[1] > xtot || we[u].a[2] > xtot) return 1e18;
    return (ll)x[we[u].a[0]] + x[we[u].a[1]] + x[we[u].a[2]];
}
int query(int p, int y, int z, int l, int r) {
    if(sum[p] - sum[y] - sum[z] == 0) return xtot + 1;
    if(l == r) return l;
    if(sum[ls] - sum[lc[y]] - sum[lc[z]] > 0) return query(ls, lc[y], lc[z], l, mid);
    return query(rs, rc[y], rc[z], mid + 1, r);
}
void dfs(int p, int l, int r, ll ans) {
    vector<pair<int, vec>> stk;
    for(auto [u, v, w] : mdf[p]) {
        stk.emplace_back(u, we[u]);
        stk.emplace_back(v, we[v]);
        we[u] = merge(we[u], vec({w}));
        we[v] = merge(we[v], vec({w}));
        ans = min(ans, (ll)x[query(1, rt[u], rt[v], 1, xtot)] + ::x[w]);
        ans = min({ans, qry(u), qry(v)});
        ify(1, 1, xtot, w, 1);
        modify(rt[u], 1, xtot, w, 1), modify(rt[v], 1, xtot, w, 1);
    }
    if(l == r) {
        ::ans[l] = ans;
    } else {
        dfs(ls, l, mid, ans);
        dfs(rs, mid + 1, r, ans);
    }
    ROF(i, sz(stk) - 1, 0) we[stk[i].first] = stk[i].second;
    for(auto [u, v, w] : mdf[p]) {
        ify(1, 1, xtot, w, -1);
        modify(rt[u], 1, xtot, w, -1), modify(rt[v], 1, xtot, w, -1);
    }
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    FOR(i, 1, m) cin >> u[i] >> v[i] >> w[i], x[++xtot] = w[i];
    cin >> q;
    FOR(i, m + 1, m + q) {
        cin >> opt[i];
        if(opt[i] == 0) cin >> u[i] >> v[i];
        else cin >> u[i] >> v[i] >> w[i], x[++xtot] = w[i];
    }
    sort(x + 1, x + xtot + 1);
    xtot = unique(x + 1, x + xtot + 1) - (x + 1);
    x[xtot + 1] = 1e18;
    FOR(i, 1, m + q) {
        if(i <= m || opt[i] == 1) w[i] = lower_bound(x + 1, x + xtot + 1, w[i]) - x;
    }
    FOR(i, 1, m) {
        int u = ::u[i], v = ::v[i], w = ::w[i];
        if(u > v) swap(u, v);
        lst[{u, v}] = {0, w};
    }
    FOR(i, 1, q) {
        int opt = ::opt[i + m], u = ::u[i + m], v = ::v[i + m], w = ::w[i + m];
        if(opt == 0) {
            if(u > v) swap(u, v);
            auto [l, w] = lst[{u, v}];
            ins(1, 0, q, l, i - 1, {u, v, w});
            lst.erase({u, v});
        } else {
            if(u > v) swap(u, v);
            lst[{u, v}] = {i, w};
        }
    }
    tot = xtot * 2 - 1;
    for(auto [fi, se] : lst) ins(1, 0, q, se.first, q, {fi.first, fi.second, se.second});
    dfs(1, 0, q, 1e18);
    FOR(i, 0, q) cout << ans[i] << "\n";
    return 0;
}