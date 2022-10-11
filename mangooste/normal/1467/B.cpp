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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    if (n <= 3) {
        cout << "0\n";
        return;
    }

    int pref = 0;
    int suf = 0;

    auto good = [&](int i) {
        if (i < 1 || i >= n - 1) return false;
        return (a[i] < a[i - 1] && a[i] < a[i + 1]) || (a[i] > a[i - 1] && a[i] > a[i + 1]);
    };
    for (int i = n - 1; i > 1; i--) {
        suf += good(i);
    }

    int mn = n;
    for (int i = 0; i < n; i++) {
        vector<int> values{a[i]};
        if (i) values.push_back(a[i - 1]);
        if (i != n - 1) values.push_back(a[i + 1]);

        for (auto x : values) {
            int prev = a[i];
            a[i] = x;
            mn = min(mn, pref + suf + good(i) + good(i - 1) + good(i + 1));
            a[i] = prev;
        }

        pref += good(i - 1);
        suf -= good(i + 2);
    }
    cout << mn << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}