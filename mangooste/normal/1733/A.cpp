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
    int n, k;
    cin >> n >> k;
    vector<int> mx(k);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx[i % k] = max(mx[i % k], x);
    }
    cout << accumulate(all(mx), 0ll) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}