#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename value_t, value_t mod, typename big_t>
struct Modular {
    using mval = Modular<value_t, mod, big_t>;

    value_t val;

    template<typename T>
    static T normalize(T x, value_t m = mod) {
        if (x < -m || x >= 2 * m)
            x %= m;
        if (x >= m)
            x -= m;
        if (x < 0)
            x += m;
        return x;
    }

    template<typename T>
    static inline mval power(mval base, T degree) {
        degree = normalize(degree, mod - 1);
        mval res = 1;
        for (; degree > 0; degree >>= 1) {
            if (degree & 1)
                res *= base;
            base *= base;
        }
        return res;
    }

    inline mval rev() const {
        return power(*this, -1);
    }

    Modular() : val(0) {}
    template<typename T>
    Modular(T x) : val(normalize(x)) {}

    mval operator * (mval x) const {
        return mval(big_t(val) * big_t(x.val));
    }
    mval operator + (mval x) const {
        return mval(val + x.val);
    }
    mval operator - (mval x) const {
        return mval(val - x.val);
    }
    mval operator / (mval x) const {
        return *this * x.rev();
    }

    mval& operator *= (mval x) {
        return *this = *this * x;
    }
    mval& operator += (mval x) {
        return *this = *this + x;
    }
    mval& operator -= (mval x) {
        return *this = *this - x;
    }
    mval& operator /= (mval x) {
        return *this = *this / x;
    }

    mval& operator ++ () {
        val++;
        if (val >= mod)
            val -= mod;
        return *this;
    }
    mval& operator -- () {
        val--;
        if (val < 0)
            val += mod;
        return *this;
    }
    mval operator ++ (int) {
        val++;
        if (val >= mod)
            val -= mod;
        return *this;
    }
    mval operator -- (int) {
        val--;
        if (val < 0)
            val += mod;
        return *this;
    }

    friend istream& operator >> (istream &in, mval &val) {
        value_t x;
        in >> x;
        val = mval(x);
        return in;
    }
    friend ostream& operator << (ostream &out, mval val) {
        return out << val.val;
    }
};

constexpr int MOD = int(1e9) + 7;
// constexpr int MOD = 998244353;
using mint = Modular<int, MOD, long long>;

struct edge {
    int node;
    edge(int node = -1) : node(node) {}
};

int N;
vector<int> l, r, c;
vector<mint> inv_c;

vector<vector<edge>> g;
vector<int> dep;
vector<int> sz;

void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

void erase_edge(int from, int to) {
    for (edge &e : g[from])
        if (e.node == to) {
            swap(e, g[from].back());
            g[from].pop_back();
            return;
        }
}

struct node_info {
    int node = -1, subroot = -1;

    node_info() {}
    node_info(int node, int subroot) : node(node), subroot(subroot) {}
};

vector<node_info> nodes;

int dfs(int node, int parent = -1, int subroot = -1) {
    if (parent < 0) {
        subroot = node;
        nodes.clear();
    }
    dep[node] = parent < 0 ? 0 : dep[parent] + 1;
    sz[node] = 1;
    nodes.emplace_back(node, subroot);

    for (edge &e : g[node])
        if (e.node != parent)
            sz[node] += dfs(e.node, node, parent < 0 ? e.node : subroot);

    return sz[node];
}

int centroid(int root) {
    int n = dfs(root);
    bool found;
    do {
        found = false;
 
        for (edge &e : g[root])
            if (sz[e.node] < sz[root] && 2 * sz[e.node] >= n) {
                root = e.node;
                found = true;
                break;
            }
    } while (found);
 
    return root;
}

vector<mint> counts, depth_sums;

mint solve_one() {
    int n = nodes.size();
    vector<pair<int, int>> events(2 * n);

    for (int i = 0; i < n; i++) {
        int node = nodes[i].node;
        events[i] = {l[node], i};
        events[n + i] = {r[node], n + i};
    }

    sort(events.begin(), events.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
        return x.first < y.first;
    });

    mint total_count = 0, total_depth = 0;
    mint total_pairs = 0, total = 0;

    for (int i = 0; i < 2 * n - 1; i++) {
        int index = events[i].second;
        bool add = true;

        if (index >= n) {
            index -= n;
            add = false;
        }

        int node = nodes[index].node;
        int subroot = nodes[index].subroot;

        mint count_change = inv_c[node];
        mint depth_change = inv_c[node] * dep[node];

        if (!add) {
            count_change *= -1;
            depth_change *= -1;
        }

        counts[subroot] += count_change;
        total_count += count_change;

        depth_sums[subroot] += depth_change;
        total_depth += depth_change;

        total_pairs += count_change * (total_depth - depth_sums[subroot]);
        total_pairs += depth_change * (total_count - counts[subroot]);

        total += mint(events[i + 1].first - events[i].first) * total_pairs;
    }

    for (int i = 0; i < n; i++)
        counts[nodes[i].subroot] = depth_sums[nodes[i].subroot] = 0;

    return total;
}

mint solve(int root) {
    root = centroid(root);
    dfs(root);
    mint answer = solve_one();
    for (edge &e : g[root]) {
        erase_edge(e.node, root);
        answer += solve(e.node);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    l.resize(N);
    r.resize(N);
    c.resize(N);
    inv_c.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> l[i] >> r[i];
        l[i]--;
        c[i] = r[i] - l[i];
        inv_c[i] = mint(1) / mint(c[i]);
    }

    g.assign(N, {});
    dep.resize(N);
    sz.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        add_edge(u, v);
    }

    counts.assign(N, 0);
    depth_sums.assign(N, 0);
    mint ans = solve(0);
    for (int i = 0; i < N; i++)
        ans *= c[i];
    cout << ans << '\n';
}