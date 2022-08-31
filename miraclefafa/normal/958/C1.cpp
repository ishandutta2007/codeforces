#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N = 1e5 + 5 ;
using namespace std ;

set <int> S ;
int n, mo, a[N], b[N], c[N] ;

int main() {
    scanf("%d%d", &n, &mo) ;
    rep(i, 1, n) {
        scanf("%d", &a[i]) ;
    }
    rep(i, 1, n) {
        b[i] = (b[i - 1] + a[i]) % mo ;
    }
    for (int i = n ; i; -- i) {
        c[i] = (c[i + 1] + a[i]) % mo ;
    }
    int ans = 0 ;
    rep(i, 1, n - 1) {
        ans = max(ans, b[i] + c[i + 1]) ;
    }
    printf("%d\n", ans) ;
    /*int las = 0 ;
    set <int> :: iterator it ;
    S.insert(0) ;
    rep(i, 1, n) {
        las = (las + a[i]) % mo ;
        it = S.upper_bound(las) ;
        if (it != S.end()) f[i] = mo - (*it) + las ; else 
            f[i] = las ;
        cout << i << " " << f[i] << endl ;
        f[i] = max(f[i], f[i - 1]) ;
        S.insert(las) ;
    }
    int ans = 0, tmp ;
    S.clear() ;
    S.insert(0) ;
    las = 0 ;
    for (int i = n ; i; -- i) {
        las = (las + a[i]) % mo ;
        it = S.upper_bound(las) ;
        if (it != S.end()) tmp = mo - (*it) + las ; else 
            tmp = las ;
        if (i) ans = max(ans, f[i - 1] + tmp) ;
        S.insert(las) ;
    } */
    //printf("%d\n", ans) ;
    return 0 ;
}