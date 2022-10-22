#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned int ui;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

inline ll _mul(ll a, ll b, ll m) {
    return (a * b) % m;
}

ll _binpow(ll x, ll p, ll m) {
    ll res = 1;
    ll tmp = x % m;
    while(p > 0) {
        if(p & 1) {
            res = _mul(res, tmp, m);
        }
        tmp = _mul(tmp, tmp, m);
        p >>= 1;
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll a, b, p, X;

    cin >> a >> b >> p >> X;

    ll P = p * (p - 1);
    ll res = 0;

    for(ll y = 0;y < p - 1;y++) {
        ll x = _mul(b, _binpow(a, p - 1 - y, p), p);
        ll n = x * (1 - p) + y * p;
        n %= P;
        if(n < 0) n += P;
        if(n <= X) {
            res += (X - n) / P + 1;
        }
    }

    cout << res << "\n";

    return 0;
}