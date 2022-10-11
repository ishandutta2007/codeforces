#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto &x : h)
        cin >> x;

    while (true) {
        int pos = 0;
        while (pos < n - 1 && h[pos] >= h[pos + 1])
            pos++;
        if (pos == n - 1)
            break;
        int del = min(h[pos + 1] - h[pos], pos == 0 ? (int) 1e9 : h[pos - 1] - h[pos] + 1);
        if (k <= del)
            return cout << pos + 1 << '\n', void();
        k -= del;
        h[pos] += del;
    }
    cout << "-1\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}