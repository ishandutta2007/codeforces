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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < n * 5; i++) {
        a.push_back(100);
        b.push_back(0);
    }
    int m = a.size();
    vector<ll> prefA(m + 1), prefB(m + 1);
    for (int i = 1; i <= m; i++) {
        prefA[i] = prefA[i - 1] + a[i - 1];
        prefB[i] = prefB[i - 1] + b[i - 1];
    }
    for (int i = n; i <= m; i++) {
        ll s = prefA[i] - prefA[i / 4];
        ll t = prefB[i - i / 4];
        if (s >= t) {
            cout << i - n << '\n';
            return;
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