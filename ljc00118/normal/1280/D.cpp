#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

struct edge_t { int u, v, next; } G[N << 1];

struct info {
    int f; ll g;
    info (int a = 0, ll b = 0) : f(a), g(b) {}
    bool operator < (const info A) const {
        if (f != A.f) return f < A.f;
        return g < A.g;
    }
};

info operator + (const info a, const info b) {
    return info(a.f + b.f, a.g + b.g);
}

inline info get(info x) { return info(x.f + (x.g > 0), 0); }

info f[N][N], tmp[N];
int head[N], a[N], b[N], siz[N];
int T, n, m, tot;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

void dfs1(int u, int fa) {
    siz[u] = 0; f[u][0] = info(0, b[u]);
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        dfs1(v, u);
        for (int j = 0; j <= siz[u] + siz[v]; j++) tmp[j] = info(-1, 0);
        for (int j = 0; j <= siz[u]; j++) {
            for (int k = 0; k <= siz[v]; k++) {
                tmp[j + k] = max(tmp[j + k], f[u][j] + f[v][k]);
            }
        }
        siz[u] += siz[v];
        for (int j = 0; j <= siz[u]; j++) f[u][j] = tmp[j];
    }
    if (u != 1) {
        ++siz[u]; f[u][siz[u]] = get(f[u][siz[u] - 1]);
        for (int i = siz[u] - 1; i >= 1; i--) f[u][i] = max(f[u][i], get(f[u][i - 1]));
    }
}

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 1; i <= n; i++) read(b[i]), b[i] -= a[i];
        for (int i = 1; i <= n; i++) head[i] = 0;
        tot = 0;
        for (int i = 1; i < n; i++) {
            int u, v;
            read(u); read(v);
            addedge(u, v);
        }
        dfs1(1, 0);
        print(get(f[1][m - 1]).f, '\n');
    }
    return 0;
}