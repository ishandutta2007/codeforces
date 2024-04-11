#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "/home/lesha/codes/Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, l, r) for (int i = int(l); i < int(r); i++)

const int N = 2'000'00 + 22;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn (i, 0, n) cin >> a[i];

    if (accumulate(all(a), 0ll) + 1 - 2 * n < k) {
        cout << -1 << '\n';
        return 0;
    }

    sort(all(a));
    reverse(all(a));

    auto can = [&](int dep) -> bool {
        ll all = 1;
        int where = 0;
        vector<int> f(N, 0);
        f[0] = 1;
        f[1] = -1;
        for (auto ln : a) {
            while (where < N && !f[where]) {
                where++;
                if (where != N) f[where] += f[where - 1];
            }
            if (where >= dep) return false;
            where++;

            f[where - 1]--;
            f[where]++;
            all--;

            if (2 * (dep - where) <= ln - 1) {
                all += 2 * (dep - where);
                f[where + 1] += 2;
                f[dep + 1] -= 2;
            } else {
                all += ln - 1;
                f[where + 1] += 2;
                f[where + 1 + (ln - 1) / 2] -= 2;
                if ((ln - 1) % 2) {
                    f[where + 1 + (ln - 1) / 2]++;
                    f[where + 1 + (ln - 1) / 2 + 1]--;
                }
            }

            where--;
            if (all >= k) return true;
        }
        return false;
    };

    int l = 0, r = int(2e9);
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (can(mid)) r = mid;
        else l = mid;
    }

    assert(r != int(2e9));
    cout << r << '\n';
}