#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int mxx = *max_element(all(x));
    int mnx = *min_element(all(x));
    int mxy = *max_element(all(y));
    int mny = *min_element(all(y));

    int ans3 = 0;
    for (int i = 0; i < n; i++) {
        ans3 = max(ans3, max(mxx - x[i], x[i] - mnx) + max(mxy - y[i], y[i] - mny));
    }
    cout << 2 * ans3;
    for (int i = 4; i <= n; i++) {
        cout << ' ' << 2 * (mxx - mnx + mxy - mny);
    }
    cout << '\n';
}