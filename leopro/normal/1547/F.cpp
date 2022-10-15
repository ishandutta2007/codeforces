#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
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
        for (const T &t : v) os << t << (is_integral_v<T> && !is_same_v<T, char> ? " " : "");
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
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

void solve() {
    autoint n;
    vector<int> a(n);
    cin >> a;
    int g = 0;
    for (int x : a) g = __gcd(g, x);
    for (int &x : a) x /= g;
    if (all_of(a.begin(), a.end(), [](int x) { return x == 1; })) answer(0);
    for (int i = 0; i < n; ++i) a.push_back(a[i]);
    vector<vector<int>> sparseGcdTable(__lg(a.size()) + 1, vector<int>(a.size()));
    sparseGcdTable[0] = a;
    for (int lvl = 1; lvl <= __lg(a.size()); ++lvl) {
        for (int i = 0; i + (1 << lvl) <= a.size(); ++i) {
            sparseGcdTable[lvl][i] = __gcd(sparseGcdTable[lvl - 1][i], sparseGcdTable[lvl - 1][i + (1 << lvl - 1)]);
        }
    }
    auto gcd = [&](int l, int r) { // [l; r)
        int lg = __lg(r - l);
        return __gcd(sparseGcdTable[lg][l], sparseGcdTable[lg][r - (1 << lg)]);
    };
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) continue;
        int l = i + 1, r = a.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (gcd(i, m) > 1) l = m; else r = m;
        }
        ans = max(ans, r - i);
    }
    cout << ans - 1 << '\n';
}