#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 +  10 ;
using ll = long long ;
ll c(int x) {
    return (1LL * x * (x + 1) ) / 2LL;
}
ll const inf = 1e17;
ll brute(int x, int y) {
    if (y == 0) return c(x);
    if(y >= x) return x;
    ll res = inf;
    for (int i = 1 ; i <= x ; i ++) {
        res = min(res, brute(x - i, y - 1) + c(i));
    }
    return res;
}


int main () {
    int T;
    for(scanf("%d", &T) ; T -- ;) {
        int n, m;
        scanf("%d %d", &n, &m);
        int res = n - m ;
        int par = m + 1;
        if (m == 0) {
            printf("0\n");
            continue;
        }
        if (m >= (n + 1) / 2) {
            ll ans = c(n);
            ans -= (n - m);
            printf("%lld\n", ans);
            continue;
        }
        int sz = res / (par);
        int ret = res % par;
        ll ans = c(n);
        ans -= c(sz) * (par - ret);
        ans -= c(sz + 1) * ret;
        printf("%lld\n", ans);

    }
}
/*
    Good Luck
        -Lucina
*/