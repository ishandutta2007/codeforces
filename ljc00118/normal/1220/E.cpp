#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5, INF = 0x7fffffff;

struct edge_t { int u, v, next; } G[N << 1];

vector <int> adj[N]; map <pii, bool> wxw;
int head[N], w[N], low[N], dfn[N], big[N], col[N], st[N], inst[N];
ll f[N][2], sum[N];
int n, m, cnt, tops, tot, top, s;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++tops; st[++top] = u; inst[u] = 1;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if(inst[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++cnt;
        while(st[top + 1] != u) {
            int tmp = st[top--];
            inst[tmp] = 0;
            col[tmp] = cnt;
            ++big[cnt];
            sum[cnt] += w[tmp];
        }
    }
}

void dfs1(int u, int fa) {
    f[u][0] = sum[u]; f[u][1] = sum[u];
    ll maxn = 0; bool ok = 0;
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        dfs1(v, u);
        if(f[v][1] >= 0) f[u][0] += f[v][1], f[u][1] += f[v][1], maxn = max(maxn, f[v][0] - f[v][1]), ok = 1;
        else maxn = max(maxn, f[v][0]);
    }
    f[u][0] += maxn;
    if(big[u] == 1 && !ok) f[u][1] = -INF;
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) read(w[i]);
    for(register int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        addedge(u, v);
    }
    read(s);
    for(register int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i, 0);
    for(register int u = 1; u <= n; u++) {
        for(register int i = head[u]; i; i = G[i].next) {
            int v = G[i].v;
            int x = col[u], y = col[v];
            if(x == y) continue;
            if(x > y) swap(x, y);
            if(wxw.count(make_pair(x, y))) continue;
            adj[x].push_back(y); adj[y].push_back(x);
            wxw[make_pair(x, y)] = 1;
        }
    }
    dfs1(col[s], 0); print(f[col[s]][0], '\n');
    return 0;
}