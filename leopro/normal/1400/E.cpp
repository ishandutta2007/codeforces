#include <bits/stdc++.h>

namespace {
    using namespace std;
//#define int long long

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
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
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
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
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

        autoint() : x(0) { cin >> x; }

        operator int() { return x; }                                               //NOLINT
        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };   //NOLINT
    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    vector<T> prefix_sum(const vector<T> &v, int from = 0) {
        vector<T> res(v.size() + 1 - from);
        res[0] = 0;
        for (int i = from; i < v.size(); ++i) res[i + 1 - from] = res[i - from] + v[i];
        return res;
    }
}

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

//void solve() {
//    autolong p, f, cnts, cntw, s, w;
//    if (s > w) {
//        swap(s, w);
//        swap(cnts, cntw);
//    }
//    long long ans = 0;
//    for (int i = 0; i <= cnts; ++i) {
//        long long weight = i * s;
//        if (weight > p) continue;
//        int countw = (p - weight) / w;
//        int rs = cnts - i;
//        int rw = cntw - countw;
//
//        if (rs * s <= f) {
//            ans = max(ans, i + rs + countw + min((long long) rw, (f - rs * s) / s));
//        } else {
//            ans = max(ans, i + countw + f / s);
//        }
//    }
//    cout << ans << '\n';
void solve() {
    autoint n;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> dp(n, vector<int>(n + 1, n));
    for (int i = 0; i <= min(a[0], n - 0); ++i) dp[0][i] = (a[0] > i) + i;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i + 1] >= j) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (a[i + 1] > j));
            if (a[i + 1] <= n)
                dp[i + 1][a[i + 1]] = min(dp[i + 1][a[i + 1]], dp[i][j] + (a[i + 1] > j ? a[i + 1] - j : 0));
        }
    }
    answer(*min_element(dp.back().begin(), dp.back().end()));
}