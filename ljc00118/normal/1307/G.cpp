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

const int N = 55, INF = 0x7fffffff;

struct edge_t { int u, v, next, cap, flow, cost; } G[N * N * 2];

int head[N], dis[N], maxflow[N], fr[N], used[N], _dis[N], _flow[N], _must[N];
int n, m, q, tot = 1, ans1, ans2, len;

inline void addedge(int u, int v, int cap, int cost) {
    G[++tot] = (edge_t) {u, v, head[u], cap, 0, cost}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], 0, 0, -cost}, head[v] = tot;
}

int spfa() {
    memset(dis, 0x7f, sizeof(dis)); queue <int> q;
    dis[1] = 0; used[1] = 1; maxflow[1] = INF; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop(); used[u] = 0;
        for (int i = head[u]; i; i = G[i].next) {
            int v = G[i].v;
            if (G[i].cap > G[i].flow && dis[v] > dis[u] + G[i].cost) {
                dis[v] = dis[u] + G[i].cost; fr[v] = i;
                maxflow[v] = min(maxflow[u], G[i].cap - G[i].flow);
                if (!used[v]) { used[v] = 1; q.push(v); }
            }
        }
    }
    return dis[n] != 0x7f7f7f7f;
}

void solve() {
    int tmp = n;
    while (tmp != 1) {
        int i = fr[tmp];
        G[i].flow += maxflow[n];
        G[i ^ 1].flow -= maxflow[n];
        tmp = G[i].u;
    }
    ans1 += maxflow[n];
    ans2 += maxflow[n] * dis[n];
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        read(u); read(v); read(w);
        addedge(u, v, 1, w);
    }
    while (spfa()) {
        solve();
        ++len; _dis[len] = dis[n]; _flow[len] = ans1; _must[len] = 1ll * ans1 * dis[n] - ans2;
        // fprintf(stderr, "dis = %d, flow = %d, must = %d\n", _dis[len], _flow[len], _must[len]);
    }
    read(q);
    while (q--) {
        int x; read(x);
        double minn = 1e18;
        for (int i = 1; i <= len; i++) if (x >= _must[i]) minn = min(minn, _dis[i] + (double)(x - _must[i]) / _flow[i]);
        printf("%.10lf\n", minn);
    }
    return 0;
}