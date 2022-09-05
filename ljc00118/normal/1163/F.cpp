#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 3e5 + 5;

priority_queue < pair <ll, int> > Q;

struct edge_t { int u, v, next, w; } G[N << 1];

vector <int> adj[N];
ll dis[2][N];
int head[N], seq[N], u[N], v[N], w[N], fr[2][N], id[N], l[N], r[N], inpath[N];
int n, m, q, tot, len; ll ans;

inline void addedge(int u, int v, int w) {
    G[++tot] = (edge_t) {u, v, head[u], w}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], w}, head[v] = tot;
}

void dij(ll *dis, int *fr, int s) {
    for (int i = 1; i <= n; i++) dis[i] = 1e18;
    dis[s] = 0; Q.push(make_pair(0, s));
    while (!Q.empty()) {
        pair <ll, int> u = Q.top(); Q.pop();
        if (-u.first > dis[u.second]) continue;
        for (int i = head[u.second]; i; i = G[i].next) {
            int v = G[i].v;
            if (dis[v] > dis[u.second] + G[i].w) {
                dis[v] = dis[u.second] + G[i].w;
                fr[v] = u.second;
                Q.push(make_pair(-dis[v], v));
            }
        }
    }
}

ll mn[N << 2];
void add(int u, int L, int R, int l, int r, ll x) {
    if (l <= L && R <= r) {
        mn[u] = min(mn[u], x);
        return;
    }
    int mid = (L + R) >> 1;
    if (mid >= l) add(u << 1, L, mid, l, r, x);
    if (mid + 1 <= r) add(u << 1 | 1, mid + 1, R, l, r, x);
}

ll qry(int u, int l, int r, int x) {
    if (l == r) return mn[u];
    int mid = (l + r) >> 1; ll ans = mn[u];
    if (mid >= x) ans = min(ans, qry(u << 1, l, mid, x));
    else ans = min(ans, qry(u << 1 | 1, mid + 1, r, x));
    return ans;
}

void dfs1(int u, int col) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (l[v]) continue;
        l[v] = col; dfs1(v, col);
    }
}

void dfs2(int u, int col) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (r[v]) continue;
        r[v] = col; dfs2(v, col);
    }
}

int main() {
    memset(mn, 0x7f, sizeof(mn));
    read(n); read(m); read(q);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        read(u); read(v); read(w);
        addedge(u, v, w);
        ::u[i] = u; ::v[i] = v; ::w[i] = w;
    }
    dij(dis[0], fr[0], 1); dij(dis[1], fr[1], n);
    seq[len = 1] = 1;
    while (seq[len] != n) seq[len + 1] = fr[1][seq[len]], ++len;
    for (int i = 1; i <= len; i++) id[seq[i]] = i;
    for (int i = 1; i < len; i++) fr[0][seq[i + 1]] = seq[i];
    for (int i = 1; i <= n; i++) adj[fr[0][i]].push_back(i);
    for (int i = 1; i <= len; i++) l[seq[i]] = r[seq[i]] = i;
    for (int i = 1; i <= len; i++) dfs1(seq[i], i);
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= n; i++) adj[fr[1][i]].push_back(i);
    for (int i = 1; i <= len; i++) dfs2(seq[i], i);
    for (int j = 1; j < len; j++) {
        int u = seq[j];
        for (int i = head[u]; i; i = G[i].next) {
            int v = G[i].v;
            if (v == seq[j + 1] && G[i].w == dis[0][v] - dis[0][u]) {
                inpath[(i + 1) / 2] = 1;
                break;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!inpath[i]) {
            if (l[u[i]] < r[v[i]]) add(1, 1, len - 1, l[u[i]], r[v[i]] - 1, dis[0][u[i]] + dis[1][v[i]] + w[i]);
            if (l[v[i]] < r[u[i]]) add(1, 1, len - 1, l[v[i]], r[u[i]] - 1, dis[0][v[i]] + dis[1][u[i]] + w[i]);
        }
    }
    for (int i = 1; i <= q; i++) {
        int j, x;
        read(j); read(x);
        if (inpath[j]) {
            print(min(min(dis[0][u[j]] + dis[1][v[j]], dis[1][u[j]] + dis[0][v[j]]) + x, qry(1, 1, len - 1, min(id[u[j]], id[v[j]]))), '\n');
        } else {
            print(min(dis[0][n], min(dis[0][u[j]] + dis[1][v[j]], dis[1][u[j]] + dis[0][v[j]]) + x), '\n');
        }
    }
    return 0;
}