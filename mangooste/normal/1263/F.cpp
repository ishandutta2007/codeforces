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
inline bool setmin(T &a, const T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
inline bool setmax(T &a, const T b) { if (a < b) { a = b; return true; } return false; }


template<typename Fun>
class y_combinator {
    const Fun _fun;
public:
    explicit y_combinator(const Fun&& fun) : _fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    inline decltype(auto) operator()(Args&&... args) const {
        return _fun(std::ref(*this), std::forward<Args>(args)...);
    }
};


template<typename T, typename Comp = less<T>>
struct SparseTable {
    Comp cmp;
    vector<vector<T>> sparse;
    vector<int> largestBit;

    inline T best(const T &a, const T &b) {
        return cmp(a, b) ? a : b;
    }

    SparseTable() {}

    SparseTable(vector<T> a) {
        int n = int(a.size());
        largestBit.resize(n + 1, -1);
        for (int i = 1; i <= n; i++)
            largestBit[i] = largestBit[i / 2] + 1;

        sparse.resize(largestBit.back() + 1, vector<T>(n));
        for (int i = 0; i < n; i++)
            sparse[0][i] = a[i];

        for (int level = 0; level < largestBit.back(); level++)
            for (int i = 0; i + (1 << (level + 1)) <= n; i++)
                sparse[level + 1][i] = best(sparse[level][i], sparse[level][i + (1 << level)]);
    }

    inline T query(int l, int r) { // [l, r)
        int level = largestBit[r - l];
        return best(sparse[level][l], sparse[level][r - (1 << level)]);
    }
};

struct graph {
    int n;
    vector<vector<int>> g;
    vector<int> dep;
    vector<int> who;

    int timer;
    vector<int> time;
    vector<int> path;
    vector<int> moments;
    SparseTable<int> sp;

    graph() {}
    graph(int n, int l) : n(n), g(n), dep(n), who(l), timer(0), time(n) {}

    void read() {
        for (int i = 1; i < n; i++) {
            int par;
            cin >> par;
            g[par - 1].push_back(i);
        }
        for (auto &x : who)
            cin >> x, x--;

        who.insert(who.begin(), -1);

        y_combinator([&](auto dfs, int v) -> void {
            time[v] = timer++;
            for (auto u : g[v]) {
                path.push_back(v);
                moments.push_back(time[v]);
                dep[u] = dep[v] + 1;
                dfs(u);
            }
        })(0);
        sp = SparseTable<int>(moments);
    }

    inline int lca(int a, int b) {
        if (a == -1 || b == -1)
            return 0;

        if (a == b)
            return a;

        tie(a, b) = minmax(time[a], time[b]);
        return path[sp.query(a, b)];
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    array<graph, 2> g;
    for (int i = 0; i < 2; i++) {
        int size;
        cin >> size;
        g[i] = graph(size, n);
        g[i].read();
    }

    array<vector<int>, 2> dp;
    dp.fill(vector<int>(n + 1, 1e9));
    dp[0][0] = dp[1][0] = 0;

    for (int where = 1; where <= n; where++) {
        array<vector<int>, 2> ndp;
        ndp.fill(vector<int>(n + 1, 1e9));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= n; j++)
                setmin(ndp[i][j], dp[i][j]
                    + g[i].dep[g[i].who[where]] - g[i].dep[g[i].lca(g[i].who[where], g[i].who[where - 1])]);

            for (int prev = 0; prev <= n; prev++)
                setmin(ndp[i][where - 1], dp[i ^ 1][prev]
                    + g[i].dep[g[i].who[where]] - g[i].dep[g[i].lca(g[i].who[prev], g[i].who[where])]);
        }
        dp = ndp;
    }

    int answer = min(*min_element(all(dp[0])), *min_element(all(dp[1])));
    cout << g[0].n + g[1].n - 2 - answer << '\n';
}