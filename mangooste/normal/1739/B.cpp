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
    vector<int> d(n);
    for (auto &x : d) cin >> x;
    for (int i = 1, val = d[0]; i < n; i++) {
        if (d[i] == 0) continue;
        if (val - d[i] >= 0) {
            cout << "-1\n";
            return;
        }
        val += d[i];
    }

    for (int i = 0; i < n; i++) {
        if (i) d[i] += d[i - 1];
        cout << d[i] << " \n"[i == n - 1];
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