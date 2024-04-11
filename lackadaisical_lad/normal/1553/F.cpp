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

const int N = 3e5 + 5;

ll f[N];
ll g[N];

void add(ll f[], int pos, ll val) {
    for (; pos < N; pos |= pos + 1) {
        f[pos] += val;
    }
}

ll get(ll f[], int pos) {
    ll res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += f[pos];
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        ans += a * i - get(f, a);
        ans += sum;
        for (int j = a; j < N; j += a) {
            add(f, j, a);
            ans -= a * (i - get(g, j - 1));
        }
        add(g, a, 1);
        sum += a;
        cout << ans << " \n"[i + 1 == n];
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