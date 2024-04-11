#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;

const int MAXN = 200228;
ll a[MAXN];
ll b[MAXN];

const ll INF = (1ll << 40);

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    int n, m, cl, ce, v;
    cin >> n >> m >> cl >> ce >> v;


    a[0] = -INF, b[0] = -INF;
    for (int i = 1; i <= cl; ++i) {
        cin >> a[i];
    }

    a[cl + 1] = b[ce + 1] = INF;

    for (int i = 1; i <= ce; ++i) {
        cin >> b[i];
    }


    int q;
    for (cin >> q; q--;) {
        ll ans = INF;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        swap(x1, y1);
        swap(x2, y2);

        ll dy = abs(y2 - y1);

        if (y1 == y2) {
            ans = abs(x2 - x1);
        } else {
            {
                auto it = lower_bound(a, a + cl + 1, x1);
                ans = min(ans, abs(x1 - *it) + abs(x2 - *it) + dy);
            }

            {
                auto it = lower_bound(a, a + cl + 1, x1) - 1;
                ans = min(ans, abs(x1 - *it) + abs(x2 - *it) + dy);
            }

            {
                auto it = lower_bound(b, b + ce + 1, x1);
                ans = min(ans, abs(x1 - *it) + abs(x2 - *it) + (dy + v - 1) / v);
            }

            {
                auto it = lower_bound(b, b + ce + 1, x1) - 1;
                ans = min(ans, abs(x1 - *it) + abs(x2 - *it) + (dy + v - 1) / v);
            }
        }

        cout << ans << "\n";
    }
}