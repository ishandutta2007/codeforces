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
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (int x = n; x >= 1; x--) {
        int first = (l + x - 1) / x * x;
        if (first > r) {
            cout << "NO\n";
            return;
        }
        a[x - 1] = first;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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