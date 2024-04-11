#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
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

const int N = 100005;

struct edge_t {
    int u, v, next, val;
} G[N];

int head[N], tot;

inline void addedge(int u, int v, int val) {
    G[++tot] = (edge_t) {u, v, head[u], val}, head[u] = tot;
    // cout << u << " " << v << " " << val << endl;
}

vector <int> adj[N];
int res[N][55], nowans[N];
int t[N][55], col[N], low[N], dfn[N], vis[N], dis[N], st[N], inst[N];
int n, m, d, cnt, color, top;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void dfs1(int u, int c, int &nowans) {
    vis[u] = 1;
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(col[v] != c) continue;
        if(!vis[v]) {
            dis[v] = dis[u] + 1;
            dfs1(v, c, nowans);
        } else nowans = gcd(nowans, abs(dis[u] + 1 - dis[v]));
    }
}

void tarjan(int u) {
    low[u] = dfn[u] = ++cnt;
    st[++top] = u; inst[u] = 1;
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(inst[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++color;
        int last = top;
        while(st[top + 1] != u) {
            int tmp = st[top--];
            inst[tmp] = 0;
            col[tmp] = color;
        }
        int nowans = d;
        dfs1(u, color, nowans);
        ::nowans[color] = nowans;
        for(register int D = 0; D < nowans; D++) {
            for(register int i = top + 1; i <= last; i++) {
                int u = st[i], qaq = (D + dis[u]) % nowans;
                int val = 0;
                for(register int j = qaq; j <= d; j += nowans) val |= t[u][j];
                res[color][D] += val;
                // fprintf(stderr, "")
            }
        }
    }
}

int f[N][55];
int dfs2(int u, int x) {
    if(~f[u][x]) return f[u][x];
    f[u][x] = 0;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v, go = (x + G[i].val) % nowans[v];
        int d = gcd(nowans[v], nowans[u]);
        for(register int j = go % d; j <= nowans[v]; j += d) {
            f[u][x] = max(f[u][x], dfs2(v, j));
        }
    }
    f[u][x] += res[u][x];
    // fprintf(stderr, "f[%d][%d] = %d\n", u, x, f[u][x]);
    return f[u][x];
}

int main() {
    memset(f, -1, sizeof(f));
    ios::sync_with_stdio(false);
    cin >> n >> m >> d;
    for(register int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 0; j < d; j++) {
            char c; cin >> c;
            t[i][j] = c - '0';
        }
    }
    for(register int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
    // cout << "ok" << endl;
    for(register int u = 1; u <= n; u++) {
        for(register unsigned i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(col[u] != col[v]) {
                addedge(col[u], col[v], (dis[u] + nowans[col[v]] - dis[v] + 1) % nowans[col[v]]);
            }
        }
    }
    cout << dfs2(col[1], (nowans[col[1]] - dis[1]) % nowans[col[1]]) << endl;
    return 0;
} //