#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    while (!a.empty() && !b.empty()) {
        if (a.back() == b.back()) {
            a.pop_back();
            b.pop_back();
        } else
            break;
    }
    if (b.size() == 1)
        if (count(a.begin(), a.end(), b[0]))
            b.pop_back();
    if (b.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}