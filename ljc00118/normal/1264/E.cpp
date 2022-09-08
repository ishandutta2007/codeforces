#include <bits/stdc++.h>
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

const int N = 55, M = 5005, INF = 0x7fffffff;

struct edge_t { int u, v, next, cap, flow, cost; } G[M * 10];

queue <int> q;
int head[M], dis[M], maxflow[M], used[M], fr[M];
int a[N][N], in[N];
int n, m, s, t, ans, tot = 1;

inline void addedge(int u, int v, int cap, int cost) {
    G[++tot] = (edge_t) {u, v, head[u], cap, 0, cost}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], 0, 0, -cost}, head[v] = tot;
}

bool spfa() {
    memset(dis, 0x7f, sizeof(dis));
    dis[s] = 0; used[s] = 1; maxflow[s] = INF; q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop(); used[u] = 0;
        for(register int i = head[u]; i; i = G[i].next) {
            int v = G[i].v;
            if(G[i].cap > G[i].flow && dis[v] > dis[u] + G[i].cost) {
                dis[v] = dis[u] + G[i].cost;
                maxflow[v] = min(maxflow[u], G[i].cap - G[i].flow);
                fr[v] = i;
                if(!used[v]) {
                    used[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[t] != 0x7f7f7f7f;
}

int ans1, ans2;
void solve() {
    int tmp = t;
    while(tmp != s) {
        int i = fr[tmp];
        G[i].flow += maxflow[t];
        G[i ^ 1].flow -= maxflow[t];
        tmp = G[i].u;
    }
    ans1 += maxflow[t];
    ans2 += maxflow[t] * dis[t];
}

inline int c(int x, int y) { return (x - 1) * n + y; }

int main() {
    read(n); read(m); s = 0; t = n * n + n + 1;
    for(register int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        a[u][v] = 1;
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = i + 1; j <= n; j++) {
            if(!a[i][j] && !a[j][i]) {
                a[i][j] = a[j][i] = 2;
            }
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= n; j++) {
            if(a[i][j] == 1) ++in[j];
        }
    }
    for(register int i = 1; i <= n; i++) {
        ans += in[i] * (in[i] - 1) / 2;
        for(register int j = in[i]; j < n - 1; j++) {
            addedge(n * n + i, t, 1, j);
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = i + 1; j <= n; j++) {
            if(a[i][j] == 2) {
                addedge(s, c(i, j), 1, 0);
                addedge(c(i, j), n * n + i, 1, 0);
                addedge(c(i, j), n * n + j, 1, 0);
            }
        }
    }
    while(spfa()) solve();
    for(register int i = 1; i <= n; i++) {
        for(register int j = i + 1; j <= n; j++) {
            if(a[i][j] == 2) {
                int u = c(i, j), go;
                for(register int t = head[u]; t; t = G[t].next) {
                    int v = G[t].v;
                    if(v > n * n && G[t].cap == G[t].flow) {
                        go = v - n * n;
                        break;
                    }
                }
                if(go == i) a[i][j] = 0, a[j][i] = 1;
                else a[i][j] = 1, a[j][i] = 0;
            }
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= n; j++) {
            putchar(a[i][j] + '0');
        }
        putchar('\n');
    }
    return 0;
}