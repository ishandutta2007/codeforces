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

const int N = 2e5 + 5;

ll f[N], fr[N];

void precalc() {
    f[0] = fr[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % MOD;
        fr[i] = binpow(f[i], MOD - 2);
    }
}

ll cnk(int n, int k) {
    return f[n] * fr[k] % MOD * fr[n - k] % MOD;
}

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    ll x = n / 2;
    ll y = n - x;
    ll ans = 0;
    
    ll cnt = min(r - n, 1 - l);
    ans = (ans + cnt * cnk(n, x)) % MOD;
    if (x != y) {
        ans = (ans + cnt * cnk(n, y)) % MOD;
    }
    for (ll i = cnt + 1; i <= r - x; i++) {
        ll pref = min(n, r - i);
        ll suf = min(n, n - i - l + 1);
        // cout << i << ' ' << pref << ' ' << suf << endl;
        if (pref < x || suf < y) break;
        ll mid = (pref + suf - n);
        ans = (ans + cnk(mid, pref - x)) % MOD;
    }
    if (x != y) {
        swap(x, y);
        for (ll i = cnt + 1; i <= r - x; i++) {
            ll pref = min(n, r - i);
            ll suf = min(n, n - i - l + 1);
            if (pref < x || suf < y) break;
            ll mid = (pref + suf - n);
            ans = (ans + cnk(mid, pref - x)) % MOD;
        }
    }
    cout << ans << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    precalc();
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}