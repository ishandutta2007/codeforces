#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll n;
int m;
const int maxN = 4e5 + 20;
ll a[maxN];
ll p[maxN];
ll k;
ll fMin(ll x) {
    ll c = 0;
    for (int i = 1; i <= m; i++) {
        c += (a[i] / x);
    }
    return c;
}
ll fMax(ll x) {
    ll c = 0;
    for (int i = 1; i <= m; i++) {
        c += (a[i] + x - 1) / x;
    }
    return c;
}
ll sufMin[maxN];
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
        a[i] = p[i] - p[i - 1];
    }
    a[m + 1] = n - p[m];
    m++;
    k += m;
    ll l = 1;
    ll r = *min_element(a + 1, a + m + 1) + 1;
    while (r - l > 1) {
        ll mid = (r + l) / 2;
        if (fMin(mid) >= k) l = mid;
        else r = mid;
    }
    ll X = l;
    l = 0;
    r = *max_element(a + 1, a + m + 1) + 1;
    while (r - l > 1) {
        ll mid = (r + l) / 2;
        if (fMax(mid) <= k) r = mid;
        else l = mid;
    }
    ll Y = r;
    vector < pair < ll, ll > > all;
    for (int i = 1; i <= m; i++) {
        if (a[i] / X >= (a[i] + Y - 1) / Y) continue;
        ll c1 = a[i] / X + 1;
        assert(a[i] / c1 < X);
        assert((a[i] + c1 - 2) / (c1 - 1) > Y);
        all.emplace_back((a[i] + c1 - 2) / (c1 - 1), a[i] / c1);
    }
    sort(all.begin(), all.end());
    sufMin[all.size()] = X;
    for (int i = (int)all.size() - 1; i >= 0; i--) {
        sufMin[i] = min(sufMin[i + 1], all[i].second);
    }
    ll best = 1e18;
    for (int cnt = 0; cnt <= all.size(); cnt++) {
        ll hi = (cnt == 0 ? Y : all[cnt - 1].first);
        ll lo = sufMin[cnt];
        best = min(best, hi - lo);
    }
    cout << best << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}