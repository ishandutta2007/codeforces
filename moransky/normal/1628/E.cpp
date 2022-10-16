#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx") 
// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5, L = 19;

int n, q, fa[N], pre[N], dfn[N], dfncnt, faW[N];

int head[N], numE = 0;

struct E{
    int next, v, w;
} e[N << 1];

void inline add(int u, int v, int w) {
    e[++numE] = (E) { head[u], v, w };
    head[u] = numE;
}
 

int son[N], sz[N], top[N], mn[N], d[N];

void dfs1(int u) {
    sz[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v == fa[u]) continue;
        fa[v] = u;
        d[v] = d[u] + 1;
        faW[v] = e[i].w;
        dfs1(v);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;
    }
}


struct Seg{
    int Lg[N], st[L][N];
    void build() {
        Lg[0] = -1;
        for (int i = 1; i <= n; i++) {
            Lg[i] = Lg[i >> 1] + 1;
            st[0][i] = faW[pre[i]];
        }
        for (int j = 1; j <= Lg[n]; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    int query(int l, int r) {
        int k = Lg[r - l + 1];
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    }
} st;

void dfs2(int u, int tp) {
    dfn[u] = ++dfncnt;
    pre[dfn[u]] = u;
    top[u] = tp;
    if (top[u] == u) mn[u] = faW[u];
    else mn[u] = max(mn[fa[u]], faW[u]);
    if (son[u]) dfs2(son[u], tp);
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v == son[u] || v == fa[u]) continue;
        dfs2(v, v);
    }
}

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (d[top[x]] < d[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return d[x] < d[y] ? x : y;
}

int query(int x, int y) {
    int ret = 0;
    while (top[x] != top[y]) {
        if (d[top[x]] < d[top[y]]) swap(x, y);
        ret = max(ret, mn[x]);
        x = fa[top[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    if (dfn[x] < dfn[y]) ret = max(ret, st.query(dfn[x] + 1, dfn[y]));
    return ret;
}

#define ls (p << 1)
#define rs (p << 1 | 1)

int dat[N << 2], w[N << 2], tag[N << 2], R[N << 2];

int da[N << 2];

void inline pushup(int p) {
    dat[p] = max(dat[ls], dat[rs]);
    if (w[ls] && w[rs]) chkMax(dat[p], query(w[ls], w[rs]));
    w[p] = 0;
    if (w[ls]) w[p] = w[ls];
    if (w[rs]) w[p] = w[rs];
}

void inline cov(int p, int k) {
    tag[p] = k;
    if (!k) {
        dat[p] = w[p] = 0;
    } else {
        dat[p] = da[p], w[p] = R[p];
    }
}

void inline pushdown(int p) {
    if (tag[p] != -1) {
        cov(ls, tag[p]);
        cov(rs, tag[p]);
        tag[p] = -1;
    }
}

void build(int p, int l, int r) {
    R[p] = r;
    tag[p] = -1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    da[p] = max(da[ls], da[rs]);
    chkMax(da[p], query(l, r));
}

void change(int p, int l, int r, int x, int y, int k) {
    if (x <= l && r <= y) {
        cov(p, k);
        return;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    if (x <= mid) change(ls, l, mid, x, y, k);
    if (mid < y) change(rs, mid + 1, r, x, y, k);
    pushup(p);
}

int query(int p, int l, int r, int x) {
    if (l == r) return w[p];
    pushdown(p);
    int mid = (l + r) >> 1;
    if (x <= mid) return query(ls, l, mid, x);
    else return query(rs, mid + 1, r, x);
}

int main() {
    read(n); read(q);
    for (int i = 1; i < n; i++) {
        int u, v, w; read(u), read(v), read(w);
        add(u, v, w);
        add(v, u, w);
    }

    dfs1(1);
    dfs2(1, 1);
    st.build();


    build(1, 1, n);

    while (q--) {
        int op; read(op);
        if (op == 1) {
            int l, r; read(l), read(r);
            change(1, 1, n, l, r, 1);
        } else if (op == 2) {
            int l, r; read(l), read(r);
            change(1, 1, n, l, r, 0);
        } else {
            int x; read(x);
            bool o = 0;
            int ans = dat[1];
            if (w[1]) chkMax(ans, query(x, w[1]));
            if (ans == 0) ans = -1;
            printf("%d\n", ans);
        }
    }
    
    return 0;
}