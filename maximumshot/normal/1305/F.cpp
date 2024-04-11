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
 
namespace FACTORIZE {
    const ll MAXX = 1000;
    const int FERMA_ITER = 30;
    //const int POLLARD_PO_ITER = 10000;
    int POLLARD_PO_ITER;
 
    inline ll sqr(ll n) {
        return n * n;
    }
 
    ll check_small(ll n) {
        for(ll x = 1;sqr(x) <= n && x <= MAXX;x++) {
            if(x > 1 && n % x == 0) {
                return x;
            }else if(sqr(x + 1) > n) {
                return -1;
            }
        }
        return -1;
    }
 
    ll check_square(ll n) {
        ll bl = 0;
        ll br = 3e9+1;
        ll bm;
        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if(sqr(bm) <= n) {
                bl = bm;
            }else {
                br = bm;
            }
        }
        if(sqr(bl) == n && bl > 1) {
            return bl;
        }else {
            return -1;
        }
    }
 
    inline ll _mul(ll val, ll n, ll mod) {
        long long int q=((double)val*(double)n/(double)mod);
        long long int res=val*n-mod*q;
        res=(res%mod+mod)%mod;
        return res;
    }
 
//    inline ll _mul(ll a, ll b, ll m) {
//        static __int128 xa = 1;
//        static __int128 xb = 1;
//        static __int128 xm = 1;
//        xa = a;
//        xb = b;
//        xm = m;
//        return ll(xa * xb % xm);
//    }
 
    inline ll _binpow(ll x, ll p, ll m) {
        static ll res = 1;
        static ll tmp = 1;
        res = 1;
        tmp = x;
        while(p > 0) {
            if(p & 1ll) {
                res = _mul(res, tmp, m);
            }
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
 
        if(n <= 1) return false;
        if(n == 2) return true;
 
        ll a, g;
 
        for(int iter = 0;iter < FERMA_ITER;iter++) {
            a = next_rand() % (n - 2);
            if(a < 0) a += n - 2;
            a += 2;
            assert(1 < a && a < n);
            g = gcd(a, n);
            if(g != 1) {
                return false;
            }
            if(_binpow(a, n - 1, n) != 1) {
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
 
    ll pollard_po(ll n) {
        POLLARD_PO_ITER = 5 + 3 * pow(n, 0.25);
        ll a, b, x, g;
        while(1) {
            a = next_rand() % n;
            if(a < 0) a += n;
            b = next_rand() % n;
            if(b < 0) b += n;
            for(int iter = 0;iter < POLLARD_PO_ITER;iter++) {
                x = a >= b ? a - b : b - a;
                g = gcd(x, n);
                if(1 < g && g < n) {
                    return g;
                }
                a = _func(a, n);
                b = _func(_func(b, n), n);
            }
        }
    }
 
    ll get_div(ll n) {
        ll res;
 
        res = check_small(n);
 
        if(res != -1) {
            return res;
        }
 
        res = check_square(n);
 
        if(res != -1) {
            return res;
        }
 
        if(is_prime(n)) {
            return n;
        }
 
        return pollard_po(n);
    }
 
    void factorize(ll n, vector<ll> &ps) {
        if (n == 1) {
            return;
        }
 
        ll p = get_div(n);
        ll q = n / p;
 
        if (p > q)
            swap(p, q);
 
        if (q == n) {
            ps.push_back(q);
            return;
        }
 
        factorize(p, ps);
        factorize(q, ps);
    }
}
 
const int N = 2e5 + 5;
 
ll gcd(ll x, ll y) {
    return !x ? y : gcd(y % x, x);
}
 
int n;
ll a[N];
 
void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}
 
mt19937 rnd(42);
mt19937_64 gen(42);
 
void _gen() {
    n = 200000;
    const ll MAXX = 1e12;
    for (int i = 1; i <= n; i++) {
        a[i] = (gen() % MAXX + MAXX) % MAXX + 1;
    }
}
 
int fast() {
    {
        ll g = 0;
        for (int i = 1; i <= n; i++) {
            g = gcd(g, a[i]);
        }
        if (g > 1) {
            return 0;
        }
    }
    ll res = 0;
    vector<int> ar_hlp;
    ll cnt_1 = 0;
    for (int i = 1; i <= n; i++) {
        res += a[i] % 2;
        if (a[i] > 1) {
            ar_hlp.push_back(i);
        } else {
            cnt_1++;
        }
    }
    sort(ar_hlp.begin(), ar_hlp.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    vector<pii> ar;
    for (int i = 0; i < (int) ar_hlp.size(); i++) {
        int j = i;
        while (j < (int) ar_hlp.size() && a[ar_hlp[i]] == a[ar_hlp[j]])
            j++;
        ar.emplace_back(ar_hlp[i], j - i);
        i = j - 1;
    }
    const double MAX_TIME = 2.2 * CLOCKS_PER_SEC;
    for (int iter = 0; iter % 20 || clock() < MAX_TIME; iter++) {
        if (ar.empty()) {
            break;
        }
        ll x;
        if ((int) ar.size() < 700 && iter < (int) ar.size()) {
            x = a[ar[iter].first];
        } else
        if ((int) ar.size() > 1) {
            int i = rnd() % ((int) ar.size() - 1) + 1;
            int j = rnd() % i;
            i = ar[i].first;
            j = ar[j].first;
            x = abs(a[i] - a[j]);
        } else {
            x = a[ar.front().first];
        }

//        assert(x > 0);
 
        if (x <= 1)
            continue;
 
        vector<ll> ps;
        FACTORIZE::factorize(x, ps);
 
        for (ll p : ps) {
            ll tmp = 0;
            for (pii pr : ar) {
                ll value, cnt;
                tie(value, cnt) = pr;
                value = a[value];
                // cout << "(" << value << ", " << cnt << ")\n";
                ll dist = 0;
                if (value < p)
                    dist = p - value;
                else {
                    ll hlp = value % p;
                    dist = min(hlp, p - hlp);
                }
                tmp += dist * cnt;
            }
            tmp += (p - 1) * cnt_1;
            // cout << p << " " << tmp << "\n";
            res = min(res, tmp);
        }
    }
 
    return (int) res;
}
 
void work() {
    read();
//    _gen();
    cout << fast() << "\n";
}
 
int main() {
 
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    work();
 
    return 0;
}