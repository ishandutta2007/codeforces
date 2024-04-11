#include <bits/stdc++.h>

#include <utility>

namespace {
    using namespace std;
#define int long long

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
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
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
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
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

        autoint() : x(0) { cin >> x; }

        operator int() { return x; }                                               //NOLINT
        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };   //NOLINT
    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    vector<T> prefix_sum(const vector<T> &v, int from = 0) {
        vector<T> res(v.size() + 1 - from);
        res[0] = 0;
        for (int i = from; i < v.size(); ++i) res[i + 1 - from] = res[i - from] + v[i];
        return res;
    }


}

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct mod_int {
    static const int MOD = 998244353;
    int value;

    mod_int(int i = 0) : value(i % MOD) {} //NOLINT
    mod_int operator+(mod_int m) const { return (value + m.value) % MOD; }

    mod_int operator+=(mod_int m) {
        value += m.value;
        return value %= MOD;
    }

    mod_int operator-(mod_int m) const { return (value - m.value + MOD) % MOD; }

    mod_int operator-=(mod_int m) {
        value -= (m.value - MOD);
        return value %= MOD;
    }

    mod_int operator*(mod_int m) const { return (value * m.value) % MOD; }

    mod_int operator*=(mod_int m) {
        value *= m.value;
        return value %= MOD;
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

    operator int() { return value; }  //NOLINT
};

int min(const vector<vector<int>> &min_table, int l, int r, const vector<int> &log) { // [l; r]
    int j = log[++r - l];
    return min(min_table[j][l], min_table[j][r - (1 << j)]);
}

void solve() {
    autoint n, m;
    vector<int> a(n), b(m);
    cin >> a >> b;

    vector<int> distincts = a;
    for (int y : b) distincts.push_back(y);
    stable_sort(distincts.begin(), distincts.end());
    distincts.resize(unique(distincts.begin(), distincts.end()) - distincts.begin());
    for (int &x : a) x = lower_bound(distincts.begin(), distincts.end(), x) - distincts.begin();
    for (int &y : b) y = lower_bound(distincts.begin(), distincts.end(), y) - distincts.begin();

    vector<int> right_most(n + m, -1);
    for (int i = 0; i < n; ++i) right_most[a[i]] = i;

    vector<int> points;
    for (int y : b) points.push_back(right_most[y]);
    vector<int> t = points;
    stable_sort(t.begin(), t.end());
    if (t != points || find(points.begin(), points.end(), -1) != points.end()) answer(0);


    vector<int> log(n + 1);
    for (int i = 2; i <= n; ++i) log[i] = -~log[i / 2];
    vector<vector<int>> min_table(log[n] + 1, vector<int>(n));
    for (int i = 0; i < n; ++i) min_table[0][i] = a[i];
    for (int j = 1; j <= log[n]; ++j) {
        for (int i = 0; i + (1 << (j - 1)) < n; ++i) {
            min_table[j][i] = min(min_table[j - 1][i], min_table[j - 1][i + (1 << (j - 1))]);
        }
    }

    if (min(min_table, 0, points.front(), log) != a[points.front()]) answer(0);
    if (min(min_table, points.back(), n - 1, log) != a[points.back()]) answer(0);

    mod_int ans = 1;
    for (int i = 0; i < points.size() - 1; ++i) {
        int l = points[i], r = points[i + 1];
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            (min(min_table, points[i], m, log) == a[points[i]] ? l : r) = m;
        }
        int R = l;
        if (R + 1 != points[i + 1]) answer(0);
        l = points[i], r = points[i + 1];
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            (min(min_table, m, points[i + 1], log) == a[points[i + 1]] ? r : l) = m;
        }
        int L = r;
        ans *= R - L + 2;
    }
    answer(ans);
}