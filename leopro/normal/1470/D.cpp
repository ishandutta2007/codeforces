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

struct DSU {
    vector<int> parent, size;

    explicit DSU(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }

    int component(int x) { return (x == parent[x]) ? x : component(parent[x]); }

    bool connected(int x, int y) { return component(x) == component(y); }

    void connect(int x, int y) {
        x = component(x);
        y = component(y);
        if (x == y) return;
        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
    }
};

void solve() {
    autoint n, m;
    vector<vector<int>> edges(n);
    for (int j = 0; j < m; ++j) {
        autoint u, v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    queue<int> bfs;
    vector<int> d(n, 1e9);
    d[0] = 0;
    bfs.push(0);
    vector<int> ans;
    vector<bool> inans(n);
    while (!bfs.empty()) {
        int c = bfs.front();
        bfs.pop();
        bool ok = true;
        for (int next : edges[c]) if (inans[next]) ok = false;
        if (ok) ans.push_back(c+1);
        if (ok) inans[c] = true;
        for (int next : edges[c]) {
            if (d[next] > d[c] + 1) {
                d[next] = d[c] + 1;
                bfs.push(next);
            }
        }
    }
    if (find_if(d.begin(), d.end(), [&](int dist) { return dist > n; }) != d.end()) answer("NO");
    sort(ans.begin(), ans.end());
    answer("YES", ans.size(), ans);
}