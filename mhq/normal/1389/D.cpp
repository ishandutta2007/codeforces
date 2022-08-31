#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        ll n, k;
        cin >> n >> k;
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ll already = max(0LL, min(r1, r2) - max(l1, l2));
        ll can = max(r1, r2) - min(l1, l2) - already;
        k -= already * n;
        ll dist = 0;
        if (r1 <= l2) dist = l2 - r1;
        if (r2 <= l1) dist = l1 - r2;
        assert(dist >= 0);
        if (k <= 0) {
            cout << 0 << '\n';
        }
        else {
            ll best = 3e18;
            for (ll cnt_d = 1; cnt_d <= n; cnt_d++) {
                ll pay = cnt_d * dist;
                ll free = min(k, can * cnt_d);
                ll to_add = 2 * (k - free);
                best = min(best, pay + free + to_add);
            }
            cout << best << '\n';
        }
    }
    return 0;
}