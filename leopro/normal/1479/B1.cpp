#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

#include <utility>

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

struct segment_tree {
    int n;
    vector<int> values;
    int add = 0;

    segment_tree(int sz) : n(1 << (__lg(sz) + 1)), values(2 * n) {}

    pair<int, int> pair_value_index(int i) { return {values[i], i}; }

    pair<int, int> get_max(int l, int r) {
        pair<int, int> mx = {-1e9, -1};
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) mx = max(mx, pair_value_index(l++));
            if (r & 1) mx = max(mx, pair_value_index(--r));
        }
        mx.first += add;
        return mx;
    }

    void set(int i, int x) {
        x -= add;
        values[i += n] = x;
        for (i /= 2; i > 0; i /= 2) values[i] = max(values[2 * i], values[2 * i + 1]);
    }

    int get(int i) { return get_max(i, i + 1).first; }

    void add_all(int x) { add += x; }
};

void solve() {
    autoint n;
    vector<int> a(n);
    cin >> a;
    segment_tree dp(n + 1);
    dp.set(0, 1);
    for (int i = 1; i <= n; ++i) dp.set(i, -1e9);
    for (int i = 1; i < n; ++i) {
        auto attempt = max(dp.get_max(0, a[i]), dp.get_max(a[i] + 1, n + 1));
        auto old = dp.get(a[i]);
        int mx = max(old, attempt.first + 1);
        if (a[i] != a[i - 1]) dp.add_all(1);
        if (dp.get(a[i - 1]) < mx) dp.set(a[i - 1], mx);
    }
    cout << dp.get_max(0, n + 1).first << '\n';
}