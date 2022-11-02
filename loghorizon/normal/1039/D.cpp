// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5;

int n, A[N], B[N], k, t, p[N], len, f[N];
 
vector<int> g[N];

void dfs1(int u, int fa) {
    p[++len] = u;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        f[v] = u;
        dfs1(v, u);
     }
}

int inline get(int x) {
    k = x;
    for (int i = 1; i <= n; i++) A[i] = 0, B[i] = 1;
    for (int o = n; o >= 2; o--) {
        int v = p[o], u = f[v];
        A[u] += A[v];
        if (~B[u]) {
            if (B[u] + B[v] >= k) A[u]++, B[u] = -1;
            else chkMax(B[u], B[v] + 1);
        }
    }
    return A[1];
}

int main() {
    read(n);
    for (int i = 1, u, v; i < n; i++)
        read(u), read(v), g[u].pb(v), g[v].pb(u);
    t = min(n, 400);
    dfs1(1, 0);
    printf("%d\n", n);
    for (int i = 2; i <= t; i++) {
        printf("%d\n", get(i));
    }
    for (int i = t + 1; i <= n; i++) {
        int l = i, r = n;
        int res = get(i);
        if (res) {
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (get(mid) == res) l = mid;
                else r = mid - 1;
            }
        } 
        for (int j = i; j <= r; j++) printf("%d\n", res);
        i = r;
    }
    return 0;
}