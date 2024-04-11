// Skyqwq
#include <bits/stdc++.h>

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

const int N = 2e5 + 5;

int n, d[N], rt, c[N], t, f[N], cnt, pre[N];

vector<int> g[N];

void dfs(int u, int fa) {
    pre[++cnt] = u;
    for (int v: g[u]) {
        if (v == fa) continue;
        f[v] = u;
        dfs(v, u);
    }
    if (d[u] % 2 == 0) c[++t] = u;
}

bool vis[N];

void clear(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    printf("%d\n", u);
    d[f[u]]--;
    for (int v: g[u]) {
        if (v == f[u]) continue;
        clear(v);
    }
    g[u].clear();
}

int main() {
    read(n);
    for (int i = 1, p; i <= n; i++) {
        read(p);
        if (p) g[i].pb(p), g[p].pb(i), d[p]++, d[i]++;
    }
    if (n % 2 == 0) { puts("NO"); return 0; }
    for (int i = 1; i <= n; i++) if (d[i] % 2 == 0) rt = i;
    dfs(rt, 0);
    puts("YES");
    for (int i = n; i; i--) {
        int u = pre[i];
        if (d[u] % 2 == 0) clear(u);
    }
    return 0; 
}