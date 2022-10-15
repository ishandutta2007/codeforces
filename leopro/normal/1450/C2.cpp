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
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

void solve() {
    autoint n;
    vector<vector<char>> a(n, vector<char>(n));
    cin >> a;
    int mn = n * n, r1 = 0, r2 = 0;
    for (int rO = 0; rO < 3; ++rO) {
        for (int rX = 0; rX < 3; ++rX) {
            if (rO == rX) continue;
            int cnt = 0;
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                    if ((x + y) % 3 == rO && a[x][y] == 'X') cnt++;
                    if ((x + y) % 3 == rX && a[x][y] == 'O') cnt++;
                }
            }
            if (mn > cnt) { mn = cnt, r1 = rO, r2 = rX; }
        }
    }
    int ans = 0, cnt = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            cnt += a[x][y] != '.';
            if ((x + y) % 3 == r1 && a[x][y] == 'X') a[x][y] = 'O',ans++;
            if ((x + y) % 3 == r2 && a[x][y] == 'O') a[x][y] = 'X',ans++;
        }
    }
    answer(a);
}