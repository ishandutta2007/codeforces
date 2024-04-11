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
    string s;
    cin >> s;
    if (count(s.begin(), s.end(), '0') % 2 == 1 || n % 2 == 1) answer("NO");
    if (s.front() == '0' || s.back() == '0') answer("NO");
    string a = s, b = s;
    int b1 = 0, b2 = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1' && max(b1, b2) > 1 && min(b1, b2)) {
            a[i] = ')', b[i] = ')', b1--, b2--;
        }else
        if (s[i] == '1' && (max(b1, b2) <= 1 || min(b1, b2) == 0)) {
            a[i] = '(', b[i] = '(', b1++, b2++;
        }else
        if (s[i] == '0' && b1 >= b2) {
            a[i] = ')', b[i] = '(', b1--, b2++;
        }else
        if (s[i] == '0' && b1 < b2) {
            a[i] = '(', b[i] = ')', b1++, b2--;
        }
    }
    a[n - 1] = b[n - 1] = ')';
    b1--, b2--;
    if (b1 || b2) answer("NO");
    answer("YES", a, b);
}