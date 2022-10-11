#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    ll ans = -1;

    auto solve = [&](const vector<int> &b) {
        ll mn = 0, mx = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += b[i];
            mn = min(mn, sum);
            mx = max(mx, sum);
        }
        ans = max(ans, mx - mn + 1);
    };

    if (!count(all(a), 0)) {
        if (accumulate(all(a), 0ll) == 0) {
            solve(a);
        }
        cout << ans << '\n';
        return 0;
    }

    for (int rot : {0, 1}) {
        vector<ll> suf(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (a[i] == 0) suf[i] += k;
        }
        int last = n - 1;
        while (a[last] != 0) last--;

        for (int c = 0; c <= n; c++) {
            ll sum = accumulate(all(a), 0ll);
            auto b = a;
            bool fail = false;

            for (int i = 0; i < c && i < last; i++) {
                if (a[i] != 0) continue;
                ll cur_max = suf[i + 1] - sum;
                cur_max = min<ll>(cur_max, k);
                if (cur_max < -k) {
                    fail = true;
                    break;
                }
                b[i] = cur_max;
                sum += cur_max;
            }
            if (fail) continue;

            for (int i = c; i < n && i < last; i++) {
                if (a[i] != 0) continue;
                ll cur_min = -sum - suf[i + 1];
                cur_min = max<ll>(cur_min, -k);
                if (cur_min > k) {
                    fail = true;
                    break;
                }
                b[i] = cur_min;
                sum += cur_min;
            }

            if (sum < -k || k < sum) {
                fail = true;
            } else {
                b[last] = -sum;
            }
            if (fail) continue;

            solve(b);
        }

        for (auto &x : a) x *= -1;
    }
    cout << ans << '\n';
}