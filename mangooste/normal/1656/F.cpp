#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));

    ll sum = accumulate(all(a), 0ll);
    if (1ll * (n - 1) * a[0] + (sum - a[0]) > 0 || 1ll * (n - 1) * a[n - 1] + (sum - a[n - 1]) < 0) {
        cout << "INF\n";
        return;
    }

    ll ans = -1ll * a[0] * a[0] * (n - 1);
    ll sum_pos = sum - 1ll * n * a[0], sum_neg = 0;
    for (int i = 0; i < n - 1; i++) {
        ll d = i == 0 ? 0 : -a[i] + a[i - 1];
        sum_pos += 1ll * (n - i) * d;
        sum_neg += 1ll * i * d;
        ll cur =  sum_neg * (a[n - 1] - a[i]) + (sum_pos - (a[n - 1] - a[i])) * (a[0] - a[i]);
        cur -= 1ll * (n - 1) * a[i] * a[i];
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}