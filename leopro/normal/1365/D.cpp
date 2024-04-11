#include <bits/stdc++.h>

#include <utility>

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
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

bool valid(int i, int j, int n, int m) {
    return (0 <= i && i < n) && (0 <= j && j < m);
}

void solve() {
    autoint n, m;
    vector<vector<char>> lab(n, vector<char>(m));
    cin >> lab;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (lab[i][j] == 'B') {
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (abs(di) + abs(dj) == 2) continue;
                        if (!valid(i + di, j + dj, n, m)) continue;
                        if (lab[i + di][j + dj] == 'G') answer("No");
                        if (lab[i + di][j + dj] != 'B') lab[i + di][j + dj] = '#';
                    }
                }
            }
        }
    }

    vector<vector<bool>> ok(n, vector<bool>(m));
    ok[n - 1][m - 1] = true;
    queue<pair<int, int>> bfs;
    if (lab[n - 1][m - 1] != '#') bfs.emplace(n - 1, m - 1);
    while (!bfs.empty()) {
        auto cell = bfs.front();
        bfs.pop();
        int i = cell.first, j = cell.second;
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                if (abs(di) + abs(dj) == 2) continue;
                if (!valid(i + di, j + dj, n, m)) continue;
                if (ok[i + di][j + dj]) continue;
                if (lab[i + di][j + dj] == '#') continue;
                bfs.emplace(i + di, j + dj);
                ok[i + di][j + dj] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (lab[i][j] == 'G' && !ok[i][j]) answer("No");
            if (lab[i][j] == 'B' && ok[i][j]) answer("No");
        }
    }
    answer("Yes");
}