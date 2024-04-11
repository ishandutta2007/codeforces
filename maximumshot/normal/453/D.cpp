#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

inline ll _sum(ll a, ll b, ll mod) {
    return a + b < mod ? a + b : a + b - mod;
}

inline ll _sub(ll a, ll b, ll mod) {
    return a >= b ? a - b : a - b + mod;
}

inline ll _mul(ll a, ll b, ll mod) {
    __int128 aa = a;
    __int128 bb = b;
    __int128 mm = mod;
    aa = (aa * bb) % mm;
    return ll(aa);
}

inline ll _binpow(ll x, ll pw, ll mod) {
    ll res = 1, tmp = x;
    while (pw > 0) {
        if (pw & 1)
            res = _mul(res, tmp, mod);
        tmp = _mul(tmp, tmp, mod);
        pw >>= 1;
    }
    return res;
}

void fwht(vector<ll>& a, ll mod) {
    ll x, y;
    for (int len = 1; len < (int) a.size(); len <<= 1) {
        for (int i = 0; i < (int) a.size(); i += len << 1) {
            for (int j = 0; j < len; j++) {
                x = a[i + j];
                y = a[i + j + len];
                a[i + j] = _sum(x, y, mod);
                a[i + j + len] = _sub(x, y, mod);
            }
        }
    }
}

ll pop_count(ll x) {
    ll res = 0;
    while (x) {
        if (x & 1)
            res++;
        x >>= 1;
    }
    return res;
}

vector<ll> solve(ll t, ll mod, vector<ll> e, vector<ll> B) {
    for (ll& x : e)
        x %= mod;
    for (ll& x : B)
        x %= mod;
    fwht(e, mod);
    fwht(B, mod);
    for (int i = 0; i < (int) e.size(); i++) {
        e[i] = _mul(e[i], _binpow(B[i], t, mod), mod);
    }
    fwht(e, mod);
    return e;
//    for (ll it = 0; it < t; it++) {
//        vector<ll> hlp(e.size(), 0);
//        for (int i = 0; i < (int) e.size(); i++)
//            for (int j = 0; j < (int) e.size(); j++)
//                hlp[i ^ j] = _sum(hlp[i ^ j], _mul(e[i], B[j], mod), mod);
//        e = hlp;
//        for (int u = 0; u < (int) hlp.size(); u++) {
//            for (int v = 0; v < (int) hlp.size(); v++) {
//                hlp[u] = _sum(hlp[u], _mul(e[v], B[pop_count(u ^ v)], mod), mod);
//            }
//        }
//        e = hlp;
//    }
    return e;
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1, g;
    g = gcd(b % a, a, x1, y1);
    x = y1 - x1 * (b / a);
    y = x1;
    return g;
}

ll rev2(ll mod) {
    ll x, y;
    gcd(2, mod, x, y);
    x = (x % mod + mod) % mod;
    return x;
}

ll ctr(ll x1, ll m1, ll x2, ll m2) {
    ll m3 = m1 * m2;
    ll x_hat, y_hat;
    gcd(m1, m2, x_hat, y_hat);

    x_hat = (x_hat % m3 + m3) % m3;
    y_hat = (y_hat % m3 + m3) % m3;

    ll r1 = _mul(x1, _mul(m2, y_hat, m3), m3);
    ll r2 = _mul(x2, _mul(m1, x_hat, m3), m3);

    return _sum(r1, r2, m3);
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    ll t, p;

    cin >> m >> t >> p;

    int n = 1 << m;

    vector<ll> e(n), B(1 << m);
    for (int i = 0; i < n; i++)
        cin >> e[i];

    vector<ll> b(m + 1);
    for (int i = 0; i <= m; i++)
        cin >> b[i];

    for (int x = 0; x < (int) B.size(); x++)
        B[x] = b[pop_count(x)];
//    for (auto x : e)
//        cout << x << " ";
//    cout << " ??\n";

//    vector<ll> res = solve(t, p, e, B);

    int k = 0;
    while (!(p & 1))
        k++, p >>= 1;

    ll mod1 = p;
    ll mod2 = 1ll << (k + m);

    vector<ll> res1 = solve(t, mod1, e, B);
    vector<ll> res2 = solve(t, mod2, e, B);
    vector<ll> res(1 << m);

    ll r2 = rev2(mod1);
    r2 = _binpow(r2, m, mod1);
    for (int i = 0; i < (int) res1.size(); i++) {
        ll x1 = _mul(r2, res1[i], mod1);
        ll x2 = res2[i] >> m;
        res[i] = ctr(x1, p, x2, 1ll << k);
    }

    for (ll x : res)
        cout << x << "\n";

    return 0;
}