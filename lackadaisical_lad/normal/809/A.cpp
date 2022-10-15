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
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
   }
   sort(x.begin(), x.end());
   for (int i = 0; i < n; i++) {
       ans = (ans + x[i] * binpow(2, i)) % MOD;
       ans = (ans - x[i] * binpow(2, n - i - 1) % MOD + MOD) % MOD;
   }
   cout << ans << endl;
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