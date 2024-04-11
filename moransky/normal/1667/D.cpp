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

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, rt, A[N], B[N];

vector<PII> g[N];
vector<PII> b[N][2];


bool f[N][2], ok;

int in[N], q[N];

vector<int> e[N];

void inline clr() {
    for (int i = 1; i <= n; i++) e[i].clear(), in[i] = 0, g[i].clear(), f[i][0] = f[i][1] = 0, b[i][0].clear(), b[i][1].clear();
}

void dfs(int u, int fa) {
    if (g[u].size() == 1) {
        f[u][0] = 1;
        return;
    }
    vector<PII> e0, e1, e2;
    PII fb;
    for (PII t: g[u]) {
        int v = t.fi;
        if (v == fa) {
            fb = t;
            continue;
        }
        dfs(v, u);
        if (!f[v][0] && !f[v][1]) {
            ok = 0;
            return;
        }
        if (!ok) return;
        if (f[v][0] && f[v][1]) e2.pb(t);
        else if (f[v][0]) e0.pb(t);
        else e1.pb(t);
    }
    int E = (g[u].size() + 1) / 2, O = g[u].size() - E;
    if (e0.size() > E || e1.size() > O) {
        ok = 0;
        return;
    }
    if (e0.size() < E) {
        f[u][0] = 1;
        vector<PII> nE = e0, nO = e1;
        nE.pb(fb);
        int x = 0;
        while (nE.size() < E) nE.pb(e2[x++]);
        while (nO.size() < O) nO.pb(e2[x++]);
        x = 0; int y = 0;
        for (int i = 0; i < g[u].size(); i++)
            if (i % 2 == 0) b[u][0].pb(nE[x++]);
            else b[u][0].pb(nO[y++]);
    } 
    if (e1.size() < O) {
        f[u][1] = 1;
        vector<PII> nE = e0, nO = e1;
        nO.pb(fb);
        int x = 0;
        while (nE.size() < E) nE.pb(e2[x++]);
        while (nO.size() < O) nO.pb(e2[x++]);
        x = 0; int y = 0;
        for (int i = 0; i < g[u].size(); i++)
            if (i % 2 == 0) b[u][1].pb(nE[x++]);
            else b[u][1].pb(nO[y++]);
    }
}

void inline topo() {
    int hh = 1, tt = 0;
    for (int i = 1; i < n; i++)
        if (!in[i]) q[++tt] = i;
    while (hh <= tt) {
        int u = q[hh++];
        for (int v: e[u]) {
            if (--in[v] == 0) q[++tt] = v;
        }
    }
}

void inline add(int x, int y) {
    in[y]++, e[x].pb(y);
}

void wk(int u, int fa, int o) {
    for (int i = 0; i < b[u][o].size(); i++) {
        PII t = b[u][o][i];
        if (i) {
            add(t.se, b[u][o][i - 1].se);
        }
        if (t.fi != fa) {
            assert(f[t.fi][i % 2 == 0 ? 0 : 1]);
            wk(t.fi, u, i % 2 == 0 ? 0 : 1);
        }
    }
}

void inline out() {
    wk(g[rt][0].fi, rt, 0);
    topo();
    for (int i = 1; i < n; i++) {
        int u = q[i];
        printf("%d %d\n", A[u], B[u]);
    }
}

int main() {
    int T; read(T);
    while (T--) {
    	read(n); ok = 1;
        for (int i = 1; i < n; i++) {
            int u, v; read(u), read(v);
            g[u].pb(mp(v, i));
            g[v].pb(mp(u, i));
            A[i] = u, B[i] = v;
        }
        for (int i = 1; i <= n; i++)
            if (g[i].size() == 1) rt = i;
        dfs(g[rt][0].fi, rt);
        if (!f[g[rt][0].fi][0]) ok = 0;
        if (!ok) puts("NO");
        else {
            puts("YES");
            out();
        }
        clr();
    }
    return 0;
}