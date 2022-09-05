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

vector <int> adj[N];
int dep[N], mn[N], vis[N], dp[N];
int T, n, k;

void dfs1(int u, int fa) {
    mn[u] = 1e9;
    for (auto v : adj[u]) {
        if (v == fa) continue;
        dep[v] = dep[u] + 1; dfs1(v, u);
        mn[u] = min(mn[u], mn[v] + 1);
    }
    if (vis[u]) mn[u] = 0;
}

void dfs2(int u, int fa) {
    if (dep[u] >= mn[u]) {
        dp[u] = 1;
        return;
    }
    if (u != 1 && adj[u].size() == 1) {
        dp[u] = 1e9;
        return;
    }
    dp[u] = 0;
    for (auto v : adj[u]) {
        if (v == fa) continue;
        dfs2(v, u);
        dp[u] = min(dp[u] + dp[v], (int)1e9);
    }
}

int main() {
    read(T);
    while (T--) {
        read(n); read(k);
        for (int i = 1; i <= n; i++) adj[i].clear(), vis[i] = 0;
        for (int i = 1; i <= k; i++) {
            int x; read(x);
            vis[x] = 1;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            read(u); read(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(1, 0); dfs2(1, 0);
        if (dp[1] == (int)1e9) dp[1] = -1;
        print(dp[1], '\n');
    }
    return 0;
}