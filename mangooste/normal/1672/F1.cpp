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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](const int i, const int j) {
        return a[i] < a[j];
    });

    vector<int> freq(n + 1);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
        mx = max(mx, freq[a[i]]);
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        int j = (i + mx) % n;
        ans[ord[j]] = a[ord[i]];
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}