#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
    #define dprint(...)
#endif // LOCAL

void solve(int test_num) {
    int n, k;
    cin >> n >> k, k--;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    cout << ([&]() -> bool {
        if (a[k] < 0) return false;
        if (k == 0 || k == n - 1) return true;

        vector<pair<ll, ll>> path_right, path_left;
        for (int rot = 0; rot < 2; rot++, k = n - 1 - k, reverse(all(a))) {
            auto &cur = rot == 0 ? path_right : path_left;
            vector<ll> pref(n);
            for (int i = 0; i < n; i++) {
                pref[i] = (i == 0 ? 0 : pref[i - 1]) + a[i];
            }
            ll mn = LLONG_MAX;
            for (int i = k + 1, last = k; i < n; i++) {
                mn = min(mn, pref[i]);
                if (pref[i] >= pref[last] || i == n - 1) {
                    cur.emplace_back(mn - pref[last], pref[i] - pref[last]);
                    mn = LLONG_MAX;
                    last = i;
                }
            }
        }
        assert(!path_left.empty() && !path_right.empty());

        ll sum = a[k];
        for (int i = 0, j = 0; i < len(path_left) && j < len(path_right);) {
            assert(i < len(path_left) && j < len(path_right));
            if (path_left[i].first + sum >= 0) {
                sum += path_left[i].second;
                i++;
            } else if (path_right[j].first + sum >= 0) {
                sum += path_right[j].second;
                j++;
            } else {
                return false;
            }
        }
        return true;
    }() ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}