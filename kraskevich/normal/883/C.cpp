#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const ll INF = (ll)1e18;

ll t0;
ll size;
ll a1, t1, p1;
ll a2, t2, p2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll max_time = 0;
    cin >> size >> max_time >> t0;
    cin >> a1 >> t1 >> p1;
    cin >> a2 >> t2 >> p2;

    if (t0 * size <= max_time) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = INF;
    for (int i = 0; i < 2; i++) {
        for (int cnt1 = 0; cnt1 <= size / a1 + 1; cnt1++) {
            ll cost1 = p1 * cnt1;
            ll vol1 = min(size, a1 * cnt1);
            ll cur = vol1 * t1;
            if (cur > max_time)
                continue;
            ll rem = size - vol1;
            if (rem * t0 + cur <= max_time) {
                ans = min(ans, cost1);
                continue;  
            }
            if (t2 >= t0)
                continue;
            ll dt = max_time - cur;
            ll up = t0 * rem - dt;
            assert (up > 0);
            ll down = t0 - t2;
            ll x = up / down;
            while (x <= rem && t0 * (rem - x) + t2 * x > dt)
                x++;
            if (x > rem)
                continue;
            ll cnt2 = (x + a2 - 1) / a2;
            ans = min(ans, cost1 + cnt2 * p2);
        }
        swap(a1, a2);
        swap(t1, t2);
        swap(p1, p2);
    }

    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}