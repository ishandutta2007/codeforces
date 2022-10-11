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
    vector<int> t(n);
    for (auto &x : t) cin >> x;
    vector<int> x(n);
    for (auto &v : x) cin >> v;

    array<vector<int>, 2> a;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i];
        a[t[i]].push_back(x[i]);
    }

    sort(all(a[0]));
    reverse(all(a[0]));
    sort(all(a[1]));
    reverse(all(a[1]));

    int n1 = len(a[0]), n2 = len(a[1]);
    if (n1 > n2) swap(n1, n2), swap(a[0], a[1]);
    
    if (n1 == n2) {
        dbg("here");
        cout << 2 * sum - min(a[0].back(), a[1].back()) << '\n';
    } else {
        ll ans = sum + accumulate(all(a[0]), 0ll);
        dbg(a[0], a[1], n1,  n2);
        assert(len(a[1]) >= n1 + 1);
        for (int i = 0; i < n1; i++) ans += a[1][i];
        cout << ans << '\n';
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