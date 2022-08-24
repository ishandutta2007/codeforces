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
        ll m, d, w;
        cin >> m >> d >> w;
        ll f = d - 1;
        ll p = __gcd(w, f);
        w /= p;
        m = min(m, d);
        ll small = m / w;
        ll big = (m + w - 1) / w;
        ll cnt_big = m % w;
        ll cnt_small = w - cnt_big;
        ll ans = (cnt_small * (small * (small - 1)) / 2) + (cnt_big * (big * (big - 1)) / 2);
        cout << ans << '\n';
    }
    return 0;
}