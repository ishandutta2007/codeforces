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
    int n, x;
    cin >> n >> x;
    vector<int> a(2 * n);
    for (auto &x : a) cin >> x;
    sort(all(a));

    bool ok = true;
    for (int i = 0; i < n; i++) {
        ok &= a[i] + x <= a[i + n];
    }
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}