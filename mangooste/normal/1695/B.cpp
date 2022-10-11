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
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    array<ll, 2> mn;
    mn.fill(LLONG_MAX);
    for (int i = 0; i < n; i++) {
        mn[i % 2] = min(mn[i % 2], 1ll * a[i] * n + i);
    }

    if (n % 2 || mn[0] > mn[1]) {
        cout << "Mike\n";
    } else {
        cout << "Joe\n";
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