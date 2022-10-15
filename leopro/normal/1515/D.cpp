#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
const int MAX = 1e6;
#define _GLIBCXX_DEBUG
#else
const int MAX = 1e6;
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
    autoint n, l, r;
    int cnt1 = 0, cnt2 = 0;
    vector<int> left(n), right(n);
    for (int i = 0; i < l; ++i) {
        autoint c;
        left[--c]++;
        cnt1++;
    }
    for (int i = 0; i < r; ++i) {
        autoint c;
        right[--c]++;
        cnt2++;
        if (right[c] && left[c]) {
            right[c]--;
            left[c]--;
            cnt1--;
            cnt2--;
        }
    }
    if (cnt1 > cnt2) {
        swap(left, right);
        swap(cnt1, cnt2);
    }
    int ans = 0;
    int t = (cnt2 - cnt1) / 2;
    for (int i = 0; i < n; ++i) {
        if (t == 0) break;
        while (right[i] >= 2) {
            right[i] -= 2;
            ans++;
            t--;
            if (t == 0) break;
        }
    }
    cout << ans + cnt1 + 2 * t << '\n';
}