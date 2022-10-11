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

struct disjoin_set_union {
    vector<tuple<int, int, ll>> updates;
    vector<array<int, 2>> cnt;
    vector<int> parent;
    ll answer;

    disjoin_set_union(int n = 0) : cnt(n), parent(n), answer(0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            cnt[i][i & 1]++;
        }
    }

    int root(int v) const {
        return parent[v] == v ? v : root(parent[v]);
    }

    void unite(int v, int u) {
        v = root(v);
        u = root(u);
        if (v == u) {
            updates.emplace_back(-1, -1, -1);
            return;
        }

        if (cnt[v][0] + cnt[v][1] < cnt[u][0] + cnt[u][1])
            swap(v, u);

        ll new_answer = answer;
        new_answer -= 1ll * cnt[v][0] * cnt[v][1];
        new_answer -= 1ll * cnt[u][0] * cnt[u][1];
        new_answer += 1ll * (cnt[v][0] + cnt[u][0]) * (cnt[v][1] + cnt[u][1]);

        parent[u] = v;
        for (int j : {0, 1})
            cnt[v][j] += cnt[u][j];

        updates.emplace_back(v, u, answer);
        answer = new_answer;
    }

    void roll_back() {
        const auto [v, u, prev_answer] = updates.back();
        updates.pop_back();
        if (v == -1)
            return;

        answer = prev_answer;
        parent[u] = u;
        for (int j : {0, 1})
            cnt[v][j] -= cnt[u][j];
    }

    void roll_back(int cnt) {
        while (cnt--)
            roll_back();
    }
};

struct dynamic_connectivity_problem {
    int q, n;
    vector<vector<pair<int, int>>> tree;

    dynamic_connectivity_problem(int q, int n) : q(q), n(n), tree(4 * q) {}

    void add(int l, int r, int e1, int e2) {
        add(1, 0, q, l, r, e1, e2);
    }

    void add(int v, int vl, int vr, int l, int r, int e1, int e2) {
        if (r <= vl || vr <= l)
            return;

        if (l <= vl && vr <= r) {
            tree[v].emplace_back(e1, e2);
            return;
        }

        int vm = (vl + vr) >> 1;
        add(v << 1, vl, vm, l, r, e1, e2);
        add(v << 1 | 1, vm, vr, l, r, e1, e2);
    }

    disjoin_set_union dsu;

    void solve() {
        dsu = disjoin_set_union(n);
        solve(1, 0, q);
    }

    void solve(int v, int vl, int vr) {
        for (const auto &[v, u] : tree[v])
            dsu.unite(v, u);

        if (vr - vl == 1)
            cout << dsu.answer << " \n"[vl == q - 1];
        else {
            int vm = (vl + vr) >> 1;
            solve(v << 1, vl, vm);
            solve(v << 1 | 1, vm, vr);
        }

        dsu.roll_back(len(tree[v]));
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);

    vector<int> x_coords;
    x_coords.reserve(n);
    vector<int> y_coords;
    y_coords.reserve(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        x_coords.push_back(x[i]);
        y_coords.push_back(y[i]);
    }

    sort(all(x_coords));
    x_coords.resize(unique(all(x_coords)) - x_coords.begin());
    sort(all(y_coords));
    y_coords.resize(unique(all(y_coords)) - y_coords.begin());

    for (int i = 0; i < n; i++) {
        x[i] = lower_bound(all(x_coords), x[i]) - x_coords.begin();
        y[i] = lower_bound(all(y_coords), y[i]) - y_coords.begin();
        x[i] = x[i] << 1;
        y[i] = y[i] << 1 | 1;
    }

    const int SZ = max(len(x_coords), len(y_coords)) * 2;
    dynamic_connectivity_problem dcp(n, SZ);
    map<pair<int, int>, int> last;
    set<pair<int, int>> points;

    for (int i = 0; i < n; i++)
        if (points.count({x[i], y[i]}) == 1) {
            points.erase({x[i], y[i]});

            auto it = last.find({x[i], y[i]});
            assert(it != last.end());
            dcp.add(it->second, i, x[i], y[i]);
            last.erase(it);
        } else {
            points.insert({x[i], y[i]});
            last[{x[i], y[i]}] = i;
        }

    for (const auto &[edge, when] : last)
        dcp.add(when, n, edge.first, edge.second);

    dcp.solve();
}