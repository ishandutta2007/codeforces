#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    auto ok = [&](int x, int y) {
        if (a[x][y]) return false;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int i = x + dx;
                int j = y + dy;
                if (i >= 0 && i < h && j >= 0 && j < w && a[i][j]) {
                    return false;
                }
            }
        }
        return true;
    };
    for (int j = 0; j < w; j++) {
        if (ok(0, j)) {
            a[0][j] = 1;
        }
    }
    for (int i = 0; i < h; i++) {
        if (ok(i, w - 1)) {
            a[i][w - 1] = 1;
        }
    }
    for (int j = w - 1; j >= 0; j--) {
        if (ok(h - 1, j)) {
            a[h - 1][j] = 1;
        }
    }
    for (int i = h - 1; i >= 0; i--) {
        if (ok(i, 0)) {
            a[i][0] = 1;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}