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

        operator int() { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };

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
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

string sorted(string s) {
    stable_sort(s.begin(), s.end());
    return s;
}

void solve() {
    autoint n;
    string s, t;
    cin >> s >> t;
    if (sorted(s) != sorted(t)) answer(-1);
    vector<vector<int>> s_letters_count(26, vector<int>(n)), t_letters_count(26, vector<int>(n));
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for (char c = 'a'; c <= 'z'; ++c) {
        for (int i = 0; i < n; ++i) {
            s_letters_count[c - 'a'][i] = (i ? s_letters_count[c - 'a'][i - 1] : 0) + (c == s[i]);
            t_letters_count[c - 'a'][i] = (i ? t_letters_count[c - 'a'][i - 1] : 0) + (c == t[i]);
        }
    }
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 1e18));
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if (i < n && j < n && s[i] == t[j]) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            else if (j < n && i && t_letters_count[t[j] - 'a'][j] <= s_letters_count[t[j] - 'a'][i - 1]) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            }
        }
    }
    answer(dp[n][n]);
}