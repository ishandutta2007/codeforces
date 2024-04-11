#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const ll mo = 1000000000039ll, base = 9971;
const int N = 2005, M = 205 ;
using namespace std ;

int n, m;

map<ll,int> f; 
char a[N][M], b[M][N] ;

int main() {
    scanf("%d%d", &n, &m) ;
    rep(i, 1, n) scanf("%s", a[i] + 1) ;
    rep(i, 1, m) scanf("%s", b[i] + 1) ;
    rep(k, 1, n - m + 1) {
        ll res = 0 ;
        rep(i, k, k + m - 1) rep(j, 1, m) {
            res = ((ll) res * base + (a[i][j] - 'a' + 1)) % mo ;
        }
        f[res] = k ;
    }
    rep(k, 1, n - m + 1) {
        ll res = 0 ;
        rep(i, 1, m) rep(j, k, k + m - 1) {
            res = ((ll) res * base + (b[i][j] - 'a' + 1)) % mo ;
        }
        if (f.count(res)) {
            printf("%d %d\n", f[res], k) ;
            return 0 ;
        }
    }
    return 0 ;
}