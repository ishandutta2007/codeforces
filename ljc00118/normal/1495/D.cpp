#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int md = 998244353;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 405;

vector <int> adj[N];
queue <int> q;
int ans[N][N], dis[2][N], cnt[2][N], vis[N];
int n, m;

void bfs(int *dis, int *cnt, int s) {
    for (int i = 1; i <= n; i++) dis[i] = N, cnt[i] = 0;
    dis[s] = 0; cnt[s] = 1; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            } else if (dis[v] == dis[u] + 1) {
                cnt[v] = min(2, cnt[v] + cnt[u]);
            }
        }
    }
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            bfs(dis[0], cnt[0], i);
            if (cnt[0][j] != 1) continue;
            bfs(dis[1], cnt[1], j);
            memset(vis, 0, sizeof(vis));
            for (int k = 1; k <= n; k++) {
                if (dis[0][k] + dis[1][k] == dis[0][j]) {
                    vis[k] = 1;
                }
            }
            int res = 1;
            for (int k = 1; k <= n; k++) {
                if (vis[k]) continue;
                int cnt = 0;
                for (int t = 0; t < (int)adj[k].size(); t++) {
                    int v = adj[k][t];
                    if (dis[0][v] + 1 == dis[0][k] && dis[1][v] + 1 == dis[1][k]) ++cnt;
                }
                // if (i == 1 && j == 1) fprintf(stderr, "k = %d, cnt = %d\n", k, cnt);
                res = mul(res, cnt);
            }
            ans[i][j] = ans[j][i] = res;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            print(ans[i][j], j == n ? '\n' : ' ');
        }
    }
    return 0;
}