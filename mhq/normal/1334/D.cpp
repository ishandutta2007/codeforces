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
        int n;
        ll l, r;
        cin >> n >> l >> r;
        if (l <= 2 * (n - 1)) {
            for (ll i = l; i <= min(r, 2LL * (n - 1)); i++) {
                if (i % 2 == 1) cout << 1 << " ";
                else cout << (i + 2) / 2 << " ";
            }
            l = max(l, 2LL * (n - 1) + 1);
        }
        if (l > r) {
            cout << '\n';
            continue;
        }
        ll cur = 2 * n - 1;
        for (ll i = 2; i < n; i++) {
            ll from = cur;
            ll to = cur + 2 * (n - i) - 1;
            ll c_l = max(from, l);
            ll c_r = min(to, r);
            if (c_l > c_r) {
                cur = to + 1;
                continue;
            }
            for (ll j = c_l; j <= c_r; j++) {
                if ((j - from) % 2 == 0) cout << i << " ";
                else {
                    cout << i + ((j - from + 1) / 2) << " ";
                }
            }
            cur = to + 1;
        }
        if (r == 1LL * n * (n - 1) + 1) cout << 1 << " ";
        cout << '\n';

    }
    return 0;
}