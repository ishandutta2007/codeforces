#include <bits/stdc++.h>

using namespace std;

#define ll   long long

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

template<auto P> ostream& operator << (ostream& o, const Modular<P> &m) { return o << m.value; }
template<auto P> istream& operator >> (istream& i,       Modular<P> &m) { ll k; i >> k; m.value = m.norm(k); return i; }
template<auto P> string   to_string(const Modular<P>& m) { return to_string(m.value); }

using Mint = Modular<1000000007>;
// using Mint = Modular<998244353>;
// using Mint = long double;

vector<vector<Mint>> operator * (vector<vector<Mint>> a, vector<vector<Mint>> b) {
    vector<vector<Mint>> c(a.size(), vector<Mint>(b[0].size(), 0));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[0].size(); ++j) {
            for (int k = 0; k < b[0].size(); ++k) {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    return c;
}

vector<vector<Mint>> pow(vector<vector<Mint>> a, ll p) {
    vector<vector<Mint>> res(a.size(), vector<Mint>(a.size(), 0));
    for (int i = 0; i < res.size(); ++i) {
        res[i][i] = 1;
    }
    while (p) {
        if (p & 1) {
            res = res * a;
        }
        a = a * a;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;
    int k;
    cin >> k;

    vector<vector<Mint>> mt((k + 1) * 2 + 1, vector<Mint>((k + 1) * 2 + 1, 0));

    vector<vector<Mint>> vinit(mt.size(), vector<Mint>(1, 0));

    // first k+1 elements are for F_{i-1}, next k+1 are for F_{i-2}, the last one is for sum up to A_{i-2}
    for (int i = 0; i < k + 1; ++i) {
        vinit[i][0] = 1;
        vinit[i + k + 1][0] = 0;
        vinit.back()[0] = 0;
    }
    vinit[k + 1][0] = 1;

    vector<vector<Mint>> C(50, vector<Mint>(50, 0));
    for (int i = 0; i < C.size(); ++i) {
        C[0][i] = 0;
        C[i][0] = 1;
    }

    for (int i = 1; i < C.size(); ++i) {
        for (int j = 1; j < C.size(); ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }

    vector<Mint> p2(50, 1);
    for (int i = 1; i < p2.size(); ++i)
        p2[i] = p2[i - 1] * 2;

    for (int p = 0; p < k + 1; ++p)
        mt[k + 1 + p][p] = 1;
    mt.back().back() = 1;
    mt.back()[k] = 1;

    for (int p = 0; p < k + 1; ++p) {
        for (int j = 0; j <= p; ++j) {
            mt[p][j] += C[p][j];
            mt[p][k + 1 + j] += C[p][j] * p2[p - j];
        }
    }

    auto res = pow(mt, n) * vinit;
    cout << res.back()[0] << '\n';

    return 0;
}