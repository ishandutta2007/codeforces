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
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

int highest_bit(int x) {
    for (int i = 60; i >= 0; --i) if (x & (1LL << i)) return i;
    return -1;
}

void solve() {
    autoint x;
    int y = x;
    int ops = 500;
    cout << ops << '\n';
    for (int i = 0; i < highest_bit(x); ++i) {
        cout << y << " + " << y << '\n';--ops;
        y *= 2;
    }
    cout << y << " + " << x << '\n';--ops;
    cout << y + x << " ^ " << x << '\n';--ops;
    cout << ((y + x) ^ x) << " ^ " << y << '\n';--ops;
    int b = (y + x) ^ x ^ y;

    cout << b << " + " << b << '\n';--ops;
    int pow2;
    if (highest_bit(b - 1) == highest_bit(b)) {
        cout << b + b << " ^ " << b << '\n';--ops;

        int t = (b + b) ^b;
        int p = 2 * t;cout << t << " + " << t << '\n',--ops;
        for (; (p ^ t) == p + t; cout << p << " + " << p << '\n',p*=2,--ops);
        cout << p << " + " << t << '\n';--ops;
        cout << p << " ^ " << t << '\n';--ops;
        cout << (p + t) << " ^ " << (p ^ t) << '\n';--ops;
        pow2 = (p + t) ^ (p ^ t);
    } else pow2 = b;

    for (int p2 = pow2; p2 <= (1LL << 60); cout << p2 << " + " << p2 << '\n',p2*=2, --ops);
    int exp = highest_bit(pow2);

    for (int i = 0; i < exp && y < (1LL << 60); ++i) {
        cout << y << " + " << y << '\n';--ops;
        y *= 2;
    }

    int res = x;
    for (int i = 1; i < exp; ++i) {
        if (res & (1LL << i)) {
            cout << res << " ^ " << (x << i) << '\n';--ops;
            res ^= (x << i);
        }
    }

    for (int i = 1; i < 60; ++i) {
        if (res & (1LL << i)) {
            cout << res << " ^ " << (1LL << i) << '\n';
            res ^= (1LL << i);
            --ops;
        }
    }
    while (ops--) cout << "1 + 1\n";
}