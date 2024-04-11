#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<vector<int>> a(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        a[i][i] = p[i];
    }
    for (int i = 0; i < n; i++) {
        int x = i;
        int y = i;
        int cnt = p[i] - 1;
        while (cnt--) {
            if (y && a[x][y - 1] == -1) {
                y--;
            } else if (x + 1 < n && a[x + 1][y] == -1) {
                x++;
            } else {
                cout << "-1\n";
                return;
            }
            a[x][y] = p[i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << a[i][j] << " \n"[j == i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}