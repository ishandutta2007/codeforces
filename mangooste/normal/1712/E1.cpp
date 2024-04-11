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
    int l, r;
    cin >> l >> r;
    r++;

    const int FIRST = 2 * l, SECOND = (5 * l + 1) / 2;
    ll ans = 0;
    vector<int> divs(r);
    for (int i = l; i < r; i++) {
        for (int j = 2 * i; j < r; j += i) divs[j]++;
        ans += 1ll * divs[i] * (divs[i] - 1) / 2;

        int x = 2 * i;
        ans += x % 3 == 0 && x % 4 == 0 && i >= FIRST;
        ans += x % 3 == 0 && x % 5 == 0 && i >= SECOND;
    }

    int length = r - l;
    ll tot = 1ll * length * (length - 1) * (length - 2) / 6;
    cout << tot - ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}

/*
a<b<c
L = lcm(a, b, c)
L < a+b+c =>
    1. L=c
    2. L=2c, a+b>c
L=c => a+b<c => cases do not intersect
L=2c => b=2c/3, (a=c/2 or a=2c/5)
*/