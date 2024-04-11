#pragma GCC optimize ("O3")
#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#else
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
//#define int long long
    using ll = long long;
    using ull = unsigned long long;

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (is_integral_v<S> && !is_same_v<S, char> ? " " : "") << p.second;
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
        for (const T &t : v) os << t << (is_integral_v<T> && !is_same_v<T, char> ? " " : "\n");
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
        for (const T &t : v) os << t << (is_integral_v<T> && !is_same_v<T, char> ? " " : "");
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

        explicit autoint(int i) : x(i) {}

        autoint() { cin >> x; }

        operator int() const { return x; }

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

struct portal {
    int x, y;
    bool active;

    friend istream &operator>>(istream &is, portal &p) {
        int a;
        is >> p.x >> p.y >> a;
        p.active = a;
        return is;
    }
};

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

void solve() {
    autoint n;
    vector<portal> p(n);
    cin >> p;
    vector<int> c{0};
    for (auto[x, y, _] : p) {
        c.push_back(x);
        c.push_back(y);
    }
    sort(c.begin(), c.end());
    vector<int> what(2 * n + 1);
    int index = 0;
    for (auto &[x, y, _] : p) {
        x = lower_bound(c.begin(), c.end(), x) - c.begin();
        y = lower_bound(c.begin(), c.end(), y) - c.begin();
        what[x] = what[y] = index++;
    }
    mod_int ans = 1;
    vector<mod_int> over(2 * n + 2);
    over[2 * n + 1] = 1;
    for (int i = 2 * n; i > 0; --i) {
        int j = what[i];
        if (p[j].y == i) {
            over[i] = over[i + 1] + over[p[j].x + 1] - over[p[j].x];
        } else {
            over[i] = over[i + 1] * 2 - !p[j].active;
        }
        ans += over[i] * (c[i] - c[i - 1]);
    }
    cout << ans << '\n';
}