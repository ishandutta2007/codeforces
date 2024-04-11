/*
    author:  Maksim1744
    created: 17.08.2020 23:25:37
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

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

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

template<auto P>
struct Modular {
    using value_type = decltype(P);
    value_type value;

    Modular(ll k = 0) : value(norm(k)) {}

    Modular<P>& operator += (const Modular<P>& m)       { value += m.value; if (value >= P) value -= P; return *this; }
    Modular<P>  operator +  (const Modular<P>& m) const { Modular<P> r = *this; return r += m; }

    Modular<P>& operator -= (const Modular<P>& m)       { value -= m.value; if (value <  0) value += P; return *this; }
    Modular<P>  operator -  (const Modular<P>& m) const { Modular<P> r = *this; return r -= m; }
    Modular<P>  operator -                     () const { return Modular<P>(-value); }

    Modular<P>& operator *= (const Modular<P> &m)       { value = value * 1ll * m.value % P; return *this; }
    Modular<P>  operator *  (const Modular<P>& m) const { Modular<P> r = *this; return r *= m; }

    Modular<P>& operator /= (const Modular<P> &m)       { return *this *= m.inv(); }
    Modular<P>  operator /  (const Modular<P>& m) const { Modular<P> r = *this; return r /= m; }

    Modular<P>& operator ++                    ()       { return *this += 1; }
    Modular<P>& operator --                    ()       { return *this -= 1; }
    Modular<P>  operator ++                 (int)       { Modular<P> r = *this; r += 1; return r; }
    Modular<P>  operator --                 (int)       { Modular<P> r = *this; r -= 1; return r; }

    bool        operator == (const Modular<P>& m) const { return value == m.value; }
    bool        operator != (const Modular<P>& m) const { return value != m.value; }

    value_type norm(ll k) {
        if (!(-P <= k && k < P)) k %= P;
        if (k < 0) k += P;
        return k;
    }

    Modular<P> inv() const {
        value_type a = value, b = P, x = 0, y = 1;
        while (a != 0) { value_type k = b / a; b -= k * a; x -= k * y; swap(a, b); swap(x, y); }
        return Modular<P>(x);
    }
};

template<auto P> Modular<P> pow(Modular<P> m, ll p) {
    Modular<P> r(1);
    while (p) {
        if (p & 1) r *= m;
        m *= m;
        p >>= 1;
    }
    return r;
}

template<auto P> ostream& operator << (ostream& o, const Modular<P> m) { return o << m.value; }
template<auto P> istream& operator >> (istream& i,       Modular<P> m) { ll k; i >> k; m.value = m.norm(k); return i; }
template<auto P> string   to_string(const Modular<P>& m) { return to_string(m.value); }

using Mint = Modular<1000000007>;
// using Mint = Modular<998244353>;
// using Mint = long double;

vector<vector<Mint>> mul(vector<vector<Mint>>& a, vector<vector<Mint>>& b) {
    vector<vector<Mint>> res(a.size(), vector<Mint>(b[0].size(), 0));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            for (int k = 0; k < b.size(); ++k) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

vector<vector<Mint>> pow(vector<vector<Mint>> a, ll p) {
    vector<vector<Mint>> res(3, vector<Mint>(3, 0));
    for (int i = 0; i < 3; ++i) {
        res[i][i] = 1;
    }
    while (p) {
        if (p & 1) res = mul(res, a);
        a = mul(a, a);
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<vector<vector<Mint>>> mat(8);
    vector<vector<Mint>> base = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}
    };
    for (int i = 0; i < 8; ++i) {
        vector<int> mask;
        for (int j = 0; j < 3; ++j) {
            mask.pb((i >> j) & 1);
        }
        mat[i] = base;
        for (int j = 0; j < 3; ++j) {
            if (mask[j] == 0) {
                mat[i][j] = vector<Mint>(3, 0);
            }
        }
    }
    vector<vector<Mint>> init = {{0}, {1}, {0}};
    ll n, m;
    cin >> n >> m;
    vector<pair<pair<ll, ll>, int>> v(n);
    vector<ll> xs;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second >> v[i].first;
        --v[i].second;
        xs.pb(v[i].first.first);
        xs.pb(v[i].first.second + 1);
    }
    xs.pb(2);
    xs.pb(m);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    vector<vector<int>> dif(3, vector<int>(xs.size(), 0));
    for (int i = 0; i < n; ++i) {
        dif[v[i].second][lowb(xs, v[i].first.first)]++;
        dif[v[i].second][lowb(xs, v[i].first.second + 1)]--;
    }
    show(dif);
    show(xs);
    vector<int> cur(3, 0);
    for (int i = 0; i + 1 < xs.size(); ++i) {
        shows;
        for (int j = 0; j < 3; ++j) {
            cur[j] += dif[j][i];
        }
        int mask = 0;
        for (int j = 0; j < 3; ++j) {
            if (cur[j] == 0) {
                mask += 1 << j;
            }
        }
        show(cur);
        // show(mat[mask]);
        auto pw = pow(mat[mask], xs[i + 1] - xs[i]);
        init = mul(pw, init);
        show(i, init);
        shows;
    }
    cout << init[0][0] + init[1][0] + init[2][0] << '\n';

    return 0;
}