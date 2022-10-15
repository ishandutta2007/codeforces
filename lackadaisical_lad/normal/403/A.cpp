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
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ' ' << (i + 1) % n + 1 << '\n';
    }
    p += n;
    for (int i = 0; i < n && p; i++) {
        for (int j = i + 2; j < n && p; j++) {
            if (j - i == n - 1) continue;
            cout << i + 1 << ' ' << j + 1 << '\n';
            p--;
        }
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