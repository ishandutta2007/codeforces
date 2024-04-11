#include <iostream>
#include <cstdio>
#include <cstring>
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

typedef pair<int, int> PII;

const int N = 1e6 + 5;

int n, m, b[N], tot;

int len;
int a[N];

bool v1[N], v2[N], vis[N];

vector<int> g[N], e[N];

void inline clear() {
    tot = len = 0;
    for (int i = 1; i <= 3 * n; i++) e[i].clear(), g[i].clear(), vis[i] = v1[i] = v2[i] = 0;
}

void dfs(int u, int fa, int id) {
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (vis[v]) continue;
        dfs(v, u, e[u][i]);
    }

    if (!v1[u]) {
        v1[u] = 1;
        b[++tot] = u;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            v1[v] = 1;
        }
    }

    if (fa && !v2[u] && !v2[fa]) {
        v2[u] = v2[fa] = 1;
        a[++len] = id;
    }
}

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(m);
        for (int i = 1, u, v; i <= m; i++) {
            read(u), read(v);
            g[u].pb(v), g[v].pb(u);
            e[u].pb(i), e[v].pb(i);
        }
        for (int i = 1; i <= 3 * n; i++) {
            if (!vis[i]) {
                dfs(i, 0, 0);
            }
        }
        if (len >= n) {
            puts("Matching");
            for (int i = 1; i <= n; i++)
                printf("%d ", a[i]);
            puts("");
        } else if (tot >= n) {
            puts("IndSet");
            for (int i = 1; i <= n; i++)
                printf("%d ", b[i]);
            puts("");
        } else {
            puts("Impossible");
        }
        clear();
    }
}