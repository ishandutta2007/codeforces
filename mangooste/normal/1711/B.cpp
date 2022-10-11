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
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> deg(n);
    vector<pair<int, int>> edges(m);
    for (auto &[v, u] : edges) {
        cin >> v >> u;
        v--, u--;
        deg[v]++, deg[u]++;
    }

    if (m % 2 == 0) {
        cout << "0\n";
        return;
    }

    int ans = accumulate(all(a), 0ll);
    for (int i = 0; i < n; i++) {
        if (deg[i] & 1) ans = min(ans, a[i]);
    }
    for (auto &[v, u] : edges) {
        if (deg[v] % 2 == 0 && deg[u] % 2 == 0) {
            ans = min(ans, a[v] + a[u]);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}