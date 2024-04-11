#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 5e5 + 5;

const LL INF = 1e18;

LL inline C(int x) {
    return x * (x - 1ll) / 2;
}

int n, sz[N], d[N];
LL f[N], ans = INF;

vector<int> g[N];

void inline chk(int v1, int v2) {
    if (v2 == -1) return;
    chkMin(ans, f[v1] + f[v2] + C(n - sz[v1] - sz[v2]));
}

bool inline cmp(int x, int y) {
    return sz[x] > sz[y];
}

int hh = 1, tt = 0;

long double k[N], b[N];
int id[N];

long double inline Inter(long double K1, long double B1, long double K2, long double B2) {
    return ((long double)B2 - B1) / ((long double)K1 - K2);
}

int inline get(LL x) {
    while (hh < tt && Inter(k[hh], b[hh], k[hh + 1], b[hh + 1]) < x) hh++;
    if (hh > tt) return -1;
    return id[hh];
}

void inline add(long double K, long double B, int v) {
    if (hh <= tt && k[tt] == K) {
        if (b[tt] > B) b[tt] = B, id[tt] = v;
        return;
    }
    while (hh < tt) {
        if (Inter(K, B, k[tt - 1], b[tt - 1]) < Inter(k[tt], b[tt], k[tt - 1], b[tt - 1])) {
            tt--;
        } else break;
    }
    ++tt;
    k[tt] = K, b[tt] = B, id[tt] = v;
}

void dfs(int u, int fa) {
    sz[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
    f[u] = C(sz[u]);
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        chkMin(f[u], f[v] + C(sz[u] - sz[v]));
        chkMin(ans, f[v] + C(n - sz[v]));
    }
    sort(g[u].begin(), g[u].end(), cmp);
    hh = 1, tt = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        chk(v, get(sz[v]));
        add(sz[v], f[v] - 1ll * n * sz[v] + 1ll * sz[v] * (sz[v] - 1) / 2, v);
    }
}

int main() {
    read(n);
    for (int i = 1, u, v; i < n; i++) {
        read(u), read(v);
        g[u].pb(v), g[v].pb(u);
    }
    d[1] = 0;
    dfs(1, 0);
    printf("%lld\n", 2 * C(n) - ans);
}