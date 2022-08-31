#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N = 15 ;
using namespace std ;

int n ;
char a[N][N], b[N][N], c[N][N], d[N][N] ;

bool chk() {
    rep(i, 0, n - 1) rep(j, 0, n - 1) {
        if (b[i][j] != d[i][j]) return false ;
    }
    return true ;
}

bool solve() {
    rep(i, 0, n - 1) rep(j, 0, n - 1) {
        d[i][j] = c[i][j] ;
    }
    if (chk()) return true ;
    rep(i, 0, n - 1) rep(j, 0, n - 1) {
        d[i][j] = c[j][n - i - 1] ;
    }
    if (chk()) return true ;
    rep(i, 0, n - 1) rep(j, 0, n - 1) {
        d[i][j] = c[n - i - 1][n - j - 1] ;
    }
    if (chk()) return true ;
    rep(i, 0, n - 1) rep(j, 0, n - 1) {
        d[i][j] = c[n - j - 1][i] ;
    }
    if (chk()) return true ;
    return false ;
}

int main() {
    scanf("%d", &n) ;
    rep(i, 0, n - 1) scanf("%s", a[i]) ;
    rep(i, 0, n - 1) scanf("%s", b[i]) ;
    rep(i, 0, n - 1) rep(j, 0, n - 1) {
        c[i][j] = a[i][j] ;
    }
    if (solve()) {
        puts("Yes") ;
        return 0 ;
    }
    rep(i, 0, n - 1) rep(j, 0, n - 1) {
        c[i][j] = a[n - i - 1][j] ;
    }
    if (solve()) {
        puts("Yes") ;
        return 0 ;
    }
    rep(i, 0, n - 1) rep(j, 0, n - 1) {
        c[i][j] = a[i][n - j - 1] ;
    }
    if (solve()) {
        puts("Yes") ;
        return 0 ;
    }
    puts("No") ;
    return 0 ;
}