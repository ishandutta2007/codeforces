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

const int N = 2e5 + 5, md = 998244353;

struct edge_t { int u, v, next, val; } G[N << 1];

int head[N], f[N][4], u[N], v[N];
int n, tot;

inline void addedge(int u, int v, int val) {
    G[++tot] = (edge_t) {u, v, head[u], val}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], val}, head[v] = tot;
}

void dfs1(int u, int fa, int val) {
    f[u][0] = f[u][1] = 1;
    if (!fa) val = n;
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        dfs1(v, u, G[i].val);
        if (G[i].val < val) f[u][2] = (1ll * f[u][2] * ((ll)f[v][0] + f[v][2] + f[v][3]) % md + 1ll * f[u][0] * (f[v][0] + f[v][3]) % md) % md;
        else f[u][2] = 1ll * f[u][2] * ((ll)f[v][0] + f[v][2] + f[v][3]) % md;
        if (G[i].val > val) f[u][3] = (1ll * f[u][3] * ((ll)f[v][0] + f[v][2] + f[v][3]) % md + 1ll * f[u][0] * (f[v][0] + f[v][3]) % md) % md;
        f[u][0] = 1ll * f[u][0] * (f[v][1] + f[v][2]) % md;
        if (G[i].val < val) f[u][1] = 1ll * f[u][1] * (f[v][1] + f[v][2]) % md;
        else f[u][1] = 1ll * f[u][1] * ((ll)f[v][0] + f[v][2] + f[v][3]) % md;
    }
    // fprintf(stderr, "%d : %d %d %d %d\n", u, f[u][0], f[u][1], f[u][2], f[u][3]);
}

int main() {
    read(n);
    for (int i = 1; i < n; i++) {
        read(u[i]); read(v[i]);
    }
    for (int i = n - 1; i >= 1; i--) {
        addedge(u[i], v[i], i);
    }
    dfs1(1, 0, 0);
    print((f[1][0] + f[1][2]) % md, '\n');
    return 0;
}