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
    if (n == 1) {
        cout << "0\n";
        return;
    }

    int ans = -1e9;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i] - a[(i + 1) % n]);
    }
    ans = max(ans, *max_element(1 + all(a)) - a[0]);
    ans = max(ans, a[n - 1] - *min_element(all(a) - 1));
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