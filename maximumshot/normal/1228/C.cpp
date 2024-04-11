#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const ll mod = inf + 7;

inline ll _mul(ll a, ll b) {
    return (a * b) % mod;
}

inline ll _binpow(ll x, ll pw) {
    ll res = 1;
    ll tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

vector<ll> get_primes(ll x) {
    vector<ll> res;
    for (ll p = 2; p * p <= x; p++) {
        if (x % p) continue;
        while (x % p == 0) {
            x /= p;
        }
        res.push_back(p);
    }
    if (x > 1) res.push_back(x);
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x, n;
    cin >> x >> n;

    vector<ll> ps = get_primes(x);

    ll tot = 1;

    for (ll p : ps) {
        ll pw = 0;
        ll val = n;
        ll cur = 1;
        while (val) {
            pw += (cur * ((val / p) % (mod - 1))) % (mod - 1);
            pw %= (mod - 1);
            val /= p;
        }
        tot = _mul(tot, _binpow(p, pw));
    }

    cout << tot << "\n";

    return 0;
}