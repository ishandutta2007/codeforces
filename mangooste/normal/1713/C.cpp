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
    int x = 0;
    while (x * x < n) x++;

    vector<int> ans(n, -228);
    n--;
    while (n >= 0) {
        while (x >= 0 && x * x >= n) x--;
        x++;
        if (n == 0) x = 0;
        int diff = x * x - n;
        for (int i = diff; i <= n; i++) ans[i] = n - (i - diff);
        n = diff - 1;
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}