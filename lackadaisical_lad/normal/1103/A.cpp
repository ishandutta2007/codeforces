#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int cntV = 0;
    int cntH = 0;
    for (char c : s) {
        if (c == '0') {
            cout << 1 + cntV * 2 << ' ' << 1 << '\n';
            cntV = (cntV + 1) % 2;
        } else {
            cout << 1 + cntH << ' ' << 2 << '\n';
            cntH = (cntH + 1) % 4;
        }
    }
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