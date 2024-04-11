#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long
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

void solve() {
    string s;
    cin >> s;
    autoint x, y;
    if (x > y) {
        for (char &c : s) if (c != '?') c = '0' + '1' - c;
        swap(x, y);
    }
    string t = s;
    for (char &c : s) if (c == '?') c = '1';
    int right_zero = count(s.begin() + 1, s.end(), '0'),
            right_one = count(s.begin() + 1, s.end(), '1'),
            left_zero = 0, left_one = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') ans += left_one * y, left_zero++; else ans += left_zero * x, left_one++;
    }
    left_zero = left_one = 0;
    int mn = ans;
    for (int i = 0; i < s.size(); ++i) {
        if (t[i] == '?') {
            if (s[i] == '0') ans -= left_one * y + right_one * x; else ans -= left_zero * x + right_zero * y;
            s[i] = '0' + '1' - s[i];
            if (s[i] == '0') ans += left_one * y + right_one * x; else ans += left_zero * x + right_zero * y;
        }
        mn = min(mn, ans);
        if (i+1<s.size()) {if (s[i+1] == '0') right_zero--; else right_one--;}
        /*_____________*/ { if (s[i] == '0') left_zero++; else left_one++;}
    }
    answer(mn);
}