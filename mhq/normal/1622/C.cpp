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
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        ll s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        sort(a.begin(), a.end());
        if (s <= k) {
            cout << 0 << '\n';
            continue;
        }
        s -= a[0];
        ll best = 2e18;
        for (int pref = 0; pref <= n - 1; pref++) {
            ll D = s + (pref + 1) * a[0];
            ll need = 0;
            if (D > k) {
                need = (D - k + pref) / (pref + 1);
            }
            best = min(best, pref + need);
            s -= a[n - 1 - pref];
        }
        cout << best << '\n';
    }
    return 0;
}