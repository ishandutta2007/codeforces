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

const int N = 105;

int n, m, k, P, f[N][N], g[N][N], C[N][N], fact[N];

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

void inline upd() {
    memcpy(g, f, sizeof g);
    memset(f, 0, sizeof f);
    add(f[1][0], 1);
    for (int u = 1; u <= n; u++) {
        for (int v = 0; v <= u; v++) {
            if (!g[u][v]) continue;
            add(f[u + 1][v], g[u][v] * 2 % P);
        }
    }
    for (int u = 1; u <= n; u++) {
        for (int v = 0; v <= u; v++) {
            if (!g[u][v]) continue;
            for (int x = 1; x + u <= n; x++) {
                for (int y = 0; y <= x && v + y <= k; y++) {
                    if (!g[x][y]) continue;
                    add(f[u + x + 1][v + y], 1ll * g[u][v] * g[x][y] % P * C[u + x][x] % P);
                }
            }
        }
    }
}
 
int main() {
    read(n), read(m), read(k), read(P);
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
    }
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (LL)fact[i - 1] * i % P;
    for (int i = 1; i <= n; i++) f[i][1] = fact[i];
    for (int i = 1; i < m; i++) upd();
    printf("%d\n", f[n][k]);
    return 0;
}