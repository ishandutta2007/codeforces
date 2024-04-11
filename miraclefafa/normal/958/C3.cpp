#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int M = 103, N = 2e6 + 5, V = 5e5 + 5, inf = 1e9 + 7 ;
using namespace std ;

bool vis[M][M][M] ;
int n, m, mo, he, ta, a[N], f[M][M][M], nxt[V][M] ;
struct poi {
    int x, y, z ;
} opt[N] ;

void upd(int i, int j, int k, int ave) {
    if (ave > n) return ;
    if (ave < f[i][j][k]) {
        f[i][j][k] = ave ;
        if (vis[i][j][k]) {
            vis[i][j][k] = false ;
            ta = (ta + 1) % N ;
            opt[ta].x = i ;
            opt[ta].y = j ;
            opt[ta].z = k ;
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &mo) ;
    rep(i, 1, n) {
        scanf("%d", &a[i]) ;
        a[i] += a[i - 1] ;
        a[i] %= mo ;
    }
    rep(i, 0, m) rep(j, 0, mo - 1) rep(k, 0, m) {
        f[i][j][k] = n + 1 ;
        vis[i][j][k] = true ;
    }
    rep(i, 0, mo - 1) nxt[n + 1][i] = n + 1 ;
    for (int i = n ; i; -- i) {
        rep(j, 0, mo - 1) nxt[i][j] = nxt[i + 1][j] ;
        nxt[i][a[i]] = i ;
    }
    he = 0, ta = 0 ;
    upd(0, 0, 0, 0) ;
    for ( ; he != ta ; ) {
        he = (he + 1) % N ; 
        int x = opt[he].x, y = opt[he].y, z = opt[he].z ;
        rep(i, 0, mo - 1) {
            int xx, yy, zz ;
            xx = x + 1 ;
            yy = i ;
            zz = z + (yy >= y ? 0 : 1) ;
            upd(xx, yy, zz, nxt[f[x][y][z] + 1][i]) ;
        }
        vis[x][y][z] = true ;
    }
    int ans = inf ;
    rep(i, 0, n) if (f[m][a[n]][i] <= n) {
        ans = min(ans, i * mo + a[n]) ;
    }
    printf("%d\n", ans) ;
    return 0 ;
}