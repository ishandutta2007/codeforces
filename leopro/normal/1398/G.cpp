#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
//#define int long long
    using ll = long long;

    template<typename T>
    inline bool whitespace(const vector<T> &) { return false; }

    template<typename T>
    inline bool whitespace(const T &) { return true; }

    inline bool whitespace(const char) { return false; }

    template<typename F, typename S>
    inline bool whitespace(const pair<F, S> &) { return false; }

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n";
        return os;
    }

    template<typename F, typename S>
    istream &operator>>(istream &is, pair<F, S> &p) {
        is >> p.first >> p.second;
        return is;
    }

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
        os << "\n";
        return os;
    }

    template<typename T>
    istream &operator>>(istream &is, deque<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const deque<T> &v) {
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
        os << "\n";
        return os;
    }

    class exit_exception : exception {
    };

    void answer() {}

    template<typename First, typename... Args>
    void answer(First &&val, Args &&... ans) {
        cout << val << "\n";
        answer(ans...);
        throw exit_exception();
    }

    struct autoint {
        int x;

        autoint(int i) : x(i) {}

        autoint() { cin >> x; }

        operator int() { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };
}

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct mod_int {
    static const int MOD = 998244353;
    int value;

    mod_int(int i = 0) : value(i) {}
    mod_int operator+(mod_int m) const {
        mod_int lhs = *this;
        lhs += m;
        return lhs;
    }

    mod_int operator+=(mod_int m) {
        value += m.value;
        if (value >= MOD) value -= MOD;
        return value;
    }

    mod_int operator-(mod_int m) const {
        mod_int lhs = *this;
        lhs -= m;
        return lhs;
    }

    mod_int operator-=(mod_int m) {
        value -= (m.value - MOD);
        if (value >= MOD) value -= MOD;
        return value;
    }

    mod_int operator*(mod_int m) const { return (value * 1LL * m.value) % MOD; }

    mod_int operator*=(mod_int m) {
        value = (value * 1LL * m.value) % MOD;
        return value;
    }

    mod_int power(int exp) {
        if (exp == 0) return 1;
        mod_int res = (exp & 1 ? value : 1);
        mod_int half = power(exp >> 1);
        return res * half * half;
    }

    mod_int operator/(mod_int m) const { return *this * m.power(MOD - 2); }

    mod_int operator/=(mod_int m) { return *this *= m.power(MOD - 2); }

    friend std::istream &operator>>(std::istream &is, mod_int &m) {
        is >> m.value;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const mod_int &m) {
        os << m.value;
        return os;
    }

    explicit operator int() const { return value; }
};

vector<int> convert(const vector<mod_int> &v) {
    vector<int> res(v.size());
    for (int i = 0; i < v.size(); ++i) res[i] = (int) v[i];
    return res;
}

vector<mod_int> convert(const vector<int> &v) {
    vector<mod_int> res(v.size());
    for (int i = 0; i < v.size(); ++i) res[i] = v[i];
    return res;
}

template<typename RingElement>
vector<RingElement> fft(const vector<RingElement> &polynomial, RingElement omega) {
    if (polynomial.size() == 1) return polynomial;
    vector<RingElement> odd(polynomial.size() / 2), even(polynomial.size() / 2);
    for (int i = 0; i < polynomial.size(); ++i) (i % 2 == 0 ? even : odd)[i / 2] = polynomial[i];
    vector<RingElement> u = fft(even, omega * omega), v = fft(odd, omega * omega);
    vector<RingElement> w(polynomial.size());
    RingElement power = 1;
    for (int i = 0; i < w.size(); ++i) {
        w[i] = u[(i >= u.size() ? i - u.size() : i)] + v[(i >= v.size() ? i - v.size() : i)] * power;
        power *= omega;
    }
    return w;
}

template<typename RingElement>
RingElement root(int size) {}

template<>
mod_int root(int size) {
    return mod_int(421).power((1 << 20) / size);
}

template<typename RingElement>
vector<int> product(vector<int> a, vector<int> b) {
    int sz = 2 << (__lg(max(a.size(), b.size()) - 1) + 1);
    a.resize(sz);
    b.resize(sz);
    auto omega = root<RingElement>(sz / 2);
    vector<RingElement> u = fft(convert(a), omega);
    vector<RingElement> v = fft(convert(b), omega);
    vector<RingElement> w(sz);
    for (int i = 0; i < sz; ++i) w[i] = u[i] * v[i];
    vector<RingElement> p = fft(w, mod_int(1) / omega);
    for (auto &c : p) c /= sz;
    return convert(p);
}

vector<bool> find_differences(const vector<int> &a) {
    vector<int> r = a;
    for (int &x : r) x = a.back() - x;
    vector<int> p1(a.back() + 1), p2(a.back() + 1);
    for (int x : a) p1[x] = 1;
    for (int x : r) p2[x] = 1;
    vector<int> p = product<mod_int>(p1, p2);
    vector<bool> ans(a.back() + 1);
    for (int i = 0; i <= a.back(); ++i) ans[i] = p[a.back() - i];
    return ans;
}

void solve() {
    autoint n, x, y;
    vector<int> a(n + 1);
    cin >> a;
    vector<bool> sum = find_differences(a);
    autoint q;
    for (int query = 0; query < q; ++query) {
        autoint l;
        l = l / 2;
        int d = 1;
        for (; d * d <= l; ++d) {
            int v = l / d;
            if (l % d == 0 && v - y > 0 && v - y < sum.size() && sum.at(v - y)) {
                cout << 2 * v << ' ';
                goto OUT;
            }
        }
        for (; d > 0; --d) {
            int v = d;
            if (l % d == 0 && v - y > 0 && v - y < sum.size() && sum.at(v - y)) {
                cout << 2 * v << ' ';
                goto OUT;
            }
        }
        cout << "-1 ";
        OUT:;
    }
}