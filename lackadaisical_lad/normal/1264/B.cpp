#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
 
ll binpow(ll a, ll p, int mod = MOD) {
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
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d > c + 1 || a > b + 1) {
        cout << "NO\n";
        return;
    }
    if (a == b + 1 && c + d || d == c + 1 && a + b) {
        cout << "NO\n";
        return;
    }
    int n = a + b + c + d;
    if (n % 2 == 0 && a + c != b + d || n % 2 && abs(a + c - b - d) != 1) {
        cout << "NO\n";
        return;
    }
    vector<int> seq(n);
    if (n % 2) {
        if (a + c > b + d) {
            seq[0] = 0;
        } else {
            seq[0] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        seq[i] = seq[i - 1] ^ 1;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (seq[i]) {
            if (b) {
                b--;
                ans[i] = 1;
            } else {
                d--;
                ans[i] = 3;
            }
        } else {
            if (a) {
                a--;
                ans[i] = 0;
            } else {
                c--;
                ans[i] = 2;
            }
        }
    }
    for (int i = 0; i + 1 < n; i++) {
        if (abs(ans[i] - ans[i + 1]) != 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}