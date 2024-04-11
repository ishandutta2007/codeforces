#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

ll gcd(ll x, ll y) {
    return !x ? y : gcd(y % x, x);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll la, ra, ta;

    cin >> la >> ra >> ta;

    ll lb, rb, tb;

    cin >> lb >> rb >> tb;

    ll df = gcd(ta, tb);
    ll res = 0;

    ll K = (lb - la) / df;

    for(ll k = K - 10;k <= K + 10;k++) {
        res = max(res, max(0ll, min(ra + k * df, rb) - max(la + k * df, lb) + 1));
    }

    cout << res << "\n";

    return 0;
}