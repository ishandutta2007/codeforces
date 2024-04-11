#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

const int inf = 1e9;
const ll inf64 = 1e18;

const ll mod = inf + 7;

inline ll _mul(ll a, ll b) {
    return (a * b) % mod;
}

inline ll _sum(ll a, ll b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline ll _sub(ll a, ll b) {
    return a >= b ? a - b : a - b + mod;
}

inline ll binpow(ll x, ll pw) {
    ll res = 1;
    ll tmp = x % mod;
    while(pw > 0) {
        if(pw & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll x, k;

    cin >> x >> k;

    if(!x) {
        cout << 0 << "\n";
        return 0;
    }

    ll res = _mul(binpow(2, k + 1), x % mod);

    res = _sub(res, _sub(binpow(2, k), 1));

    cout << res << "\n";

    return 0;
}