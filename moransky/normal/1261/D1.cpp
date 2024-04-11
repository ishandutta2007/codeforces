#include <iostream>
#include <cstdio>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 2e3 + 5, P = 998244353;

int n, k, a[N], f[N][N * 2], ans, D = 2001;

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

void inline upd(int i, int j, int k, int o) {
    add(f[i][j + k], 1ll * f[i - 1][j] * o % P);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    f[0][D] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = - i + D; j <= i + D; j++) {
            int o = k - 1;
            upd(i, j, - 1 + (a[i] == a[i % n + 1]), 1);
            if (a[i] != a[i % n + 1]) upd(i, j, 1, 1), o--;
            upd(i, j, 0, o);
        }
    }
    for (int i = 1; i <= n; i++) add(ans, f[n][i + D]);
    printf("%d\n", ans);
    return 0;
}