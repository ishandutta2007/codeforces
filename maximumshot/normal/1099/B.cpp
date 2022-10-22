#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

ll get(ll lh, ll rh) { // [lh, rh], lh > rh
    return (lh + rh) * (lh - rh + 1) / 2;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll n;

    cin >> n;

    ll res = inf64;

    for(ll a = 1;a * a <= n;a++) {
        ll b = (n + a - 1) / a;
        res = min(res, a + b);
    }

    cout << res << "\n";

    return 0;
}