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

const int N = 2e5 + 5;

struct edge_t { int u, v, nxt, val; } G[N];

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

vector <int> vec[N];
ll d[N];
int low[N], dfn[N], inst[N], st[N], col[N], head[N];
int n, m, q, tot, cnt_t, top, cnt_c;

inline void addedge(int u, int v, int val) {
    G[++tot] = (edge_t) {u, v, head[u], val}, head[u] = tot;
    // G[++tot] = (edge_t) {v, u, head[v], val}, head[v] = tot;
}

void tarjan(int u) {
    low[u] = dfn[u] = ++cnt_t; st[++top] = u; inst[u] = 1;
    for (int i = head[u]; i; i = G[i].nxt) {
        int v = G[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inst[v]) low[u] = min(low[u], dfn[v]);
    }
    // fprintf(stderr, "low[%d] = %d, dfn[%d] = %d\n", u, low[u], u, dfn[u]);
    if (low[u] == dfn[u]) {
        ++cnt_c;
        int tmp = 0;
        while (tmp != u) {
            tmp = st[top--];
            col[tmp] = cnt_c;
            vec[cnt_c].push_back(tmp);
            inst[tmp] = 0;
        }
    }
}

ll dis[N], all;
int vis[N], nowcol;
void dfs1(int u) {
    vis[u] = 1;
    for (int i = head[u]; i; i = G[i].nxt) {
        int v = G[i].v;
        if (col[v] != nowcol) continue;
        if (!vis[v]) {
            dis[v] = dis[u] + G[i].val;
            dfs1(v);
        } else {
            all = gcd(all, dis[u] - dis[v] + G[i].val);
        }
    }
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        read(u); read(v); read(w);
        addedge(u, v, w);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= cnt_c; i++) {
        nowcol = i;
        all = 0;
        dfs1(vec[i][0]);
        d[i] = all;
    }
    read(q);
    while (q--) {
        int u, s, t;
        read(u); read(s); read(t);
        if (s == 0) {
            printf("YES\n");
            continue;
        }
        // fprintf(stderr, "d[%d] = %lld\n", col[u], d[col[u]]);
        if ((t - s) % gcd(d[col[u]], t) == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}