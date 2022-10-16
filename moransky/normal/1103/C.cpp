// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
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
 
const int N = 250005;

int n, m, k, d[N], fa[N], s[N], mx;

vector<int> g[N];

void dfs(int u) {
    if (d[u] > d[mx]) mx = u;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (d[v]) continue;
        fa[v] = u, s[u]++, d[v] = d[u] + 1;
        dfs(v);
    }
}

int main() {
    read(n), read(m), read(k);
    for (int i = 1, u, v; i <= m; i++)
        read(u), read(v), g[u].pb(v), g[v].pb(u);
    d[1] = 1;
    dfs(1);
    if (d[mx] >= (n + k - 1) / k) {
        puts("PATH");
        printf("%d\n", d[mx]);
        while (mx) {
            printf("%d ", mx);
            mx = fa[mx];
        }
        return 0;
    } else {
        puts("CYCLES");
        int cnt = 0;
        for (int u = 1; u <= n; u++) {
            if (s[u]) continue;
            int x = 0, y = 0;
            for (int i = 0; i < g[u].size(); i++) {
                int v = g[u][i];
                if (v == fa[u]) continue;
                if (!x) x = v;
                else y = v;
            }
            if (d[x] > d[y]) swap(x, y);
            int A = d[u] - d[x] + 1, B = d[u] - d[y] + 1, C = d[y] - d[x] + 2;
            if (A % 3) {
                printf("%d\n", A);
                int p = u;
                while (p != x) {
                    printf("%d ", p);
                    p = fa[p];
                }
                printf("%d", x);
                puts("");
            } else if (B % 3) {
                printf("%d\n", B);
                int p = u;
                while (p != y) {
                    printf("%d ", p);
                    p = fa[p];
                }
                printf("%d", y);
                puts("");
            } else {
                printf("%d\n", C);
                printf("%d ", u);
                int p = y;
                while (p != x) {
                    printf("%d ", p);
                    p = fa[p];
                }
                printf("%d", x);
                puts("");
            }
            ++cnt;
            if (cnt == k) break;
        }
    }
	return 0;
}