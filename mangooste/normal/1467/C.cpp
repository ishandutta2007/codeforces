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

inline int getBit(int mask, int bit) {
    return (mask >> bit) % 2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 3> n;
    for (int i = 0; i < 3; i++) {
        cin >> n[i];
        assert(n[i]);
    }
    array<vector<int>, 3> a;
    for (int i = 0; i < 3; i++) {
        a[i].resize(n[i]);
        for (auto &x : a[i]) {
            cin >> x;
        }
        sort(all(a[i]));
    }

    ll ans = LLONG_MIN;
    for (int root = 0; root < 3; root++) {
        for (int second = 0; second < 8; second++) {
            if (getBit(second, root)) continue;

            ll curAns = 0;
            curAns += a[root].back();
            for (int i = 0; i < 3; i++) {
                if (getBit(second, i)) curAns -= a[i][0];
            }

            int popcnt = __builtin_popcount(second);
            bool ok = true;
            for (int i = 0; i < 3 && ok; i++) {
                for (int j = getBit(second, i); j < n[i] - (i == root) && ok; j++) {
                    if (popcnt - getBit(second, i)) curAns += a[i][j];
                    else if (i != root) curAns -= a[i][j];
                    else ok = false;
                }
            }
            if (ok) ans = max(ans, curAns);
        }
    }
    assert(ans != LLONG_MIN);
    cout << ans << '\n';
}