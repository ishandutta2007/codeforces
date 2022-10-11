#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

template<typename T>
int normalize(T val, int mod) {
    if (val < -mod || val >= 2 * mod)
        val %= mod;
    if (val < 0)
        val += mod;
    if (val >= mod)
        val -= mod;
    return int(val);
}

template<int mod>
struct mval {
    int val;

    mval() : val(0) {}
    template<typename T> mval(T val) : val(normalize(val, mod)) {}

    explicit operator int() const { return val; }
    explicit operator long long() const { return val; }

    mval power(long long deg) const {
        deg = normalize(deg, mod - 1);
        mval prod = 1;
        mval a = *this;
        for (; deg; deg >>= 1, a *= a)
            if (deg & 1)
                prod *= a;
        return prod;
    }
    mval rev() const { return power(-1); }

    mval& operator+=(const mval m) { val += m.val; if (val >= mod) val -= mod; return *this; }
    mval& operator-=(const mval m) { val -= m.val; if (val < 0) val += mod; return *this; }
    mval& operator*=(const mval m) { val = 1ll * val * m.val % mod; return *this; }
    mval& operator/=(const mval m) { val = 1ll * val * m.rev().val % mod; return *this; }
    template<typename T> mval& operator=(const T x) { *this = mval(x); return *this; }

    friend mval operator+(const mval a, const mval b) { return mval(a) += b; }
    friend mval operator-(const mval a, const mval b) { return mval(a) -= b; }
    friend mval operator*(const mval a, const mval b) { return mval(a) *= b; }
    friend mval operator/(const mval a, const mval b) { return mval(a) /= b; }

    mval& operator++() { ++val; if (val == mod) val = 0; return *this; }
    mval operator++(int) { val++; if (val == mod) val = 0; return *this; }
    mval& operator--() { --val; if (val == -1) val = mod - 1; return *this; }
    mval operator--(int) { val--; if (val == -1) val = mod - 1; return *this; }

    bool operator==(const mval m) const { return val == m.val; }
    bool operator!=(const mval m) const { return val != m.val; }
    bool operator<(const mval m) const { return val < m.val; }
    bool operator>(const mval m) const { return val > m.val; }

    friend istream& operator>>(istream &in, mval &m) { long long x; in >> x; m = mval(x); return in; }
    friend ostream& operator<<(ostream &out, const mval m) { return out << m.val; }
};

constexpr int MOD = 1'000'000'007;
// constexpr int MOD = 998'244'353;
using mint = mval<MOD>;

template<typename T>
struct graph {
    struct edge {
        int from, to;
        T cost;
    };

    int n;
    std::vector<edge> edges;
    std::vector<std::vector<int>> g;

    graph(int n = 0) : n(n), g(n) {}

    int size() const {
        return n;
    }

    void resize(int new_n) {
        n = new_n;
        g.resize(new_n);
    }

    void reserve(int mem) {
        edges.reserve(mem);
    }

    virtual int add(int from, int to, T cost) = 0;
};

template<typename T>
struct forest : public graph<T> {
    using graph<T>::n;
    using graph<T>::edges;
    using graph<T>::g;

    std::vector<int> root;
    std::vector<int> parent;
    std::vector<int> previous_edge;
    std::vector<int> depth;
    std::vector<int> subtree_size;
    std::vector<T> dist;
    std::vector<int> tin;
    std::vector<int> tout;

    forest(int n = 0) : graph<T>(n) {}

    int add(int from, int to, T cost = T(1)) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = int(edges.size());
        g[from].push_back(id);
        g[to].push_back(id);
        edges.push_back({from, to, cost});
        return id;
    }

    bool is_parent(int v, int u) const {
        return tin[v] <= tin[u] && tout[u] <= tout[v];
    }

    bool is_root(int v) const {
        return root[v] == v;
    }

    bool connected(int v, int u) const {
        return root[v] == root[u];
    }

    void set_default() {
        root.resize(n);
        std::iota(root.begin(), root.end(), 0);
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        previous_edge.assign(n, -1);
        depth.assign(n, 0);
        subtree_size.assign(n, 0);
        dist.assign(n, T(0));
        tin.assign(n, 0);
        tout.assign(n, 0);
    }

    void set_root(int new_root) {
        if (root.empty())
            set_default();

        static int timer = 0;

        std::function<void(int)> dfs = [&](int v) {
            subtree_size[v] = 1;
            tin[v] = timer++;
            for (const int id : g[v]) {
                int u = v ^ edges[id].from ^ edges[id].to;
                if (u == parent[v])
                    continue;

                root[u] = root[v];
                parent[u] = v;
                previous_edge[u] = id;
                depth[u] = depth[v] + 1;
                dist[u] = dist[v] + edges[id].cost;

                dfs(u);
                subtree_size[v] += subtree_size[u];
            }
            tout[v] = timer;
        };

        parent[new_root] = root[new_root] = new_root;
        previous_edge[new_root] = -1;
        depth[new_root] = 0;
        dist[new_root] = T(0);
        dfs(new_root);
    }

    void init() {
        set_default();
        for (int v = 0; v < n; v++)
            if (root[v] == v)
                set_root(v);
    }

    std::vector<int> order(int start) const {
        std::vector<int> order;

        std::function<void(int, int)> dfs = [&](int v, int parent) {
            order.push_back(v);
            for (const int id : g[v]) {
                int u = v ^ edges[id].from ^ edges[id].to;
                if (u == parent)
                    continue;

                dfs(u, v);
            }
        };

        dfs(start, start);
        return order;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    forest<int> tree(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        tree.add(v, u);
    }

    if (k == 1) {
        cout << n << '\n';
        return;
    }
    if (k == 2) {
        cout << mint(n) * (n - 1) / 2 << '\n';
        return;
    }

    mint answer = 0;
    for (int c = 0; c < n; c++) {
        tree.set_root(c);
        vector<int> ls;
        ls.reserve(len(tree.g[c]));
        for (int id : tree.g[c])
            ls.push_back(tree.tin[c ^ tree.edges[id].from ^ tree.edges[id].to]);

        assert(is_sorted(all(ls)));
        auto get_id = [&](int x) -> int {
            return upper_bound(all(ls), x) - ls.begin() - 1;
        };

        vector<mint> dp(k + 1);
        vector<int> cnt(len(ls));
        for (int dep = 1; dep < n; dep++) {
            fill(all(cnt), 0);
            for (int v = 0; v < n; v++)
                if (tree.depth[v] == dep)
                    cnt[get_id(tree.tin[v])]++;

            if (len(cnt) - count(all(cnt), 0) < k)
                continue;

            fill(all(dp), 0);
            dp[0] = 1;
            for (auto num : cnt)
                for (int i = k; i > 0; i--)
                    dp[i] += dp[i - 1] * num;

            answer += dp[k];
        }
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}