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
    cout << n << '\n';
    vector<int> p(n);
    iota(all(p), 1);
    for (int it = 0;; it++) {
        for (int i = 0; i < n; i++) {
            cout << p[i] << " \n"[i == n - 1];
        }
        if (it == n - 1) break;
        swap(p[0], p[it + 1]);
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