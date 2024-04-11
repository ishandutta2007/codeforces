#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int INF = 0x3f3f3f3f;

struct atom {
    int a, b, c;
    bool operator < (const atom A) const { return c < A.c; }
} a[105];

int f[1 << 14][105], g[1 << 14][105], dis[1 << 14][105], dis2[105][105], dis3[1 << 14][14];
int xa[14], ya[14], x[105], y[105], t[105];
int n, m, ans = 1;

int main() {
    // freopen("1.in", "r", stdin);
    memset(f, 0x3f, sizeof(f)); memset(dis, 0x3f, sizeof(dis)); memset(dis3, 0x3f, sizeof(dis3));
    read(n); read(m);
    for (int i = 0; i < n; i++) read(xa[i]), read(ya[i]);
    for (int i = 1; i <= m; i++) read(a[i].a), read(a[i].b), read(a[i].c);
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++) x[i] = a[i].a, y[i] = a[i].b, t[i] = a[i].c;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < n; k++) {
                if ((i >> k) & 1) {
                    dis[i][j] = min(dis[i][j], abs(xa[k] - x[j]) + abs(ya[k] - y[j]));
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) continue;
            for (int k = 0; k < n; k++) {
                if ((i >> k) & 1) {
                    dis3[i][j] = min(dis3[i][j], abs(xa[j] - xa[k]) + abs(ya[j] - ya[k]));
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            dis2[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        }
    }
    for (int i = 0; i < n; i++) f[1 << i][0] = 0;
    for (int i = 1; i <= m; i++) g[0][i] = 1;
    for (int i = 0; i < (1 << n); i++) {
        // for (int j = m; j >= 0; j--) f[i][j] = min(f[i][j], f[i][j + 1]);
        for (int j = 1; j <= m; j++) {
            int pos = upper_bound(f[i], f[i] + m + 1, t[j] - dis[i][j]) - f[i] - 1;
            if (pos != -1) g[i][j] = max(g[i][j], pos + 1);
            if (!g[i][j]) continue;
            for (int k = j + 1; k <= m; k++) {
                if (t[j] + min(dis[i][k], dis2[j][k]) <= t[k]) {
                    g[i][k] = max(g[i][k], g[i][j] + 1);
                }
            }
        }
        // for (int j = 0; j <= m; j++) {
        //     fprintf(stderr, "f[%d][%d] = %d\n", i, j, f[i][j]);
        // }
        // for (int j = 0; j <= m; j++) {
        //     fprintf(stderr, "g[%d][%d] = %d\n", i, j, g[i][j]);
        // }
        // for (int j = 1; j <= m; j++) assert(f[i][j - 1] <= f[i][j]);
        for (int j = 0; j <= m; j++) {
            if (f[i][j] != INF) {
                for (int k = 0; k < n; k++) {
                    if ((i >> k) & 1) continue;
                    f[i | (1 << k)][j] = min(f[i | (1 << k)][j], f[i][j] + dis3[i][k]);
                }
            }
        }
        for (int j = 1; j <= m; j++) {
            if (g[i][j] != 0) {
                for (int k = 0; k < n; k++) {
                    if ((i >> k) & 1) continue;
                    f[i | (1 << k)][g[i][j]] = min(f[i | (1 << k)][g[i][j]], t[j] + min(dis3[i][k], abs(xa[k] - x[j]) + abs(ya[k] - y[j])));
                    // if ((i | (1 << k)) == 5 && g[i][j] == 1) {
                        // fprintf(stderr, "i = %d, j = %d, val = %d, t[j] = %d\n", i, j, t[j] + min(dis3[i][k], abs(xa[k] - x[j]) + abs(ya[k] - y[j])) + 1, t[j]);
                    // }
                }
            }
            ans = max(ans, g[i][j]);
        }
    }
    print(ans, '\n');
    return 0;
}