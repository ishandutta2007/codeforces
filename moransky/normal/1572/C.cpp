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

const int N = 3005;

int n, a[N], f[N][N];

vector<int> g[N];
 
int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]), g[a[i]].pb(i);
        for (int l = 2; l <= n; l++) {
            for (int i = 1, j; (j = i + l - 1) <= n; i++) {
                f[i][j] = f[i + 1][j];
                for (int k: g[a[i]]) {
                    if (i < k && k <= j) {
                        chkMax(f[i][j], f[i + 1][k - 1] + f[k][j] + 1);
                    }
                }
            }
        }
        printf("%d\n", n - 1 - f[1][n]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) f[i][j] = 0;
        for (int i = 1; i <= n; i++) g[i].clear();
    }
    return 0;
}