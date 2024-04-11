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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (auto &x : a) cin >> x;

    for (int rot = 0; rot < 2; rot++, swap(n, m)) {
        ll tot = 0, can_sub = 0;
        for (auto &x : a) {
            int cur = x / n;
            if (cur <= 1) continue;
            tot += cur;
            can_sub += cur - 2;
        }
        if (tot < m) continue;
        if (tot % 2 != m % 2 && can_sub == 0) continue;
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}