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
#endif // LOCAL

void solve(int test_num) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    if (k == n) {
        cout << int(1e9) << '\n';
        return;
    }

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](const int i, const int j) {
        return a[i] < a[j];
    });

    multiset<int, greater<>> st1, st2;
    auto update = [&](int pos, bool remove) {
        if (pos >= n - 1 || pos < 0) return;
        int val1 = min(a[pos], a[pos + 1]);
        int val2 = max(a[pos], a[pos + 1]);
        if (remove) {
            st1.erase(st1.find(val1));
            st2.erase(st2.find(val2));
        } else {
            st1.insert(val1);
            st2.insert(val2);
        }
    };
    for (int i = 0; i < n - 1; i++) update(i, false);

    int ans = 0;
    for (int it = 0; auto i : ord) {
        if (it > k) break;

        int ops_left = k - it++;
        if (ops_left == 0) {
            ans = max(ans, min(2 * a[i], *st1.begin()));
        } else if (ops_left == 1) {
            ans = max(ans, min(2 * a[i], *st2.begin()));
        } else {
            ans = max(ans, min(2 * a[i], int(1e9)));
        }

        update(i, true);
        update(i - 1, true);
        a[i] = 1e9;
        update(i, false);
        update(i - 1, false);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}