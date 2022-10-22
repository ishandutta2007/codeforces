#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool isPrime(ll x) {
    for(ll y = 2;y * y <= x;y++) {
        if(x % y == 0) {
            return false;
        }
    }
    return true;
}

ll gcd(ll x, ll y) {
    return x == 0 ? y : gcd(y % x, x);
}

ll get(ll x, ll y) {
    ll my = 0;

    for(ll d = 1;d * d <= x;d++) {
        if(x % d) continue;
        ll k = y / d;
        if(d > 1) my = max(my, k * d);
        k = y / (x / d);
        my = max(my, k * (x / d));
    }

    return my;
}

ll f(ll x, ll y) {
    if(y == 0) return 0ll;
    if(x == 1) return y;
    ll g = gcd(x, y);
    if(g > 1)
        return 1 + f(x / g, y / g - 1);
    else {
        ll my = get(x, y);
        return y - my + f(x, my);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll x, y;

    cin >> x >> y;

    cout << f(x, y) << "\n";

    return 0;
}