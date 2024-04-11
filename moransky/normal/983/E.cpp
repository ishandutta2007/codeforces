// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5, L = 18;

typedef pair<int, int> PII;

int n, fa[N][L], m, dep[N], q, nxt[N][L], ret[N], dfn[N], sz[N], now[N];
int dfncnt;
vector<int> g[N];

int inline lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = L - 1; ~i; i--)
        if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
    if (x == y) return x;
    for (int i = L - 1; ~i; i--)
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
int inline Min(int x, int y) {
    return dep[x] < dep[y] ? x : y;
}

int inline jump(int u, int p, int &o) {
    if (u == p) {
        o = u;
        return 0;
    }
    int res = 0;
    for (int i = L - 1; ~i; i--) {
        if (dep[nxt[u][i]] > dep[p]) u = nxt[u][i], res |= 1 << i;
    }
    if (nxt[u][0] == u) return -1;
    o = u;
    return res + 1;
}


void dfs(int u) {
    dfn[u] = ++dfncnt; sz[u] = 1;
    for (int v: g[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
}

vector<int> e[N];

struct T{
    int y, w, id;
};

vector<T> Q[N];

int c[N];

void inline add(int x, int k) {
    for (; x <= n; x += x & -x) c[x] += k;
}

int inline ask(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += c[x];
    return res;
}

int main() {
    read(n);
    for (int i = 2; i <= n; i++) read(fa[i][0]), g[fa[i][0]].pb(i), dep[i] = dep[fa[i][0]] + 1;
    for (int u = 1; u <= n; u++) {
        nxt[u][0] = u;
        for (int i = 1; i < L; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    dfs(1);
    read(m);
    while (m--) {
        int x, y; read(x), read(y);
        int p = lca(x, y); 
        if (p != x && p != y) {
            if (dfn[x] > dfn[y]) swap(x, y);
            e[dfn[x]].pb(dfn[y]);
        }
        nxt[x][0] = Min(nxt[x][0], p);
        nxt[y][0] = Min(nxt[y][0], p);
    }
    for (int i = n; i > 1; i--)
        nxt[fa[i][0]][0] = Min(nxt[fa[i][0]][0], nxt[i][0]);
    for (int u = 1; u <= n; u++) {
        for (int i = 1; i < L; i++) nxt[u][i] = nxt[nxt[u][i - 1]][i - 1];
    }
    read(q);
    for (int i = 1; i <= q; i++) {
        int x, y; read(x), read(y); 
        int p = lca(x, y);
        int u, v; 
        int a1 = jump(x, p, u), a2 = jump(y, p, v);
        if (a1 == -1 || a2 == -1) ret[i] = -1;
        else {
            int ans = a1 + a2;
            if (p != x && p != y) {
                x = u, y = v;

                if (dfn[x] > dfn[y]) swap(x, y);
                int Lx = dfn[x], Rx = dfn[x] + sz[x] - 1;
                int Ly = dfn[y], Ry = dfn[y] + sz[y] - 1;
                Q[Rx].pb((T) { Ry, 1, i });
                Q[Rx].pb((T) { Ly - 1, -1, i });
                Q[Lx - 1].pb((T) { Ry, -1, i });
                Q[Lx - 1].pb((T) { Ly - 1, 1, i });
            }
            ret[i] = ans;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int v: e[i]) add(v, 1);
        for (T v: Q[i]) {
            now[v.id] += v.w * ask(v.y);
        }
    }
    for (int i = 1; i <= q; i++) if (now[i]) ret[i]--;
    for (int i = 1; i <= q; i++) printf("%d\n", ret[i]);
    return 0;
}