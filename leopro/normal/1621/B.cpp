#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n;
    cin >> n;
    set<int> ints;
    map<int, int> minCost;
    auto relax = [&](int x, int c) {
        if (minCost.find(x) == minCost.end()) minCost[x] = c; else minCost[x] = min(minCost[x], c);
    };
    int len = -1, cost = 0;
    for (int i = 0; i < n; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        if (len < r - l) {
            len = r - l;
            cost = c;
        }
        if (len == r - l) {
            cost = min(cost, c);
        }
        ints.insert(l);
        ints.insert(r);
        relax(l, c);
        relax(r, c);
        int mn = *ints.begin();
        int mx = *--ints.end();
        int ans = minCost[mn] + minCost[mx];
        if (mx - mn == len) ans = min(ans, cost);
        cout << ans << '\n';
    }
}