/*
    author:  Maksim1744
    created: 24.10.2021 13:20:31
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

// finds x and y such that a * x + b * y = c
template<typename T>
pair<T, T> egcd(T a, T b, T c) {
    if (a == 0) {
        // b * y = c
        assert(c % b == 0);
        return {0, c / b};
    }
    // a * x + b * y = c
    // a * x + (b % a + (b/a) * a) * y = c
    // a * (x + (b/a) * y) + (b % a) * y = c
    auto [y0, x0] = egcd(b % a, a, c);
    T y = y0;
    T x = x0 - (b / a) * y;
    return {x, y};
}

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int g = 0;
    for (int k : a)
        g = gcd(g, abs(k));
    for (int i = 0; i < n; ++i) {
        a[i] /= g;
    }
    int i1 = -1;
    int i2 = -1;
    int best = 2e9;
    for (int i = 0; i + 1 < n; ++i) {
        int cur = gcd(abs(a[i]), abs(a[i + 1]));
        if (cur < best) {
            best = cur;
            i1 = i;
            i2 = i + 1;
        }
    }
    for (int i = 0; i < max(1000, n * 5); ++i) {
        int j1 = rnd(n);
        int j2 = rnd(n);
        if (j1 == j2) continue;
        int cur = gcd(abs(a[j1]), abs(a[j2]));
        if (cur < best) {
            best = cur;
            i1 = j1;
            i2 = j2;
        }
    }

    ll curs = 0;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        if (i == i1 || i == i2) continue;
        ll sp = curs + a[i] * best;
        ll sm = curs - a[i] * best;
        if (abs(sp) < abs(sm)) {
            b[i] = best;
            curs = sp;
        } else {
            b[i] = -best;
            curs = sm;
        }
    }

    auto [x, y] = egcd<ll>(abs(a[i1]), abs(a[i2]), -curs);
    if (a[i1] < 0) x = -x;
    if (a[i2] < 0) y = -y;
    if (curs == 0) {
        x = a[i2];
        y = -a[i1];
    } else {
        if (x == 0) {
            if (y != a[i1]) {
                x += a[i2];
                y -= a[i1];
            } else {
                x -= a[i2];
                y += a[i1];
            }
        } else if (y == 0) {
            if (x != -a[i2]) {
                x += a[i2];
                y -= a[i1];
            } else {
                x -= a[i2];
                y += a[i1];
            }
        }
    }
    assert(x * a[i1] + y * a[i2] + curs == 0);
    b[i1] = x;
    b[i2] = y;
    ll sma = 0, sm = 0;
    show(a);
    show(b);
    show(i1, i2);
    for (int i = 0; i < n; ++i) {
        sma += abs(b[i]);
        sm += (ll)b[i] * a[i];
    }
    assert(sma <= 1e9);
    assert(sm == 0);
    cout << b << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}