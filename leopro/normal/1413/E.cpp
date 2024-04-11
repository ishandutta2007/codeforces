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
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

int get(int time, int plus, int seg, int freq) {
    if (time <= seg){
        int cnt = (time / freq) + 1;
        int l = time * plus;
        int r = (time - (freq * (cnt - 1))) * plus;
        return (l + r) * cnt / 2;
    }
    int full = (time - seg) / freq + 1;
    return full * plus * seg + get(time - full * freq, plus, seg, freq);
}

int f(int t, int a, int b, int c, int d) {
    int time = t * d;
    int lost = (t + 1) * a;
    int got = get(time, b, c, d);
    return lost - got;
}

void solve() {
    autoint a, b, c, d;
    int l = 0, r = (c + 5);
    while (r - l > 2) {
        int m1 = (l + r) / 2;
        int m2 = m1 + 1;
        auto left = f(m1, a, b, c, d);
        auto right = f(m2, a, b, c, d);
        (left >= right ? r = m2 : l = m1);
    }
    if (l > c) {
        cout << "-1\n";
    } else {
        cout << max({f(l, a, b, c, d), f(l + 1, a, b, c, d), f(l + 2, a, b, c, d), f(l + 3, a, b, c, d)}) << '\n';
    }
}