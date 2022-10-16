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

const int N = 4005;

int n, m, L[N], R[N], s[N], top, sz[N], rt;
 
LL a[N], f[N][N];

void dfs(int u) {
    if (!u) return;
    sz[u] = 1;
    int ls = L[u], rs = R[u];
    dfs(ls); sz[u] += sz[ls];
    dfs(rs); sz[u] += sz[rs];
    for (int x = 0; x <= sz[ls]; x++) {
        for (int y = 0; y <= sz[rs]; y++) {
            chkMax(f[u][x + y], f[ls][x] + f[rs][y] - 2 * a[u] * x * y);
            chkMax(f[u][x + y + 1], f[ls][x] + f[rs][y] + (m - 1) * a[u] - 2 * a[u] * (x * y + x + y));
        }
    }
}

int main() {
    memset(f, 0xcf, sizeof f);
    f[0][0] = 0;
    read(n), read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) {
        while (top && a[s[top]] > a[i]) L[i] = s[top--];
        if (top) R[s[top]] = i;
        s[++top] = i;
    }
    rt = s[1];
    dfs(rt);
    printf("%lld\n", f[rt][m]);
    return 0;
}