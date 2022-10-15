#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// const int MOD = 1e9 + 7;
const int MOD = 998244353;
 
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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll l = -1, r = 3e12;
    using pp = pair<ll, int>;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        std::priority_queue<pp, std::vector<pp>, std::greater<pp>> setik;
        for (int i = 0; i < n; i++) {
            setik.push({a[i] / b[i], i});
        }
        vector<int> cnt(n);
        bool ok = true;
        for (int i = 0; i < k; i++) {
            auto [t, pos] = setik.top();
            if (t < i) {
                ok = false;
                break;
            }
            setik.pop();
            cnt[pos]++;
            setik.push({(a[pos] + mid * cnt[pos]) / b[pos], pos});
        }
        if (ok) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == 3e12) {
        r = -1;
    }
    cout << r << endl;
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