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

const int N = 3005;

queue <pii> q;
vector <int> adj[N];
int g[N][N], dis[N][N], siz[N][N], in[N][N];
ll f[N][N], ans;
int n;

void dfs1(int u, int fa, int id, int val) {
    // fprintf(stderr, "%d %d %d %d\n", u, fa, id, val);
    siz[id][u] = 1; g[id][u] = val;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        dis[id][v] = dis[id][u] + 1; dfs1(v, u, id, val);
        siz[id][u] += siz[id][v];
    }
}

int main() {
    read(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int u = 1; u <= n; u++) {
        siz[u][u] = n;
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i]; dis[u][v] = 1;
            // fprintf(stderr, "ok\n");
            dfs1(v, u, u, v);
            if (u < v) {
                f[u][v] = 1ll * siz[u][v] * (n - siz[u][v]);
                q.push(make_pair(u, v));
            }
        }
    }
    // cout << "ok" << endl;
    // cout << siz[5][1] << " " << siz[5][3] << endl;
    while (!q.empty()) {
        pii u = q.front(); q.pop();
        for (int i = 0; i < (int)adj[u.first].size(); i++) {
            int v = adj[u.first][i];
            if (v == g[u.first][u.second]) continue;
            f[min(v, u.second)][max(v, u.second)] = max(f[min(v, u.second)][max(v, u.second)], f[u.first][u.second] + 1ll * siz[v][u.second] * (n - siz[v][u.first]));
            ++in[min(v, u.second)][max(v, u.second)];
            if (in[min(v, u.second)][max(v, u.second)] == 2) q.push(make_pair(min(v, u.second), max(v, u.second)));
        }
        swap(u.first, u.second);
        for (int i = 0; i < (int)adj[u.first].size(); i++) {
            int v = adj[u.first][i];
            if (v == g[u.first][u.second]) continue;
            // if (u.first == 1 && u.second == 5) fprintf(stderr, "debug : %d %d %d, siz[%d][%d] = %d\n", v, (int)f[u.first][u.second], siz[v][u.second] * (n - siz[v][u.first]), v, u.first, siz[v][u.first]);
            f[min(v, u.second)][max(v, u.second)] = max(f[min(v, u.second)][max(v, u.second)], f[u.second][u.first] + 1ll * siz[v][u.second] * (n - siz[v][u.first]));
            ++in[min(v, u.second)][max(v, u.second)];
            if (in[min(v, u.second)][max(v, u.second)] == 2) q.push(make_pair(min(v, u.second), max(v, u.second)));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans = max(ans, f[i][j]);
            // fprintf(stderr, "f[%d][%d] = %d\n", i, j, f[i][j]);
        }
    }
    print(ans, '\n');
    return 0;
}