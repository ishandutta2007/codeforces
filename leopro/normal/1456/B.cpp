#include <bits/stdc++.h>

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
    // cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

unsigned int highest_bit(unsigned int x) {
    for (unsigned int i = 40; i >= 0; --i) if (x & (1uLL << i)) return i;
    return 0;
}

void solve() {
    autoint n;
    vector<unsigned int> a(n);
    cin >> a;
    for (int i = 0; i + 2 < n; ++i) {
        if (highest_bit(a[i]) == highest_bit(a[i + 1]) && highest_bit(a[i + 1]) == highest_bit(a[i + 2])) answer(1);
    }
    int ans = 1e9;
    for (int i = 1; i < n; ++i) {
        unsigned int leftXOR = a[i - 1];
        for (int j = i - 1; j >= 0; --j) {
            unsigned int rightXOR = a[i];
            for (int k = i; k < n; ++k) {
                if (leftXOR > rightXOR) ans = min(ans, k - j - 1);

                if (k + 1 < n) rightXOR = rightXOR ^ a[k + 1];
            }
            if (j) leftXOR = leftXOR ^ a[j - 1];
        }
    }
    answer(ans == 1e9 ? -1 : ans);
}