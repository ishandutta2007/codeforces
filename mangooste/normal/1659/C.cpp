#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    for (auto &p : x) cin >> p;

    ll ans = 0;
    for (auto p : x) {
        ans += 1ll * b * p;
    }
    ll cur = 0, sum = accumulate(all(x), 0ll);
    for (int i = 0, last = 0; i < n; i++) {
        cur += 1ll * (a + b) * (x[i] - last);
        last = x[i];
        sum -= x[i];
        ans = min(ans, cur + (sum - 1ll * (n - i - 1) * x[i]) * b);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}