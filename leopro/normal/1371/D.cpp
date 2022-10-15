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
            os << t /*<<(whitespace(t) ? " " : "")*/;
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

pair<int, int> next(pair<int, int> cur, int n) {
    if (cur.first == n - 1 && cur.second == n - 1) {
        return {1, 0};
    }
    if (cur.first == n - 1) {
        return {0, cur.second + 1};
    }
    if (cur.second == n - 1) {
        return {cur.first + 2, 0};
    }
    return {cur.first + 1, cur.second + 1};
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> table(n, vector<int>(n));
     for (pair<int, int> idx = {0, 0}; k--; idx = next(idx, n)) {
        table[idx.first][idx.second] = 1;
    }
    int ans = 0;
    int rmax = -1e18, rmin = 1e18, cmax = -1e18, cmin = 1e18;
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j < n; ++j) {
            s += table[i][j];
        }
        rmax = max(rmax, s);
        rmin = min(rmin, s);
    }
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j < n; ++j) {
            s += table[j][i];
        }
        cmax = max(cmax, s);
        cmin = min(cmin, s);
    }
    cout << (rmax - rmin) * (rmax - rmin) + (cmax - cmin) * (cmax - cmin) << '\n';
    cout << table;
}