#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

namespace FACTORIZE {
    const ll MAXX = 1000;
    const int FERMA_ITER = 30;
// const int POLLARD_PO_ITER = 10000;
    int POLLARD_PO_ITER;
    inline ll sqr(ll n) { return n * n; }
    ll check_small(ll n) {
        for (ll x = 1; sqr(x) <= n && x <= MAXX; x++) {
            if (x > 1 && n % x == 0) {
                return x;
            } else if (sqr(x + 1) > n) {
                return -1;
            }
        }
        return -1;
    }
    ll check_square(ll n) {
        ll bl = 0;
        ll br = 3e9 + 1;
        ll bm;
        while (br - bl > 1) {
            bm = (bl + br) / 2;
            if (sqr(bm) <= n) {
                bl = bm;
            } else {
                br = bm;
            }
        }
        if (sqr(bl) == n && bl > 1) {
            return bl;
        } else {
            return -1;
        }
    }
    inline ll MUL(ll val, ll n, ll mod) {
        long long int q =
                ((double)val * (double)n / (double)mod);
        long long int res = val * n - mod * q;
        res = (res % mod + mod) % mod;
        return res;
    }
    inline ll _mul(ll a, ll b, ll m) {
        static __int128 xa = 1;
        static __int128 xb = 1;
        static __int128 xm = 1;
        xa = a;
        xb = b;
        xm = m;
        return ll(xa * xb % xm);
    }
    inline ll _binpow(ll x, ll p, ll m) {
        static ll res = 1;
        static ll tmp = 1;
        res = 1;
        tmp = x;
        while (p > 0) {
            if (p & 1ll) { res = _mul(res, tmp, m); }
            tmp = _mul(tmp, tmp, m);
            p >>= 1;
        }
        return res;
    }
    mt19937_64 next_rand(42);
    ll gcd(ll x, ll y) {
        return !x ? y : gcd(y % x, x);
    }
    bool is_prime(ll n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        ll a, g;
        for (int iter = 0; iter < FERMA_ITER; iter++) {
            a = next_rand() % (n - 2);
            if (a < 0) a += n - 2;
            a += 2;
            assert(1 < a && a < n);
            g = gcd(a, n);
            if (g != 1) { return false; }
            if (_binpow(a, n - 1, n) != 1) {
                return false;
            }
        }
        return true;
    }
    inline ll _func(ll x, ll n) {
        static ll result = 1;
        result = _mul(x, x, n);
        return result + 1 < n ? result + 1 : 0;
    }
    ll diff(ll x, ll y, ll mod) {
        if (x - y < 0)
            return x - y + mod;
        else
            return x - y + mod;
    }
    ll pollard_po(ll n) {
        const int POLLARD_PO_ITER =
                5 + 3 * pow(n, 0.25);
        const int MAGIC_LOG = 20;
        while (true) {
            ll x = next_rand() % n;
            for (int i = 0; i < POLLARD_PO_ITER; i++) {
                x = _mul(x, x, n) + 1;
            }
            ll y = _mul(x, x, n) + 1;
            for (int i = 0;
                 i < POLLARD_PO_ITER / MAGIC_LOG; i++) {
                ll g = 1;
                for (int j = 0; j < MAGIC_LOG; j++) {
                    g = _mul(g, diff(x, y, n), n);
                    y = _mul(y, y, n) + 1;
                }
                ll res = __gcd(g, n);
                if (res != 1 && res != n) return res;
            }
        }
    }
    ll get_div(ll n) {
        if (n == 1)
            return 1;
        ll res;
        res = check_small(n);
        if (res != -1) { return res; }
        res = check_square(n);
        if (res != -1) { return res; }
        if (is_prime(n)) { return n; }
        return pollard_po(n);
    }
} // namespace FACTORIZE

struct output {
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    ll n;

    input() = default;

    void read() {
        cin >> n;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        for (ll k = 2; k <= 100; k++) {
            ll x = n - k * (k + 1) / 2;
            if (x >= 0 && x % k == 0)
                return output{k};
        }
        for (ll pw = 1;; pw++) {
            ll k = 1ll << pw;
            ll x = n - k * (k + 1) / 2;
            if (x < 0)
                break;
            if (x >= 0 && x % k == 0)
                return output{k};
        }
        ll n2 = n;
        while (n2 % 2 == 0)
            n2 /= 2;
        for (ll k : {n2}) {
            if (k < 2)
                continue;
            ll x = n - k * (k + 1) / 2;
            if (x >= 0 && x % k == 0)
                return output{k};
        }
        return output{-1};
    }

#ifdef DEBUG
    output slow() {
        return output();
    }
#endif
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}

#ifdef DEBUG
void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
            break;
        }
    }
}
#endif

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}