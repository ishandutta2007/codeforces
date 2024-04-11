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
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    assert(is_sorted(all(a)));
    assert(is_sorted(all(b)));

    for (int i = 0; i < n; i++)  {
        int pos = lower_bound(all(b), a[i]) - b.begin();
        cout << b[pos] - a[i] << " \n"[i == n - 1];
    }

    vector<int> mx(n);
    for (int i = n - 1, last = n - 1; i >= 0; i--) {
        if (i + 1 < n && a[i + 1] > b[i]) last = i;
        mx[i] = b[last] - a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << mx[i] << " \n"[i == n - 1];
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