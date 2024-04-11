#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef pair<long double, long double> pdd;

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

    ll n, k;

    cin >> n >> k;

    ll kn = n * k;

    ll a, b;

    cin >> a >> b;

    vector<ll> as, bs;

    as.push_back(a);
    as.push_back((k - a) % k);

    bs.push_back(b);
    bs.push_back((k - b) % k);

    ll x = inf64;
    ll y = -inf64;

    for (ll aa : as) {
        for (ll bb : bs) {
//            cout << "(" << aa << ", " << bb << ")\n";
            for (ll i = 0; i < 2 * n; i++) {
                ll s = aa;
                ll t = i * k + bb;
                ll l = t - s;
//                cout << s << " " << t << "\n";
                while (l <= 0) l += kn;
                ll tmp = kn / gcd(l, kn);
//                cout << "tmp = " << tmp << "\n";
                x = min(x, tmp);
                y = max(y, tmp);
            }
        }
    }

    cout << x << " " << y << "\n";

    return 0;
}