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
    int n;
    cin >> n;
    if (n % 3 == 0) {
        cout << n / 3 << '\n';
    } else if (n % 3 == 2) {
        cout << n / 3 + 1 << '\n';
    } else {
        int ans = n / 3 + 2;
        for (int take2 = 1; take2 * 2 <= n && take2 <= 6; take2++) {
            int left = n - 2 * take2;
            if (left % 3 == 0) ans = min(ans, take2 + left / 3);
            else if (left % 3 == 2) ans = min(ans, take2 + left / 3 + 1);
        }
        cout << ans << '\n';
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