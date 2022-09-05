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

const int N = 55;

struct edge_t { int v, nxt, w; } G[233333];

queue <int> q;
int a[N][N], id[N][N], d[N], deg[N], f[N], tem[N], dis[N * N], cnt[N * N], pre[N * N], vis[N * N], used[N * N], u[N * N], v[N * N], head[N * N];
int n, k, ans = 1e9, tot;

inline void addedge(int u, int v, int w) {
    G[++tot] = (edge_t) {v, head[u], w}, head[u] = tot;
}

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
    read(n); read(k);
    for (int i = 1; i <= k; i++) read(d[i]);
    for (int i = k + 1; i <= n; i++) d[i] = n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) read(a[i][j]);
    }
    int m = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = max(k + 1, i + 1); j <= n; j++) {
            id[i][j] = ++m; u[m] = i; v[m] = j;
        }
    }
    for (int mask = 0; mask < (1 << (k * (k - 1) / 2)); mask++) {
        for (int i = 1; i <= n; i++) f[i] = i;
        memset(deg, 0, sizeof(deg));
        int now = 0, cando = 1, sum = 0;
        for (int u = 1; u <= k; u++) {
            for (int v = u + 1; v <= k; v++) {
                if ((mask >> now) & 1) {
                    int x = find(u), y = find(v);
                    if (x == y) cando = 0;
                    ++deg[u]; ++deg[v]; f[x] = y; sum += a[u][v];
                }
                ++now;
            }
        }
        for (int i = 1; i <= k; i++) {
            if (deg[i] > d[i]) {
                cando = 0;
            }
        }
        if (!cando) continue;
        memcpy(tem, f, sizeof(tem));
        memset(used, 0, sizeof(used));
        while (1) {
            memset(head, 0, (m + 2) * 4); tot = 0;
            int s = 0, t = m + 1;
            for (int i = 1; i <= m; i++) {
                if (used[i]) {
                    memcpy(f, tem, sizeof(f));
                    for (int j = 1; j <= m; j++) {
                        if (used[j] && i != j) {
                            f[find(u[j])] = find(v[j]);
                        }
                    }
                    for (int j = 1; j <= m; j++) {
                        if (!used[j] && find(u[j]) != find(v[j])) {
                            addedge(i, j, a[u[j]][v[j]]);
                        }
                    }
                    --deg[u[i]]; --deg[v[i]];
                    for (int j = 1; j <= m; j++) {
                        if (!used[j] && deg[u[j]] < d[u[j]] && deg[v[j]] < d[v[j]]) {
                            addedge(j, i, -a[u[i]][v[i]]);
                        }
                    }
                    ++deg[u[i]]; ++deg[v[i]];
                }
            }
            memcpy(f, tem, sizeof(f));
            for (int i = 1; i <= m; i++) {
                if (used[i]) {
                    f[find(u[i])] = find(v[i]);
                }
            }
            for (int i = 1; i <= m; i++) {
                if (!used[i]) {
                    if (find(u[i]) != find(v[i])) {
                        addedge(s, i, a[u[i]][v[i]]);
                    }
                    if (deg[u[i]] < d[u[i]] && deg[v[i]] < d[v[i]]) {
                        addedge(i, t, 0);
                    }
                }
            }
            memset(dis, 0x3f, (m + 2) * 4);
            q.push(s); dis[s] = 0; vis[s] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop(); vis[u] = 0;
                for (int i = head[u]; i; i = G[i].nxt) {
                    int v = G[i].v;
                    if (dis[v] > dis[u] + G[i].w || (dis[v] == dis[u] + G[i].w && cnt[v] > cnt[u] + 1)) {
                        dis[v] = dis[u] + G[i].w; cnt[v] = cnt[u] + 1; pre[v] = u;
                        if (!vis[v]) { vis[v] = 1; q.push(v); }
                    }
                }
            }
            if (dis[t] == 0x3f3f3f3f) break;
            sum += dis[t];
            int tmp = pre[t];
            while (tmp) {
                if (used[tmp]) --deg[u[tmp]], --deg[v[tmp]];
                else ++deg[u[tmp]], ++deg[v[tmp]];
                used[tmp] ^= 1;
                tmp = pre[tmp];
        }
            }
        int ecnt = __builtin_popcount(mask);
        for (int i = 1; i <= m; i++) ecnt += used[i];
        if (ecnt == n - 1) ans = min(ans, sum);
    }
    print(ans, '\n');
    return 0;
}