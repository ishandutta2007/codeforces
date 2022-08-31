#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N = 1005 ;
using namespace std ;

int n, d[N] ;

int main() {
    scanf("%d", &n) ;
    int x, y, ans = 0 ;
    rep(i, 1, n - 1) {
        scanf("%d%d", &x, &y) ;
        ++ d[x], ++ d[y] ;
    }
    rep(i, 1, n) ans += (d[i] == 1) ;
    printf("%d\n", ans) ;
    return 0 ;
}