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

int max(vector<vector<int>> &max_table, vector<int> &lg, int l, int r) {
    if (l > r) return 0;
    int lb = lg[r - l + 1];
    return max(max_table[lb][l], max_table[lb][r - (1 << lb) + 1]);
}

void solve() {
    autoint n;
    vector<char> s(n);
    cin >> s;
    vector<int> s0, s1;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            (s[i] == '0' ? s0 : s1).push_back(1);
        } else {
            (s[i] == '0' ? s0 : s1).back()++;
        }
    }
    if (s[0] == '1') s0.insert(s0.begin(), 0);
    if (s.back() == '1') s0.insert(s0.end(), 0);
    vector<int> lg(n, 0);
    for (int i = 2; i < n; ++i) lg[i] = lg[i / 2] + 1;

    vector<vector<int>> max_table(lg[s1.size()] + 1, vector<int>(s1.size()));
    for (int i = 0; i < s1.size(); ++i) max_table[0][i] = s1[i];
    for (int lg = 1; lg < max_table.size(); ++lg) {
        for (int j = 0; (j + (1 << lg) - 1) < s1.size(); ++j) {
            max_table[lg][j] = max(max_table[lg-1][j], max_table[lg-1][(j + (1 << (lg - 1)))]);
        }
    }

    vector<int> ps0 = s0;
    ps0.insert(ps0.begin(), 0);
    for (int i = 1; i < ps0.size(); ++i) ps0[i] += ps0[i - 1];

    vector<int> ps1 = s1;
    ps1.insert(ps1.begin(), 0);
    for (int i = 1; i < ps1.size(); ++i) ps1[i] += ps1[i - 1];

    int ans = 0;
    for (int i = 0; i < s1.size(); ++i) {
        int l = 0, r = i + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            (max(max_table, lg, i - m, i - 1) < s1[i] ? l : r) = m;
        }

        int x = 0, y = s1.size() - i;
        while (y - x > 1) {
            int m = (x + y) / 2;
            (max(max_table, lg, i + 1, i + m) <= s1[i] ? x : y) = m;
        }

        int len1 = (ps1[i] - ps1[i - l]) + (ps0[i + 1] - ps0[i - l]);     if (i - l - 1 >= 0) len1 += s1[i]-1;
        int len2 = (ps1[i + x + 1] - ps1[i + 1]) + (ps0[i +x + 2] - ps0[i + 1]);if (i + x + 1 < s1.size()) len2 += s1[i];
        ans += (len1 + 1) * (len2 + 1) * s1[i];
        for (int len = 1; len < s1[i]; ++len) {

            int l = 0, r = i + 1;
            while (r - l > 1) {
                int m = (l + r) / 2;
                (max(max_table, lg, i - m, i - 1) < len ? l : r) = m;
            }

            int x = 0, y = s1.size() - i;
            while (y - x > 1) {
                int m = (x + y) / 2;
                (max(max_table, lg, i + 1, i + m) <= len ? x : y) = m;
            }

            int len1 = (ps1[i] - ps1[i - l]) + (ps0[i + 1] - ps0[i - l]);
            if (i - l - 1 >= 0) len1 += len-1;
            ans += (1 + len1) * len;
            int len2 = (ps1[i + x + 1] - ps1[i + 1]) + (ps0[i +x + 2] - ps0[i + 1]);
            if (i + x + 1 < s1.size()) len2 += len;
            ans += (len2 + 1) * len;
        }
        for (int len = 1; len + 2 <= s1[i]; ++len) ans += len * (s1[i] - len - 1);
    }
    answer(ans);

}