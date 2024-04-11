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

ll calc(vector<ll> a) {
    ll res = 0;
    ll cur = 0;
    ll k = -1;
    for(int i = 0;i < (int)a.size();i++) {
        cur += a[i];
        if(cur < 0) {
            cur = 0;
            k = i;
        }
        res = max(res, cur * (i - k));
    }
    return res;
}

ll slow(vector<ll> a) {
    ll res = -inf64;
    for(int l = 0;l < (int)a.size();l++) {
        ll cur = 0;
        for(int r = l;r < (int)a.size();r++) {
            cur += a[r];
            res = max(res, cur * (r - l + 1));
        }
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll k;

    cin >> k;

    vector<ll> a;

    ll C = 1998;
    ll S = k + C + 1;

    a.push_back(-1);

    for(ll i = 0;i < C;i++) {
        ll x = min(1000000ll, S);
        a.push_back(x);
        S -= x;
    }

    cout << (int)a.size() << "\n";

    for(ll x : a) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}