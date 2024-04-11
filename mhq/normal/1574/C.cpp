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
    int n;
    cin >> n;
    vector<ll> a(n);
    ll s = 0;
    for (ll &v : a) {
        cin >> v;
        s += v;
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    while (m--) {
        ll x, y;
        cin >> x >> y;
        int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
        ll best = 2e18;
        if (pos != a.size()) {
            best = min(best, max(x - a[pos], 0LL) + max(y + a[pos] - s, 0LL));
        }
        if (pos != 0) {
            pos--;
            best = min(best, max(x - a[pos], 0LL) + max(y + a[pos] - s, 0LL));
        }
        pos = upper_bound(a.begin(), a.end(), s - y) - a.begin();
        if (pos != a.size()) {
            best = min(best, max(x - a[pos], 0LL) + max(y + a[pos] - s, 0LL));
        }
        if (pos != 0) {
            pos--;
            best = min(best, max(x - a[pos], 0LL) + max(y + a[pos] - s, 0LL));
        }
        cout << best << '\n';
    }

    return 0;
}