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

struct edge {
    int u, v, b;

    edge(int u, int v, int b) : u(u), v(v), b(b) {}

    friend istream &operator>>(istream &is, edge &e) {
        is >> e.u >> e.v >> e.b;
        --e.u, --e.v;
        return is;
    }

    edge() = default;
};

void dfs(const vector<vector<edge>> &g, vector<int> &color, int cur) {
    for (auto next : g[cur]) {
        int x = next.u + next.v - cur;
        if (color[x] == color[cur]) answer("NO");
        if (color[x] == 1 - color[cur]) continue;
        color[x] = 1 - color[cur];
        dfs(g, color, x);
    }
}

void assert_bipartite(const vector<vector<edge>> &g, int n) {
    vector<int> color(n, -1);
    color[0] = 0;
    dfs(g, color, 0);
}

void solve() {
    autoint n, m;
    vector<edge> e(m);
    vector<vector<edge>> graph(n);
    cin >> e;
    for (int i = 0; i < m; ++i) {
        graph[e[i].u].push_back(e[i]);
        graph[e[i].v].push_back(e[i]);
    }
    assert_bipartite(graph, n);
    vector<vector<int>> highest(n, vector<int>(n, n));
    for (int i = 0; i < n; ++i) {
        highest[i][i] = 0;
        for (int times = 0; times <= n; ++times) {
            for (auto edge : e) {
                highest[i][edge.u] = min(highest[i][edge.u], highest[i][edge.v] + (edge.b == 1 ? -1 : 1));
                highest[i][edge.v] = min(highest[i][edge.v], highest[i][edge.u] + 1);
            }
        }
    }

    int ans = -1;
    for (int mn = 0; mn < n; ++mn) {
        if (highest[mn][mn] < 0) continue;
        ans = max(ans, *max_element(highest[mn].begin(), highest[mn].end()));
    }
    if (ans == -1) answer("NO");
    cout << "YES\n" << ans << '\n';
    for (int mn = 0; mn < n; ++mn) {
        if (highest[mn][mn] < 0) continue;
        if (ans == *max_element(highest[mn].begin(), highest[mn].end())) {
            for (int i = 0; i < n; ++i) cout << highest[mn][i] + n << ' ';
            cout << '\n';
            return;
        }
    }
}