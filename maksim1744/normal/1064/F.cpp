/*
    21.10.2018 14:30:02
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const bool debug = true;

int main(int argc, char const *argv[]) {
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    ll d = (r - l + n) % n + 1;
    if (d > k) {
        cout << -1 << '\n';
        return 0;
    }
    // t * (n + s) + a = k or k + 1
    ll ans = -1;
    // cout << "n = " << n << '\n';
    // cout << "d = " << d << '\n';
    // cout << "k = " << k << '\n';
    if (k / n > n) {
        for (int iii = 0; iii < 2; ++iii) {
            for (ll s = n; s >= iii; --s) {
                ll vl = d + max((ll)iii, s - (n - d));
                ll vr = d + min(s, d);
                // cout << "s = " << s << " : ";
                // cout << "vl = " << vl << ", ";
                // cout << "vr = " << vr << ", ";
                ll tl = (k - vl) / (n + s);
                ll tr = (k - vr + n + s - 1) / (n + s);
                // cout << "tl = " << tl << ", ";
                // cout << "tr = " << tr << '\n';
                if (tl >= tr) {
                    ans = max(ans, s);
                    break;
                }
            }
            ++k;
        }
    } else {
        for (int iii = 0; iii < 2; ++iii) {
            for (ll t = 0; t * n <= k; ++t) {
                if (t == 0) {
                    if (k <= 2 * d) {
                        ans = max(ans, k - d + (n - d));
                    }
                    continue;
                }
                // cout << "-------------\n";
                // cout << "t = " << t << '\n';
                // cout << "k = " << k << '\n';
                // cout << "d = " << d << '\n';
                ll k0 = k;
                k0 -= t * n;
                k0 -= d;
                if (k0 < 0) {
                    continue;
                }
                // k0 = t * b + (t + 1) * a, a <= d, b <= n - d, a + b -> max
                // b = (k0 - a) / t - a
                // t | k0 - a
                // k0 - a = xt
                // a = k0 - xt
                // b = x(t + 1) - k0
                // a + b = x
                // x -> max

                // d >= a = k0 - xt
                // d >= k0 - xt
                // x >= (k0 - d) / t

                // n - d >= b = x(t + 1) - k0
                // n - d >= x(t + 1) - k0
                // x <= (n - d + k0) / (t + 1)

                // a >= 0
                // k0 >= xt
                // x <= k0 / t

                // b >= 0
                // x(t + 1) >= k0
                // x >= k0 / (t + 1)
                // cout << "k0 = " << k0 << '\n';
                ll x1 = max((k0 - d + t - 1) / t, (k0 + t) / (t + 1));
                ll x2 = min((n - d + k0) / (t + 1), k0 / t);
                if (x1 > x2) {
                    continue;
                }
                ll x = x2;
                // cout << "x = " << x << '\n';
                ll a = k0 - x * t;
                ll b = x * (t + 1) - k0;
                if (a < 0 || b < 0) {
                    continue;
                }
                // cout << "a = " << a << '\n';
                if (a == 0 && iii == 1) {
                    if (x1 < x2) {
                        --x;
                        a = k0 - x * t;
                        b = x * (t + 1) - k0;
                    } else {
                        continue;
                    }
                }
                // cout << "b = " << b << '\n';
                ll s = a + b;
                // cout << "s = " << s << '\n';
                ans = max(ans, s);
            }
            ++k;
        }
    }
    cout << ans << '\n';
    return 0;
}