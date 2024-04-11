#include <bits/stdc++.h>
#include <Windows.h>
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

const int N = 2e5 + 105;

vector <int> adj[N];
int fa[N], siz[N], tops[N], wson[N], top[N], dep[N], val[N][25];
int n, m, dfnt;

void dfs1(int u) {
    siz[u] = 1;
    for (auto v : adj[u]) {
        if (v == fa[u]) continue;
        dep[v] = dep[u] + 1; fa[v] = u; dfs1(v); siz[u] += siz[v];
        if (siz[v] > siz[wson[u]]) wson[u] = v;
    }
}

void dfs2(int u, int tp) {
    tops[u] = ++dfnt; top[u] = tp;
    if (wson[u]) dfs2(wson[u], tp);
    for (auto v : adj[u]) {
        if (v == fa[u] || v == wson[u]) continue;
        dfs2(v, v);
    }
}

struct fenwick {
    int f[N];

    void add(int x, int y) {
        while (x <= n) {
            f[x] += y;
            x += (x & -x);
        }
    }

    void add(int l, int r, int y) {
        add(l, y); add(r + 1, -y);
    }

    int query(int x) {
        int ans = 0;
        while (x) {
            ans += f[x];
            x &= (x - 1);
        }
        return ans;
    }
} tr[25];

int main() {
    read(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= 20; i++) {
        ++n; adj[n].push_back(n - 1);
    }
    dfs1(n); dfs2(n, n);
    read(m);
    while (m--) {
        int opt;
        read(opt);
        if (opt == 1) {
            int u, ans = 0; read(u);
            int x = u;
            for (int i = 0; i <= 20; i++) {
                ans += tr[i].query(tops[x]);
                ans += val[x][i];
                x = fa[x];
            }
            print(ans, '\n');
        }
        if (opt == 2) {
            int u, v, k, d;
            read(u); read(v); read(k); read(d);
            while (top[u] != top[v]) {
                if (dep[top[u]] < dep[top[v]]) swap(u, v);
                tr[d].add(tops[top[u]], tops[u], k);
                u = fa[top[u]];
            }
            if (dep[u] > dep[v]) swap(u, v);
            tr[d].add(tops[u] + 1, tops[v], k);
            for (int i = 0; i <= d; i++) {
                val[u][d - i] += k;
                if (i != d) val[u][d - i - 1] += k;
                u = fa[u];
            }
        }
    }
    return 0;
}