#include <iostream>
#include <cstdio>
#include <vector>
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

const int N = 2e5 + 5, P = 998244353;

int n, sz[N], fact[N], ans = 1;

vector<int> g[N];

void dfs(int u, int fa) {
    sz[u] = 1; int s = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u); ++s;
        sz[u] ++;
        ans = 1ll * ans * sz[v] % P;
    }
    ans = 1ll * fact[s] * ans % P;
}

int main() {
    read(n);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (LL)fact[i - 1] * i % P;
    for (int i = 1, u, v; i < n; i++)
        read(u), read(v), g[u].pb(v), g[v].pb(u);
    dfs(1, 0);
    printf("%lld\n", 1ll * n * ans % P);
}