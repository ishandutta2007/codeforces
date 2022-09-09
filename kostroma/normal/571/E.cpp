#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
#include <time.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1000000007;
time_t BEGIN;

void out(const vi & v) {
    for (int i = 0; i < v.size(); ++i) cerr << v[i] << ' ';
    cerr << endl;
}

ll mpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        n /= 2;
        x = x * x % mod;
    }
    return res;
}

ll inv (ll a, ll b) {
    a %= b;
    ll b0 = b;
    ll xa = 1, xb = 0, ya = 0, yb = 1;
    while (a % b != 0) {
        ll t = a / b;
        a = (a - t * b) % b0;
        xa = (xa - t * ya) % b0;
        xb = (xb - t * yb) % b0;
        swap(a, b);
        swap(xa, ya);
        swap(xb, yb);
    }
    ya %= b0;
    if (ya < 0) ya += b0;
    return ya;
}

ll lcm(ll x, ll y) {
    ll d = __gcd(x, y);
    x /= d;
    if (y) assert(x <= 1e18 / y);
    return x * y;
}

class AP {
public:
    AP(ll s, ll T): s(s), T(T) {}
    AP& operator=(const AP & a) { T = a.T; s = a.s; return *this; }
    void out() {
        cerr << s << "+" << T << "k\n";
    }
    ll T, s;
};

AP strong_intersect(AP a, AP b) {
    if (a.T == b.T) {
        if (a.s == b.s) return a;
        return AP(-1, -1);
    }
    if (a.s == b.s) return AP(a.s, 0);
    if (a.s < b.s) swap(a, b);
    ll num = a.s - b.s;
    ll den = b.T - a.T;
    if (den < 0 || num % den != 0) return AP(-1, -1);
    ll index = num / den;
    return AP(a.s + a.T*index, 0);
}
   
ll mul(ll x, ll y, ll z) {
    if (x == 0 || y == 0) return 0;
    if (y < 0) {
        x = -x;
        y = -y;
    }
    ll res = 0;
    while (y) {
        if (y & 1) res = (res + x) % z;
        y /= 2;
        x = (x + x) % z;
    }
    return res;
}

AP intersect(AP a, AP b) {
//    a.out(); b.out();
    if (a.s < 0 || b.s < 0) return AP(-1, -1);
    if (a.T == 0 && b.T == 0) {
        if (a.s == b.s) return a;
        return AP(-1, -1);
    }
    if (b.T == 0) swap(a, b);
    if (a.T == 0) {
        if (b.s > a.s || (a.s - b.s) % b.T != 0) return AP(-1, -1);
        return a;
    }
    ll d = __gcd(a.T, b.T);
    if (a.s % d != b.s % d) return AP(-1, -1);
    if (a.s < b.s) swap(a, b);
    ll x = (b.s - a.s) / d; // x <= 0
    ll y = b.T / d;
    ll z = a.T / d; // (x + y*i) / z
    assert(y <= 1e18 / z);
    ll r = mul((-x) % z, inv(y, z), z);
    ll mi = r + z*max(0LL, (-x - r*y + z*y - 1) / (z*y));
    assert(mi <= 1e18 / b.T);
//    cerr << x << ' ' << y << ' ' << z << ' ' << mi << endl;
    AP res(b.s + b.T * mi, lcm(a.T, b.T));
//    cerr << "res "; res.out();
    return res;
}

vi uniq_merge(const vi & a, const vi & b) {
    vi c(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    return c;
}

int ord(int a, int p) {
    int cnt = 0;
    while (a % p == 0) {
        ++cnt;
        a /= p;
    }
    return cnt;
}

vi erat;

vi get_primes(int n) {
    vi primes;
    for (int i = 2; i*i <= n; ++i) if (n % i == 0) {
        primes.push_back(i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) primes.push_back(n);
    sort(primes.begin(), primes.end());
    return primes;
}

ll fix(int A0, int B0, ll fix0, int A1, int B1, const vi & curp, bool & fail) {
    ll fix = -1;
    for (auto p : curp) {
        AP a0(ord(A0, p), ord(B0, p));
        if (fix0 >= 0) {
            a0.s = a0.s + a0.T * fix0;
            a0.T = 0;
        }
        AP a1(ord(A1, p), ord(B1, p));
        AP a2 = intersect(a0, a1);
        if (a2.s < 0) {
            fail = true;
            return -1;
        }
        if (a0.T == 0 && a1.T == 0 && a0.s != a1.s) {
            fail = true;
            return -1;
        }
        if (a2.T == 0 && a1.T != 0) {
            ll nfix = (a2.s - a1.s) / a1.T;
            if (fix != -1 && fix != nfix) {
                fail = true;
                return -1;
            }
            fix = nfix;
        }
    }
    return fix;
}

AP trace(AP a, AP b) {
    return AP((a.s - b.s) / b.T, a.T / b.T);
}

AP subsec(AP a, AP b) {
    return AP(a.s + a.T * b.s, a.T * b.T);
}

AP common(int A0, int B0, int A1, int B1, const vi & curp) {
    bool fail = false;
    ll fix1 = fix(A0, B0, -1, A1, B1, curp, fail);
//    cerr << "fix1 " << fix1 << ' ' << fail << endl;
    ll fix0 = fix(A1, B1, fix1, A0, B0, curp, fail);
//    cerr << "fix0 " << fix0 << ' ' << fail << endl;
    if (fail) {
        return AP(-1, -1);
    }
    if (fix0 >= 0) {
        ll fix1 = fix(A0, B0, fix0, A1, B1, curp, fail);
        if (fail || fix1 < 0) {
            return AP(-1, -1);
        } else {
            return AP(fix0, 0);
        }
    }
    AP intersection0(0, 1);
    AP intersection1(0, 1);
    bool was = false;
    for (auto p : curp) {
        AP a0(ord(A0, p), ord(B0, p));
        AP a1(ord(A1, p), ord(B1, p));
        AP a2 = intersect(a0, a1);
        if (a2.s < 0) return AP(-1, -1);
        if (a0.T == 0 && a1.T == 0) continue;
        AP new0 = trace(a2, a0);//((a2.s - a0.s) / a0.T, a2.T / a0.T);
        AP new1 = trace(a2, a1);//((a2.s - a1.s) / a1.T, a2.T / a1.T);
        if (!was) {
            intersection0 = new0;
            intersection1 = new1;
            was = 1;
        } else {
//            cerr << "new "; new0.out(); new1.out();
            AP x0 = intersect(new0, intersection0);
            AP x1 = intersect(new1, intersection1);
            if (x0.s < 0 || x1.s < 0) return AP(-1, -1);
            AP subold0 = trace(x0, intersection0);
            AP subold1 = trace(x1, intersection1);
            AP subold2 = intersect(subold0, subold1);
            if (subold2.s < 0) return AP(-1, -1);
            intersection0 = subsec(intersection0, subold2);
            intersection1 = subsec(intersection1, subold2);
//            cerr << "traced inter "; intersection0.out(); intersection1.out();
            AP subnew0 = trace(intersection0, new0);
            AP subnew1 = trace(intersection1, new1);
            AP subnew2 = strong_intersect(subnew0, subnew1);
//            cerr << "subnew "; subnew0.out(); subnew1.out(); subnew2.out();
            if (subnew2.s < 0) return AP(-1, -1);
            intersection0 = subsec(new0, subnew2);
            intersection1 = subsec(new1, subnew2);
        }
//        cerr << "inter "; intersection0.out(); intersection1.out();
        if (intersection1.T == 0) {
            ll fix1 = intersection1.s;
            ll fix0 = fix(A1, B1, fix1, A0, B0, curp, fail);
            if (fail || fix0 < 0) return AP(-1, -1);
            intersection0 = AP(fix0, 0);
        }
        if (intersection0.T == 0) {
            ll fix0 = intersection0.s;
            ll fix1 = fix(A0, B0, fix0, A1, B1, curp, fail);
            if (fail || fix1 < 0) {
                return AP(-1, -1);
            } else {
                return AP(fix0, 0);
            }
        }
        if (intersection0.s < 0 || intersection1.s < 0) return AP(-1, -1);
    }
    return intersection0;
}

bool check_geom(int a, int b, ll n) {
    if (n % a) return false;
    n /= a;
    if (b == 1) {
        return n == 1;
    }
    while (n > 1) {
        if (n % b) return false;
        n /= b;
    }
    return n == 1;
}

bool check_all_geoms(const vi & a, const vi & b, ll n) {
    for (int j = 0; j < a.size(); ++j) {
        if (!check_geom(a[j], b[j], n)) return false;
    }
    return true;
}

ll check_stupid(const vi & a, const vi & b, int start) {
    ll n = a[start];
    while (1) {
        bool ok = true;
        for (int i = 0; i < a.size(); ++i) {
            if (!check_geom(a[i], b[i], n)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return n%mod;
        }
        if (n > 1e18 / b[start] || b[start] == 1) break;
        n *= b[start];
    }
    return -1;
}

vi factor(int n, const vi & p) {
    vi pw(p.size());
    for (int i = 0; i < p.size(); ++i) {
        while (n % p[i] == 0) {
            n /= p[i];
            ++pw[i];
        }
    }
    return pw;
}

int solve(const vi & a, const vi & b) {
    int n = a.size();
    for (int i = 0; i < n; ++i) if (b[i] == 1) {
        for (int j = 0; j < n; ++j) {
            if (!check_geom(a[j], b[j], a[i])) return -1;
        }
        return a[i];
    }
    vvi primes(n);
    for (int i = 0; i < n; ++i) {
        primes[i] = uniq_merge(get_primes(a[i]), get_primes(b[i]));
    }
    AP intersection(0, 1);
    for (int i = 1; i < n; ++i) {
        vi curp = uniq_merge(primes[0], primes[i]);
        intersection = intersect(intersection, common(a[0], b[0], a[i], b[i], curp));
        if (intersection.s < 0) return -1;
    }
    return a[0]*mpow(b[0], intersection.s) % mod;
}

int stupid_solve(vi a, vi b) {
    vii ts(a.size());
    for (int i = 0; i < a.size(); ++i) ts[i] = pii(a[i], b[i]);
    sort(ts.begin(), ts.end());
    ts.resize(unique(ts.begin(), ts.end()) - ts.begin());
    a.resize(ts.size());
    b.resize(ts.size());
    for (int i = 0; i < a.size(); ++i) {
        a[i] = ts[i].first;
        b[i] = ts[i].second;
    }
/*    int d = a[0];
    for (int i = 0; i < a.size(); ++i) {
        d = __gcd(a, a[i]);
    }
    for (int i = 0; i < a.size(); ++i) {
        a[i] / d;
    }*/
    for (int i = 0; i < a.size(); ++i) if (b[i] == 1) {
        for (int j = 0; j < a.size(); ++j) {
            if (!check_geom(a[j], b[j], a[i])) return -1;
        }
        return a[i];
    }
    for (int i = 0; i < a.size(); ++i) {
        if (b[i] > b[0]) {
            swap(a[0], a[i]);
            swap(b[0], b[i]);
            break;
        }
    }
    vvi primes(a.size());
    vvi primesa(a.size());
    vvi primesb(a.size());
    for (int i = 0; i < a.size(); ++i) {
        primes[i] = uniq_merge(get_primes(a[i]), get_primes(b[i]));
        primesa[i] = get_primes(a[i]);
        primesb[i] = get_primes(b[i]);
    }
    for (int i = 1; i < a.size(); ++i) {
        if (primes[i] != primes[i-1]) {
            int n = (primes[i].size() > primes[i-1].size()) ? a[i] : a[i-1];
            if (!check_all_geoms(a, b, n)) return -1;
            else return n;
        }
        if (primesb[i] != primesb[i-1]) {
            int start = (primesb[i].size() > primesb[i-1].size()) ? i : i-1;
            return check_stupid(a, b, start);
        }
    }
    for (auto p : primesa[0]) if (!binary_search(primesb[0].begin(), primesb[0].end(), p)) {
        for (int i = 1; i < a.size(); ++i) {
            if (ord(a[i], p) != ord(a[i-1], p)) return -1;   
        }
    }
    vvi pa(a.size()), pb(b.size());
    for (int i = 0; i < a.size(); ++i) {
        pa[i] = factor(a[i], primesb[0]);
        pb[i] = factor(b[i], primesb[0]);
    }
    vi v = pa[0];
    for (int pwb = 0; ; ++pwb) {
        double passed_time = (clock() - BEGIN) / (double)CLOCKS_PER_SEC;
        if (passed_time > 0.01) break;
        bool ok = true;
        for (int i = 1; i < a.size() && ok; ++i) {
            int div = 0;
            for (int j = 0; j < v.size(); ++j) {
                if (v[j] < pa[i][j] || (v[j] - pa[i][j]) % pb[i][j] != 0) {
                    ok = false;
                    break;
                }
                int ndiv = (v[j] - pa[i][j]) / pb[i][j];
                if (j && ndiv != div) {
                    ok = false;
                    break;
                }
                div = ndiv;
            }
        }
        if (ok) {
            return a[0] * mpow(b[0], pwb) % mod;
        }
        for (int i = 0; i < v.size(); ++i) {
            v[i] += pb[0][i];
        }
    }
 
//    return check_stupid(a, b, 0);
    return -1;
}

int main() {
    int n;
    while (cin >> n) {
        BEGIN = clock();
        vi a(n), b(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i], &b[i]);
        }
        int res = solve(a, b);
        cout << res << endl;
//        int res1 = stupid_solve(a, b);
//        cout << res1 << endl;
/*        if (res != res1) {
            cerr << res1 << endl;
            out(a); out(b);
            assert(0);
        }*/
    }
    return 0;
}