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
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cnt[x - 1]++;
    }

    auto solve = [&](int val) {
        ll possib = 0, extra = 0;
        for (int i = 0; i < n; i++) {
            int take = min(val, cnt[i]);
            possib += (val - take) / 2;
            extra += cnt[i] - take;
        }
        return possib >= extra;
    };

    int l = 0, r = m;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        (solve(mid) ? r : l) = mid;
    }
    cout << r << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}