#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define ull unsigned long long
using namespace std;
const int N = 5e5 + 10;
int n;
struct fwt {
    int t[N];
    void M(int x, int v) {
        for(; x <= n; x += x & (-x)) t[x] += v;
    }
    int Q(int x) {
        int res = 0;
        for(; x; x -= x & (-x)) res += t[x];
        return res;
    }
    int kth(int k) {
        int pos = 0, sum = 0;
        ROF(i, 19, 0) {
            pos += 1 << i;
            if(pos > n || sum + t[pos] >= k) pos -= 1 << i;
            else sum += t[pos];
        }
        return pos + 1;
    }
}t;
vector<int> g[N];
int siz[N], big[N], dep[N], dfn[N], id[N], dtot, fa[N], top[N];
void dfs1(int u, int fa) {
    ::fa[u] = fa;
    siz[u] = 1;
    for(auto v : g[u]) if(v != fa) {
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[big[u]] < siz[v]) big[u] = v;
    }
}
void dfs2(int u, int tp) {
    dfn[u] = ++dtot;
    id[dtot] = u;
    top[u] = tp;
    if(big[u]) dfs2(big[u], tp);
    for(auto v : g[u]) if(v != fa[u] && v != big[u]) {
        dfs2(v, v);
    }
}
int lca(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    return v;
}
int up(int u, int a) {
    int v = -1;
    while(top[u] != top[a]) {
        if(t.Q(dfn[u]) - t.Q(dfn[top[u]] - 1) > 0) {
            v = u;
            break;
        }
        u = fa[top[u]];
    }
    int l, r;
    if(v == -1) {
        if(t.Q(dfn[u]) - t.Q(dfn[a]) > 0) {
            l = dfn[a], r = dfn[u];
        } else return -1;
    } else {
        l = dfn[top[u]] - 1, r = dfn[u];
    }
    int rk = t.Q(r);
    return id[t.kth(rk)];
}
int down(int u, int a) {
    int l = -1, r;
    while(top[u] != top[a]) {
        if(t.Q(dfn[u]) - t.Q(dfn[top[u]] - 1) > 0) {
            l = dfn[top[u]] - 1, r = dfn[u];
        }
        u = fa[top[u]];
    }
    if(t.Q(dfn[u]) - t.Q(dfn[a]) > 0) {
        l = dfn[a], r = dfn[u];
    }
    if(l == -1) return -1;
    int rk = t.Q(l);
    return id[t.kth(rk + 1)];
}
int ask(int u, int v) {
    int l = lca(u, v);
    int x = up(u, l);
    if(x != -1) return x;
    x = down(v, l);
    return x;
}
void dfs3(int u, int fa) {
    for(auto v : g[u]) if(v != fa) {
        dfs3(v, u);
    }
    if(fa) {
        int x = ask(u - n, fa - n);
        assert(x != -1);
        t.M(dfn[x], -1);
        cout << x <<" " << ::fa[x] <<" " << u - n <<" " << fa - n << "\n";
    }
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    FOR(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    FOR(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        u += n, v += n;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    FOR(i, 2, n) t.M(dfn[i], 1);
    cout << n - 1 << "\n";
    dfs3(n + 1, 0);
    return 0;
}