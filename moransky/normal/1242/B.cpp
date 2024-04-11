#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }

const int N = 1e5 + 5;

int n, m, f[N], s[N], top, ans;

vector<int> g[N];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n + 1; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        g[i].pb(0);
        g[i].pb(n + 1);
        sort(g[i].begin(), g[i].end());
    }
    for (int i = 1; i <= n; i++) {
        int u = -1;
        if (i == 1) u = 1;
        else {
            if (top) u = s[top--];
            else u = find(1), ans++;
        }
        if (find(u) == u) f[u] = u + 1;
        for (int j = 0; j + 1 < g[u].size(); j++) {
            int p = find(g[u][j] + 1), r = g[u][j + 1] - 1;
            while (p <= r) {
                s[++top] = p;
                f[p] = p + 1;
                p = find(p);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}