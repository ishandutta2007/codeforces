#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

using ll = long long;
ll n;
ll l, r;

void solve () {
    scanf("%lld %lld %lld", &n, &l, &r);
    ll f = 0, cur = 1;

    ll old_l = l;
    ll old_r = r;

    if (l % 2 == 0 && l > 1) -- l;
    if (r % 2) ++ r;

    while (f < l) {
        if (cur == n - 1)break;
        if (f + (n - cur) * 2 < l) {
            f += (n - cur) * 2;
            ++ cur;
        } else break;

    }

    ll x = cur, y = cur + (l - f + 1) / 2;

    vector<ll> a;


    for (ll i = l ; i <= r ; i += 2) {
        a.push_back(x);
        a.push_back(y);
        if (y != n) ++ y;
        else {
            ++ x;
            y = x + 1;
        }
    }
    int start = 0, fin = (int)a.size() - 1;
    if (old_l > l) start = 1;
    if (old_r < r) fin -= 1;
    if (old_r == (n) * (n - 1) + 1) a[fin] = 1;
    for (int i = start ; i <= fin ; ++ i)
        printf("%lld ", a[i]);
    printf("\n");
}

int main () {
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }

}
/*
    Good Luck
        -Lucina
*/