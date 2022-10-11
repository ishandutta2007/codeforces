#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    ll sum = accumulate(all(a), 0ll);

    reverse(all(a));
    for (int i = 0; i < n; i++) {
        a[i] -= i;
    }
    sort(all(a));
    reverse(all(a));

    ll ans = sum;
    for (int i = 0; i < k; i++) {
        sum -= a[i];
        sum -= i;
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}