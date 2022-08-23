#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;

const int MAXN = 200228;
ll p[MAXN];
ll a[MAXN];

int n, m;
ll t;


using Pair = pair<int, ll>;

Pair solve(ll x, bool& targ) {
    ll ct = 0;
    ll ls = 0;
    int ans = 0;
    targ = false;

    for (int i = 0; i < n; ++i) {
        if (p[i] <= x) {
            ct += p[i];
            ls += p[i];

            if (ct > t) {
                targ = true;
                return {ans, x};
            }

            ++ans;
            if (ans % m == 0) {
                ct += ls;
                ls = 0;
            }
        }
    }

    return {ans, x};
}

void solve() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        a[i] = p[i];
    }

    
    ll l = 0, r = t;
    bool targ;

    while (l + 1 < r) {
        ll md = (l + r) / 2;
        solve(md, targ);

        if (targ) {
            r = md;
        } else {
            l = md;
        }
    }

    auto bst = max(solve(l, targ), solve(r, targ));
    cout << bst.first << " " << bst.second << "\n";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}