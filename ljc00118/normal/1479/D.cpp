#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

ull seed = chrono::system_clock::now().time_since_epoch().count() + 233;
inline ull R() {
    seed ^= seed << 17;
    seed ^= seed >> 13;
    seed ^= seed << 5;
    return seed;
}

const int N = 3e5 + 5;

vector <int> adj[N];
int lc[N * 30], rc[N * 30], rt[N];
ull sum[N * 30], val[N];
int tops[N], pre[N], fa[N], top[N], siz[N], wson[N], a[N], d[N];
int n, m, tot, dfn;

void ins(int &u, int pre, int l, int r, int x, ull y) {
    u = ++tot; lc[u] = lc[pre]; rc[u] = rc[pre]; sum[u] = sum[pre] ^ y;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (mid >= x) ins(lc[u], lc[pre], l, mid, x, y);
    else ins(rc[u], rc[pre], mid + 1, r, x, y);
}

void dfs1(int u, int fa) {
    siz[u] = 1;
    random_shuffle(adj[u].begin(), adj[u].end());
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        ::fa[v] = u; d[v] = d[u] + 1; dfs1(v, u); siz[u] += siz[v];
        if (siz[v] > siz[wson[u]]) wson[u] = v;
    }
}

void dfs2(int u, int tp) {
    tops[u] = ++dfn; pre[dfn] = u; top[u] = tp;
    if (wson[u]) dfs2(wson[u], tp);
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == wson[u] || v == fa[u]) continue;
        dfs2(v, v);
    }
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (d[top[u]] < d[top[v]]) swap(u, v);
        u = fa[top[u]];
    }
    return d[u] < d[v] ? u : v;
}

ull ss[60];
int le[60], ri[60], I[N], id[60];
int cnt, len;

void prepare_query(int L, int R, int l, int r) {
    if (l <= L && R <= r) {
        ++cnt;
        I[L] = cnt; le[cnt] = L; ri[cnt] = R;
        return;
    }
    int mid = (L + R) >> 1;
    if (mid >= l) prepare_query(L, mid, l, r);
    if (mid + 1 <= r) prepare_query(mid + 1, R, l, r);
}

void query(int u, int L, int R, int l, int r) {
    if (!u) return;
    if (l <= L && R <= r) {
        ss[I[L]] ^= sum[u];
        return;
    }
    int mid = (L + R) >> 1;
    if (mid >= l) query(lc[u], L, mid, l, r);
    if (mid + 1 <= r) query(rc[u], mid + 1, R, l, r);
}

void getid(int u, int L, int R, int l, int r) {
    if (!u) return;
    if (l <= L && R <= r) {
        id[++len] = u;
        return;
    }
    int mid = (L + R) >> 1;
    if (mid >= l) getid(lc[u], L, mid, l, r);
    if (mid + 1 <= r) getid(rc[u], mid + 1, R, l, r);
}

int main() {
    read(n); read(m);
    // n = 300000; m = 300000;
    for (int i = 1; i <= n; i++) val[i] = R();
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        // u = i + 1; v = R() % i + 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1, 1);
    for (int i = 1; i <= n; i++) ins(rt[pre[i]], rt[fa[pre[i]]], 1, n, a[pre[i]], val[a[pre[i]]]);
    while (m--) {
        int u, v, l, r;
        read(u); read(v); read(l); read(r);
        int tmp = lca(u, v);
        vector <int> pos = vector <int> {u, v, tmp, fa[tmp]};
        memset(ss, 0, sizeof(ss));
        cnt = 0;
        prepare_query(1, n, l, r);
        for (int i = 0; i < (int)pos.size(); i++) query(rt[pos[i]], 1, n, l, r);
        int cando = 0;
        for (int i = 1; i <= cnt; i++) {
            if (ss[i]) {
                cando = i;
                break;
            }
        }
        if (!cando) {
            print(-1, '\n');
            continue;
        }
        len = 0;
        for (int i = 0; i < (int)pos.size(); i++) getid(rt[pos[i]], 1, n, le[cando], ri[cando]);
        int L = le[cando], R = ri[cando];
        while (L != R) {
            int mid = (L + R) >> 1;
            ull ss = 0;
            for (int i = 1; i <= len; i++) ss ^= sum[lc[id[i]]];
            if (ss) {
                for (int i = 1; i <= len; i++) id[i] = lc[id[i]];
                R = mid;
            } else {
                for (int i = 1; i <= len; i++) id[i] = rc[id[i]];
                L = mid + 1;
            }
        }
        print(L, '\n');
    }
    return 0;
}