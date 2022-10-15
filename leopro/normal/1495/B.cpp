#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long
    using ll = long long;

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (is_integral_v<F> || is_integral_v<S> ? " " : "") << p.second << "\n";
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
        for (const T &t : v) os << t << (is_integral_v<T> ? " " : "");
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
        for (const T &t : v) os << t << (is_integral_v<T> ? " " : "");
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

void solve() {
    autoint n;
    vector<int> p(n);
    cin >> p;
    vector<int> up(n), down(n);
    for (int i = 1; i < n; ++i) {
        up[i] = up[i - 1] + (p[i] > p[i - 1] ? 1 : -up[i - 1]);
        down[i] = down[i - 1] + (p[i] < p[i - 1] ? 1 : -down[i - 1]);
    }
    int maxPath = max(*max_element(up.begin(), up.end()), *max_element(down.begin(), down.end()));
    if (maxPath % 2 == 1) answer(0);
    int top = -1;
    for (int i = 0; i < n; ++i) {
        if (up[i] == maxPath && i + maxPath < down.size() && down[i + maxPath] == maxPath) top = i;
    }
    if (top == -1) answer(0);
    for (int i = 0; i < n; ++i) if (up[i] == maxPath && i != top) answer(0);
    for (int i = 0; i < n; ++i) if (down[i] == maxPath && i != top + maxPath) answer(0);
    answer(1);
}