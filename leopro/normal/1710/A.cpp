#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) cin >> a[i];
    ll h = 0, v = 0;
    bool oh = false, ov = false;
    for (int i = 0; i < k; ++i) {
        if (a[i] / n != 1) h += a[i] / n * n, oh |= a[i] / n >= 3;
        if (a[i] / m != 1) v += a[i] / m * m, ov |= a[i] / m >= 3;
    }
    cout << (h >= n * 1LL*m && (oh || m % 2 == 0) || v >= n * 1LL*m && (ov || n % 2 == 0) ? "YES" : "NO") << '\n';
}