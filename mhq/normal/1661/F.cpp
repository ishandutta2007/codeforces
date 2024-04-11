#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
ll a[maxN];
ll m;
vector<ll> d;
ll get(ll d, ll t) {
    ll a = (d / t);
    return (t * a * a + (2 * a + 1) * (d % t));
}
ll S;
pair<ll,ll> check(ll r) {
    ll cnt = 0;
    ll s = 0;
    for (auto& t : d) {
        ll L = 0;
        ll R = t + 1;
//        if (get(t, 1) - get(t, 2) < r) {
//            s += get(t, 1);
//            continue;
//        }
        while (R - L > 1) {
            ll MID = (L + R) / 2;
            if (get(t, MID) - get(t, MID + 1) >= r) {
                L = MID;
            }
            else {
                R = MID;
            }
        }
        cnt += L;
        s += get(t, L + 1);
    }
    return {s, cnt};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    S = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d.emplace_back(a[i] - a[i - 1]);
        S += (d.back() * d.back());
    }
    cin >> m;
    if (S <= m) {
        cout << 0;
        return 0;
    }
    ll l = 1;
    ll r = 1e18 + 228;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        auto res = check(mid);
        if (res.first <= m) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    auto res = check(r);
    assert(res.first > m);
    ll need = (res.first - m + l - 1) / l;
    cout << (res.second + need) << '\n';

    return 0;
}