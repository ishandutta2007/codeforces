#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

ll gcd(ll x, ll y) {
    return !x ? y : gcd(y % x, x);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll a, b, x, y;

    cin >> a >> b >> x >> y;

    ll g = gcd(x, y);

    x /= g;
    y /= g;

    cout << min(a/x, b/y) << "\n";

    return 0;
}