#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int len = (n - k) / 2 + 1;
    string s(len, '0');
    s.back() = '1';
    for (int i = 0; i < n; i++)
        cout << s[i % len];
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}