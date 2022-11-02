#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, lbnd, hbnd;

ll sum(ll x) {
    ll ret = 0;
    while (x > 0) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%I64d", &n);
    ll lo = 1, hi = n;
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (mid <= n / mid) lo = mid;
        else hi = mid - 1;
    }
    hbnd = lo + 10;
    lo = 1, hi = n;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (mid + 200 >= n / mid) hi = mid;
        else lo = mid + 1;
    }
    lbnd = max(lo - 10, ll(1));
    for (ll i=lbnd; i<=hbnd; i++) {
        if (i * i + sum(i) * i == n) {
            printf("%I64d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}