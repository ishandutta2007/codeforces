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

const int N = 2e5 + 5;

vector <int> adj[N];
int dep[N], fa[N][20], a[N];
int n, q;

void dfs1(int u) {
    for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : adj[u]) {
        if (v == fa[u][0]) continue;
        fa[v][0] = u; dep[v] = dep[u] + 1; dfs1(v);
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main() {
    read(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[1] = 1; dfs1(1);
    read(q);
    while (q--) {
        int k; read(k);
        for (int i = 1; i <= k; i++) read(a[i]);
        if (k <= 2) {
            printf("YES\n");
            continue;
        }
        int u = a[1], v = a[2], len = dis(u, v), ans = 1;
        for (int i = 3; i <= k; i++) {
            int x = dis(u, a[i]), y = dis(v, a[i]);
            if (x == len + y) {
                len = x; v = a[i];
            } else if (y == len + x) {
                len = y; u = a[i];
            } else if (len == x + y) {

            } else {
                ans = 0;
                break;
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}