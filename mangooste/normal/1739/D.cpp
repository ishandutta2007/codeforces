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
    vector<int> par(n), dep(n);
    for (int i = 1; i < n; i++) {
        cin >> par[i], par[i]--;
        dep[i] = dep[par[i]] + 1;
    }

    auto solve = [&](int max_depth) {
        auto max_dep = dep;
        int ops = 0;
        for (int i = n - 1; i > 0; i--) {
            if (max_dep[i] <= max_depth) continue;
            if (max_dep[i] - dep[i] == max_depth - 1) {
                ops++;
            } else {
                max_dep[par[i]] = max(max_dep[par[i]], max_dep[i]);
            }
        }
        assert(max_dep[0] <= max_depth);
        return ops <= k;
    };

    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
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