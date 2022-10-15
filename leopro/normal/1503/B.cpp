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
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

using cell = pair<int, int>;
#define i first
#define j second

void solve() {
    autoint n;
    set<cell> free_even, free_odd;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            ((i + k) % 2 ? free_odd : free_even).emplace(i + 1, k + 1);
        }
    }
    for (int turn = 0; turn < n * n; ++turn) {
        autoint forbidden;
        if (forbidden == 2 && free_odd.empty()) {
            auto[i, j] = *free_even.begin();
            free_even.erase(free_even.begin());
            cout << 3 << ' ' << i << ' ' << j << endl;
        } else if (forbidden == 2) {
            auto[i, j] = *free_odd.begin();
            free_odd.erase(free_odd.begin());
            cout << 1 << ' ' << i << ' ' << j << endl;
        } else if (forbidden == 1 && free_even.empty()) {
            auto[i, j] = *free_odd.begin();
            free_odd.erase(free_odd.begin());
            cout << 3 << ' ' << i << ' ' << j << endl;
        } else if (forbidden == 1) {
            auto[i, j] = *free_even.begin();
            free_even.erase(free_even.begin());
            cout << 2 << ' ' << i << ' ' << j << endl;
        } else if (forbidden == 3 && free_even.empty()){
            auto[i, j] = *free_odd.begin();
            free_odd.erase(free_odd.begin());
            cout << 1 << ' ' << i << ' ' << j << endl;
        } else {
            auto[i, j] = *free_even.begin();
            free_even.erase(free_even.begin());
            cout << 2 << ' ' << i << ' ' << j << endl;
        }
    }
}