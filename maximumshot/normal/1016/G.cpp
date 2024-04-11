#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const ll maxx = 1e7;

ll _mul(ll a, ll b, ll md) {
    ll res = 0;
    for(int i = 0;i <= 62;i++) {
        if((1ll << i) & a) {
            ll ad = b;
            for(int j = 0;j < i;j++) {
                if((ad += ad) >= md) ad -= md;
            }
            if((res += ad) >= md) res -= md;
        }
    }
    return res;
}

ll is_sqr(ll x) {
    ll bl = 0;
    ll br = inf + 1;
    ll bm;

    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(bm * bm <= x) bl = bm;
        else br = bm;
    }

    if(bl * bl == x) {
        return bl;
    }else {
        return -1;
    }
}

ll binpow(ll x, ll pw, ll md) {
    ll res = 1ll % md;
    ll tmp = x % md;
    while(pw > 0) {
        if(pw & 1) {
            res = _mul(res, tmp, md);
        }
        tmp = _mul(tmp, tmp, md);
        pw >>= 1;
    }
    return res;
}

ll gcd(ll x, ll y) {
    return !x ? y : gcd(y % x, x);
}

bool is_prime(ll x) {
    mt19937_64 rnd(42);
    for(int iter = 0;iter < 100;iter++) {
        ll a = rnd() % (x - 1) + 1;
        ll g = gcd(a, x);
        if(g > 1) return false;
        if(binpow(a, x - 1, x) != 1) return false;
    }
    return true;
}

vec< ll > simple_factorize(ll x) {
    if(is_prime(x)) {
        return {x};
    }

    auto nxt = [x](ll t) -> ll { return (_mul(t, t, x) + 1) % x; };
    ll ITER = 5 + 3 * pow(x, 0.25);
    mt19937_64 rnd(42);

    while(1) {
        ll a = rnd() % x;
        ll b = rnd() % x;
        for(int iter = 0;iter < ITER;iter++) {
            ll value = a >= b ? a - b : b - a;
            ll GCD = gcd(value, x);
            if(1 < GCD && GCD < x) {
                return {GCD, x / GCD};
            }
            a = nxt(a);
            b = nxt(nxt(b));
        }
    }
}

vec< ll > factorize(ll x) {
    if(x == 1) return {};
    vec< ll > res;
    for(ll y = 2;y <= maxx;y++) {
        if(x % y) continue;
        while(x % y == 0) {
            x /= y;
        }
        res.push_back(y);
    }
    if(x == 1) return res;
    {
        ll hlp = is_sqr(x);
        if(hlp != -1) {
            res.push_back(hlp);
            return res;
        }
    }
    vec< ll > ad_res = simple_factorize(x);
    for(ll adx : ad_res) res.push_back(adx);
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;
    ll X, Y;

    scanf("%d %lld %lld", &n, &X, &Y);

    if(Y % X) {
        puts("0");
        return 0;
    }

    vec< ll > a(n);
    for(int i = 0;i < n;i++) scanf("%lld", &a[i]);

    if(X == Y) {
        int c1 = 0, c2 = 0;
        for(int i = 0;i < n;i++) {
            if(a[i] % X == 0) {
                c1++;
            }
            if(Y % a[i] == 0) {
                c2++;
            }
        }
        printf("%lld\n", 1ll * c1 * c2);
        return 0;
    }

    vec< ll > ps = factorize(Y);
    vec< int > as, bs;

    for(int i = 0;i < n;i++) {
        if(a[i] % X) continue;
        int mask = 0;
        for(int j = 0;j < (int)ps.size();j++) {
            ll p = ps[j];
            ll v1 = a[i];
            ll v2 = X;
            while(v1 % p == 0 && v2 % p == 0) {
                v1 /= p;
                v2 /= p;
            }
            if(v1 % p && v2 % p) {
                mask |= (1 << j);
            }
        }
        as.push_back(mask);
    }

    for(int i = 0;i < n;i++) {
        if(Y % a[i]) continue;
        int mask = 0;
        for(int j = 0;j < (int)ps.size();j++) {
            ll p = ps[j];
            ll v1 = a[i];
            ll v2 = Y;
            while(v1 % p == 0 && v2 % p == 0) {
                v1 /= p;
                v2 /= p;
            }
            if(v1 % p && v2 % p) {
                mask |= (1 << j);
            }
        }
        bs.push_back(mask);
    }

    int sz = (int)ps.size();
    int need = (1 << sz) - 1;

    vec< int > cnt(1 << sz);

    for(int _a  : as) cnt[_a]++;

    vec< vec< int > > D(1 << sz, vec< int >(sz + 1));

    for(int i = 0;i < (1 << sz);i++) {
        D[i][0] = cnt[i];
    }

    for(int i = 0;i < sz;i++) {
        for(int S = 0;S < (1 << sz);S++) {
            D[S][i + 1] = D[S][i];
            if(!((1 << i) & S)) D[S][i + 1] += D[S ^ (1 << i)][i];
        }
    }

    ll res = 0;

    for(int _b : bs) {
        int _a = need ^ _b;
        res += D[_a][sz];
    }

    printf("%lld\n", res);

    return 0;
}