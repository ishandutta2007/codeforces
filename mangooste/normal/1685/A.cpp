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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));

    if (n & 1) {
        cout << "NO\n";
        return;
    }

    vector<int> b;
    for (int i = 0; i < n / 2; i++) {
        b.push_back(a[i]);
        b.push_back(a[i + n / 2]);
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        int prev = (i + n - 1) % n, nxt = (i + 1) % n;
        ok &= b[i] != b[nxt];
        ok &= (b[prev] < b[i]) == (b[nxt] < b[i]);
    }
    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << b[i] << " \n"[i == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}