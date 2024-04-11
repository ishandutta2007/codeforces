#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n;
    cin >> n;
    --n;
    for (int x = 2; x +1 < n; ++x) {
        int y = n - x;
        if (gcd(x, y) == 1) {
            cout << x << ' ' << y << " 1\n";
            return;
        }
    }
}