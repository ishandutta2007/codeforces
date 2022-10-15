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
    ll A, cf, cm, m;
    cin >> n >> A >> cf >> cm >> m;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        m -= A - a[i].first;
        a[i].second = i;
    }
    if (m >= 0) {
        cout << cf * n + cm * A << endl;
        for (int i = 0; i < n; i++) {
            cout << A << " \n"[i + 1 == n];
        }
        return;
    }
    sort(a.rbegin(), a.rend());
    ll best = 0;
    int j = n - 1;
    ll cur = 0;
    int pos = 0;
    ll rem = 0;
    int govno = n;
    for (int i = n - 1; i >= 0; i--) {
        m += A - a[i].first;
        while (j > i) {
            if ((a[j - 1].first - a[j].first) * (n - j) <= m) {
                m -= (a[j - 1].first - a[j].first) * (n - j);
                j--;
            } else {
                break;
            }
        }
        if (m >= 0) {
            ll val = cf * i + cm * min(A, a[j].first + m / (n - j)); 
            if (val > best) {
                best = val;
                pos = i;
                rem = m;
                govno = j;
            }
        }
    }
    vector<ll> val(n);
    for (int i = 0; i < pos; i++) {
        val[a[i].second] = A;
    }
    for (int i = pos; i < govno; i++) {
        val[a[i].second] = a[i].first;
    }
    for (int i = govno; i < n; i++) {
        val[a[i].second] = min(A, a[govno].first + rem / (n - govno)); 
    }
    cout << best << endl;
    for (int i = 0; i < n; i++) {
        cout << val[i] << " \n"[i + 1 == n];
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