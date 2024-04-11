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
    int n, m;
    cin >> n >> m;
    if (n > m) {
        cout << "No\n";
        return;
    }

    if (n % 2 || m == n) {
        cout << "Yes\n";
        for (int i = 0; i < n - 1; i++) {
            cout << 1 << ' ';
        }
        cout << m - (n - 1) << '\n';
    } else {
        if (m % 2 != n % 2) {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        for (int i = 0; i < n - 2; i++) {
            cout << 1 << ' ';
        }
        m -= n - 2;
        cout << m / 2 << ' ' << m / 2 << '\n';
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