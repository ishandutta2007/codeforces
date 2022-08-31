#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#ifdef DEBUG
#define i128 long long
#else
#define i128 __int128
#endif
ll mod;
ll mult(ll a, ll b) {
    ll q = (long long)((long double)a * (long double)b / (long double)mod);
    long long r = a * b - q * mod;
    while (r < 0) r += mod;
    return r % mod;
}
ll sum(ll a, ll b) {
    ll s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
ll sub(ll a, ll b) {
    ll s = a - b;
    if (s < 0) s += mod;
    return s;
}
ll pw(ll a, ll b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    ll res = pw(a, b / 2);
    return mult(res, res);
}
int m;
ll t;
const int maxN = 20;
ll e[(1 << maxN) + 2];
int bits[(1 << maxN) + 2];
ll c[(1 << maxN) + 2];
int b[maxN + 1];
ll mm;
void xr(ll* x, bool inv) {
    // a0 + a1, a0 - a1
    for (int bit = 0; bit < m; bit++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            if (mask & (1 << bit)) {
                ll u = x[mask];
                ll v = x[mask ^ (1 << bit)];
                x[mask ^ (1 << bit)] = sum(v, u);
                x[mask] = sub(v, u);
            }
        }
    }
    if (inv) {
        for (int i = 0; i < (1 << m); i++) {
            assert((x[i] % (1 << m)) == 0);
            x[i] /= (1 << m);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> m >> t >> mod;
    mm = mod;
    mod *= (1 << m);
    for (int i = 0; i < (1 << m); i++) {
        cin >> e[i];
        e[i] %= mod;
    }
    for (int i = 0; i <= m; i++) {
        cin >> b[i];
    }
    c[0] = b[0];
    for (int i = 1; i < (1 << m); i++) {
        bits[i] = bits[i / 2] + (i & 1);
        c[i] = b[bits[i]];
    }
    xr(e, false);
    xr(c, false);
    for (int i = 0; i < (1 << m); i++) {
        c[i] = pw(c[i], t);
    }
    for (int i = 0; i < (1 << m); i++) {
        e[i] = mult(e[i], c[i]);
    }
    xr(e, true);
    for (int i = 0; i < (1 << m); i++) {
        cout << (e[i] % mm) << '\n';
    }
    return 0;
}