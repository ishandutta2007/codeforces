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

#define x first
#define y second
using cell = pair<int, int>;

void solve() {
    autoint n, m;
    vector<cell> pawns(m);
    cin >> pawns;
    for (auto &p : pawns) --p.x;
    for (auto &p : pawns) --p.y;
    vector<vector<int>> g(n + m);
    auto link = [&](int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    };
    for (int i = 0; i < m; ++i) link(n + i, pawns[i].x);
    for (int i = 0; i < m; ++i) link(n + i, pawns[i].y);
    for (auto &v : g) {
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
    }
    vector<int> comp(n + m);
    function<void(int, int)> dfs = [&](int cur, int c) {
        if (comp[cur] == c) return;
        comp[cur] = c;
        for (int next : g[cur]) dfs(next, c);
    };
    int c = 0;
    for (int i = 0; i < n + m; ++i) {
        if (comp[i] == 0) dfs(i, ++c);
    }
    vector<bool> cycle(c + 1, true);
    for (int i = 0; i < n + m; ++i) {
        if (g[i].size() <= 1) cycle[comp[i]] = false;
    }
    int already = count_if(pawns.begin(), pawns.end(), [](cell p) { return p.x == p.y; });
    cout << m - already + count(cycle.begin() + 1, cycle.end(), true) << '\n';
}