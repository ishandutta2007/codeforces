#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int SQRT = 500;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        auto calc = [&](ld R) -> ld {
            ld maxB = min({ld(x - a * R) / ld(b), ld(y - b * R) / ld(a)});
            if (maxB < 0) maxB = 0;
            return R + maxB;
        };

        auto score = [&](ll R) -> ll {
            ll maxB = min({(x - a * R) / b, (y - b * R) / a});
            if (maxB < 0) maxB = 0;
            return R + maxB;
        };

        ld bl = 0, br = min({ld(x) / ld(a), ld(y) / ld(b)}), bm1, bm2;
        for (int iter = 0; iter < 100; iter++) {
            bm1 = (2 * bl + br) / 3.0;
            bm2 = (bl + 2 * br) / 3.0;
            if (calc(bm1) < calc(bm2)) bl = bm1;
            else br = bm2;
        }

        int DELTA = SQRT + 10;
        ll res = 0;

        for (ll delta = -DELTA; delta <= DELTA; delta++) {
            ll R = max(0ll, ll(bl) + delta);
            if (a * R > x || b * R > y) continue;
            res = max(res, score(R));
        }

        cout << res << "\n";
    }

    return 0;
}