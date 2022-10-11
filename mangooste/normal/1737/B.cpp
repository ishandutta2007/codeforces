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
    ll l, r;
    cin >> l >> r;

    auto my_sqrt = [&](ll val) {
        ll x = sqrtl(val);
        x = max(0ll, x);
        while (x * x > val) x--;
        while ((x + 1) * (x + 1) <= val) x++;
        return x;
    };
    
    auto solve = [&](ll r) -> ll {
        if (r == 0) return 0;
        if (r == 1) return 1;

        ll x = my_sqrt(r);
        ll ans = r / x - (x * x - 1) / x;
        ans += 3 * (x - 1);
        return ans;
    };

    cout << solve(r) - solve(l - 1) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}