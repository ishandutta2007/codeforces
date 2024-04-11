#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

const ll INF = 1ll << 62;

ll solve(ll f, ll t, ll t0, ll a1, ll t1, ll p1, ll a2, ll t2, ll p2) {
    ll ans = INF;

    for (int i = 0; i <= f / a1; ++i) {
        ll cost = p1 * i;

        ll left_f = f - a1 * i;
        ll left_t = t - t1 * a1 * i;

        ll buy = left_f;

        left_t -= left_f * t2;
        if (left_t < 0) {
            continue;
        }

        ll debuy = buy;

        if (t2 != t0) {
            debuy = left_t / (t0 - t2);
        }

        buy -= min(buy, debuy);

        cost += (buy + a2 - 1) / a2 * p2;

        ans = min(ans, cost);
    }

    return ans;
}

int main() {
#ifdef PAUNSVOKNO
    freopen("in", "r", stdin); cout.tie(nullptr);
    cout.setf(ios::fixed); cout.precision(20); ios_base::sync_with_stdio(false);
#endif
    ll f, t, t0, a1, t1, p1, a2, t2, p2;
    cin >> f >> t >> t0 >> a1 >> t1 >> p1 >> a2 >> t2 >> p2;

    t1 = min(t1, t0);
    t2 = min(t2, t0);

    ll ans = min(solve(f, t, t0, a1, t1, p1, a2, t2, p2),
                 solve(f, t, t0, a2, t2, p2, a1, t1, p1));

    if (ans < INF) {
        cout << ans << "\n";
    } else {
        cout << -1 << "\n";
    }
}