#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N = 2e4 + 5, M = 105, inf = 1e9 + 7 ;
using namespace std ;

int n, m, mo, a[N], f[N][55], g[55][M] ;

int main() {
    scanf("%d%d%d", &n, &m, &mo) ;
    rep(i, 1, n) {
        scanf("%d", &a[i]) ;
        a[i] += a[i - 1] ;
        a[i] %= mo ;
    }
    rep(i, 0, m) rep(j, 0, mo - 1) g[i][j] = - inf ;
    g[0][0] = 0 ;
    rep(i, 1, n) rep(j, 1, min(i, m)) {
        rep(k, 0, mo - 1) {
            f[i][j] = max(f[i][j], g[j - 1][k] + ((a[i] - k + mo) % mo)) ;
        }
        g[j][a[i] % mo] = max(g[j][a[i] % mo], f[i][j]) ;
    }
    printf("%d\n", f[n][m]) ;
    return 0 ;
}