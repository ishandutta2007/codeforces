#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

ll gcd(ll a, ll b) {
    return !a ? b : gcd(b % a, a);
}

void solve() {
    ll p, q, b;

    scanf("%lld %lld %lld", &p, &q, &b);

    p %= q;

    if(!p) {
        puts("Finite");
        return;
    }

    ll g = gcd(p, q);

    p /= g;
    q /= g;

    while(q > 1) {
        g = gcd(q, b);
        if(g <= 1) {
            puts("Infinite");
            return;
        }
        while(q % g == 0) {
            q /= g;
        }
    }

    puts("Finite");
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    while(n--) {
        solve();
    }

    return 0;
}