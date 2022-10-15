// So stupid mistakes...

#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

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
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

int operator%(int x, autoint n) {
    int t = x % (int)n;
    if (t < 0) t += n;
    return t;
}

void solve() {
    autoint n, m;
    vector<vector<int>> data;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data.push_back(vector{i, j, autoint() - 1});
        }
    }
    vector<int> delta(3);
    int row = 0, col = 1, val = 2;
    for (int j = 0; j < m; ++j) {
        char c;
        cin >> c;
        if (c == 'L') delta[col]--;
        if (c == 'R') delta[col]++;
        if (c == 'D') delta[row]++;
        if (c == 'U') delta[row]--;
        if (c == 'I') swap(col, val);
        if (c == 'C') swap(row, val);
    }
    vector<vector<int>> ans(n, vector<int>(n));
    for (auto &cell : data) {
        ans[(cell[row] + delta[row]) % n][(cell[col] + delta[col]) % n] = (cell[val] + delta[val]) % n + 1;
    }
    cout << ans << '\n';
}