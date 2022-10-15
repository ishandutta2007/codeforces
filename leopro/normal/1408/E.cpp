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

struct edge {
    int u, v, w;

    explicit edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}

    friend istream &operator>>(istream &is, edge &e) {
        is >> e.u >> e.v >> e.w;
        --e.v, --e.u;
        return is;
    }

    bool operator<(const edge &edge) const {
        return w < edge.w;
    }
};

void solve() {
    autoint m, n;
    vector<int> a(m), b(n);
    cin >> a >> b;
    vector<vector<int>> sets(m);
    for (int j = 0; j < m; ++j){
        autoint sz;
        sets[j].resize(sz);
        cin >> sets[j];
    }
    vector<edge> edges;
    int total_sum = 0;
    for (int j = 0; j < m; ++j){
        for (int x : sets[j]) edges.emplace_back(x-1, n + j, b[x - 1] + a[j]);
        for (int x : sets[j]) total_sum += b[x - 1] + a[j];
    }
    DSU dsu(n + m);
    int ans = 0;
    stable_sort(edges.rbegin(), edges.rend());
    for (auto e : edges){
        if (!dsu.connected(e.u, e.v)) {
            dsu.connect(e.u, e.v);
            ans += e.w;
        }
    }
    answer(total_sum - ans);
}