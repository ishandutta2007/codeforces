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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<pair<int, int>> ops;
    if (all_of(all(a), [](const int x) { return x % 2; })) {
        for (int i = n - 2; i >= 0; i--) ops.emplace_back(i, n - 1);
    } else {
        const int parity = a[0] % 2;
        int last = n - 1;
        while (a[last] % 2 != parity) last--;
        for (int i = last - 1; i >= 0; i--) {
            if (a[i] % 2 == parity) {
                ops.emplace_back(i, last);
            }
        }
        for (int i = 1; i < n; i++) {
            if (a[i] % 2 != parity) {
                ops.emplace_back(0, i);
            }
        }
    }

    assert(len(ops) <= n);
    cout << len(ops) << '\n';
    for (auto [i, j] : ops) {
        cout << i + 1 << ' ' << j + 1 << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}