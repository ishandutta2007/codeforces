/*
    author:  Maksim1744
    created: 12.06.2021 14:27:14
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
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

const int basen = 9;
const int base = pow(10, basen);

// uncomment to multiply large numbers with fft
// basen should be even, at most 8
// with doubles in fft and basen = 8 works up to Big.v.size() = 1e6 (but fails for 1e6 + 5e4)
// #define BIGINT_USE_FFT

// division works in n^2 * log(base), where n = Big.v.size()

struct Big {
    vector<int> v;
    bool minus = false;

    Big() {}
    Big(long long k) {
        if (k < 0) {
            minus = true;
            k = -k;
        }
        while (k) {
            v.push_back(k % base);
            k /= base;
        }
    }
    Big(string s) {
        if (s[0] == '-') {
            s.erase(s.begin());
            minus = true;
        }
        reverse(s.begin(), s.end());
        while (s.size() % basen != 0)
            s.push_back('0');
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i += basen)
            v.push_back(stoi(s.substr(i, basen)));
        reverse(v.begin(), v.end());
        norm();
    }

    Big &operator += (const Big &other) {
        if (minus == other.minus) {
            _add_(v, other.v);
        } else {
            if (_comp_(other.v, v)) {
                _sub_(v, other.v);
            } else {
                _sub2_(v, other.v);
                minus ^= 1;
            }
        }
        norm();
        return *this;
    }
    Big operator + (const Big &other) const {
        auto res = *this;
        return res += other;
    }

    Big operator - () const {
        Big res = *this;
        if (!v.empty()) res.minus ^= 1;
        return res;
    }
    Big &operator -= (const Big &other) {
        return *this += -other;
    }
    Big operator - (const Big &other) const {
        auto res = *this;
        return res -= other;
    }

    Big operator * (const Big &other) const {
        if (v.empty() || other.v.empty()) return 0;
        Big res;
        res.v = _mult_(v, other.v);
        res.minus = minus ^ other.minus;
        return res;
    }
    Big &operator *= (const Big &other) {
        return *this = *this * other;
    }

    Big operator / (const Big &other) const {
        Big res;
        res.v = _div_(v, other.v).first;
        res.minus = minus ^ other.minus;
        res.norm();
        return res;
    }
    Big &operator /= (const Big &other) {
        return *this = *this / other;
    }

    Big operator % (const Big &other) const {
        Big res;
        res.v = _div_(v, other.v).second;
        res.minus = minus ^ other.minus;
        res.norm();
        return res;
    }
    Big &operator %= (const Big &other) {
        return *this = *this % other;
    }

    int operator % (int m) const {
        long long p = 1;
        long long res = 0;
        for (int k : v) {
            res += k * p % m;
            p = p * base % m;
        }
        return res % m;
    }

    void norm() {
        while (!v.empty() && v.back() == 0)
            v.pop_back();
        if (v.empty())
            minus = false;
    }

    bool operator < (const Big &other) const {
        if (minus != other.minus) return minus;
        if (minus) return _comp_(other.v, v);
        else return _comp_(v, other.v);
    }
    bool operator > (const Big &other) const {
        return other < *this;
    }
    bool operator <= (const Big &other) const {
        return !(other < *this);
    }
    bool operator >= (const Big &other) const {
        return !(*this < other);
    }

    bool operator == (const Big &other) const {
        return minus == other.minus && v == other.v;
    }
    bool operator != (const Big &other) const {
        return !(*this == other);
    }

  private:
    static void _sub_(vector<int> &a, const vector<int> &b) {
        a.resize(max(a.size(), b.size()) + 1, 0);
        for (int i = 0; i < b.size(); ++i)
            a[i] -= b[i];
        for (int i = 0; i + 1 < b.size() || a[i] < 0; ++i) {
            if (a[i] < 0) {
                a[i] += base;
                --a[i + 1];
            }
        }
        assert(a.back() >= 0);
        while (!a.empty() && a.back() == 0)
            a.pop_back();
    }

    static void _sub2_(vector<int> &a, const vector<int> &b) {
        a.resize(max(a.size(), b.size()) + 1, 0);
        for (int i = 0; i < a.size(); ++i)
            a[i] = (i < b.size() ? b[i] : 0) - a[i];
        for (int i = 0; i + 1 < a.size(); ++i) {
            if (a[i] < 0) {
                a[i] += base;
                --a[i + 1];
            }
        }
        assert(a.back() >= 0);
        while (!a.empty() && a.back() == 0)
            a.pop_back();
    }

    static void _add_(vector<int> &a, const vector<int> &b) {
        a.resize(max(a.size(), b.size()) + 1, 0);
        for (int i = 0; i < b.size(); ++i)
            a[i] += b[i];
        for (int i = 0; i + 1 < b.size() || a[i] >= base; ++i) {
            if (a[i] >= base) {
                a[i] -= base;
                ++a[i + 1];
            }
        }
        while (!a.empty() && a.back() == 0)
            a.pop_back();
    }

    static bool _comp_(const vector<int> &a, const vector<int> &b) {
        if (a.size() != b.size())
            return a.size() < b.size();
        for (int i = (int)a.size() - 1; i >= 0; --i)
            if (a[i] != b[i])
                return a[i] < b[i];
        return false;
    }

    static vector<int> _mult_(const vector<int> &a, const vector<int> &b) {
        #ifdef BIGINT_USE_FFT
        // tested on a.v.size() = 1e6, b.v.size() = C, fft is better on C > ~500 : https://ideone.com/kSYLd8
        // if a.v.size() = b.v.size() = C, it's 380 : https://ideone.com/MJTo1Y
        if (min(a.size(), b.size()) > 380) {
            return _fft_mult_(a, b);
        }
        #endif

        return _slow_mult_(a, b);
    }

    static vector<int> _slow_mult_(const vector<int> &a, const vector<int> &b) {
        vector<long long> tmp(a.size() + b.size() + 1, 0);
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                long long prod = 1ll * a[i] * b[j];
                long long div = prod / base;
                tmp[i + j] += prod - base * div;
                tmp[i + j + 1] += div;
            }
        }
        for (int i = 0; i + 1 < tmp.size(); ++i) {
            long long div = tmp[i] / base;
            tmp[i + 1] += div;
            tmp[i] -= div * base;
        }
        while (!tmp.empty() && tmp.back() == 0)
            tmp.pop_back();
        return vector<int>(tmp.begin(), tmp.end());
    }

    #ifdef BIGINT_USE_FFT
    static vector<int> _fft_mult_(const vector<int> &a, const vector<int> &b) {
        vector<int> ta(a.size() * 2), tb(b.size() * 2);
        static_assert(basen % 2 == 0, "basen has to be even");
        const static int M = pow(10, basen / 2);
        for (int i = 0; i < a.size(); ++i) {
            ta[i * 2] = a[i] % M;
            ta[i * 2 + 1] = a[i] / M;
        }
        for (int i = 0; i < b.size(); ++i) {
            tb[i * 2] = b[i] % M;
            tb[i * 2 + 1] = b[i] / M;
        }
        auto tc = fft::multiply(ta, tb);
        tc.resize(tc.size() / 2 * 2 + 10, 0);
        for (int i = 0; i + 1 < tc.size(); ++i) {
            tc[i + 1] += tc[i] / M;
            tc[i] %= M;
        }
        vector<int> res(tc.size() / 2);
        for (int i = 0; i < res.size(); ++i)
            res[i] = tc[i * 2] + tc[i * 2 + 1] * M;
        while (!res.empty() && res.back() == 0)
            res.pop_back();
        return res;
    }
    #endif

    static pair<vector<int>, vector<int>> _div_(vector<int> a, vector<int> b) {
        if (a.size() < b.size()) {
            return {{}, a};
        }
        vector<int> res;
        vector<int> c, c2;
        for (int i = (int)a.size() - b.size(); i >= 0; --i) {
            c.resize(b.size() + i);
            for (int j = 0; j < b.size(); ++j) {
                c[i + j] = b[j];
            }
            int L = 0, R = base;
            while (R - L > 1) {
                int C = (L + R) / 2;
                c2 = _mult_(c, {C});
                if (_comp_(a, c2)) {
                    R = C;
                } else {
                    L = C;
                }
            }
            c = _mult_(c, {L});
            _sub_(a, c);
            res.push_back(L);
        }
        reverse(res.begin(), res.end());
        return {res, a};
    }
};

string to_string(const Big &b) {
    if (b.v.empty()) return "0";
    string res;
    for (int i = (int)b.v.size() - 1; i >= 0; --i) {
        string t = to_string(b.v[i]);
        if (!res.empty())
            t = string(basen - t.size(), '0') + t;
        res += t;
    }
    if (b.minus)
        res.insert(res.begin(), '-');
    return res;
}

ostream &operator << (ostream &o, const Big &b) {
    return o << to_string(b);
};

istream &operator >> (istream &i, Big &b) {
    string s;
    i >> s;
    b = Big(s);
    return i;
}

Big gcd(Big a, Big b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

mt19937_64 rng(94238742);
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Big n;
    cin >> n;

    auto gen_rand = [&]() {
        if (n.v.size() == 1)
            return Big(rnd(n.v[0]));
        Big b;
        b.v.resize(n.v.size());
        b.v.back() = rnd(n.v.back());
        for (int i = 0; i + 1 < b.v.size(); ++i)
            b.v[i] = rnd(base);
        return b;
    };

    int Q = 80;
    vector<pair<Big, Big>> v;
    vector<Big> al;
    for (int i = 0; i < Q; ++i) {
        auto x = gen_rand();
        if (gcd(x, n) != 1) continue;
        cout << "sqrt " << x * x % n << endl;
        Big y;
        cin >> y;
        if (x == y) continue;
        Big a = (x + n - y);
        if (a >= n)
            a -= n;
        Big b = x + y;
        if (b >= n)
            b -= n;
        if (a == 0 || b == 0) continue;
        a = gcd(a, n);
        b = gcd(b, n);
        if (a == 0 || b == 0) continue;
        v.eb(a, b);
        al.pb(a);
        al.pb(b);
    }

    assert(!al.empty());
    sort(al.begin(), al.end());
    al.erase(unique(al.begin(), al.end()), al.end());
    for (int i = 0; i < 200; ++i) {
        auto x = al[rnd(al.size())];
        auto y = al[rnd(al.size())];
        auto res = gcd(x, y);
        if (res != 1)
            al.pb(res);
    }
    sort(al.begin(), al.end());
    al.erase(unique(al.begin(), al.end()), al.end());
    vector<Big> ans;
    for (auto k : al) {
        k = gcd(n, k);
        if (k != 1) {
            n /= k;
            ans.pb(k);
        }
    }

    cout << "! " << ans.size() << ' ' << ans << endl;

    return 0;
}