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

struct strongly_connected_component {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<std::vector<int>> reversed_g;

    strongly_connected_component(int n = 0) : n(n), g(n), reversed_g(n) {}

    int size() const {
        return n;
    }

    void add(int from, int to) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        g[from].push_back(to);
        reversed_g[to].push_back(from);
    }

    std::vector<int> scc() const {
        std::vector<int> order;
        order.reserve(n);
        std::vector<char> used(n);

        std::function<void(int)> dfs_order = [&](int v) {
            used[v] = 1;
            for (auto u : g[v])
                if (!used[u])
                    dfs_order(u);

            order.push_back(v);
        };

        for (int i = 0; i < n; i++)
            if (!used[i])
                dfs_order(i);

        std::reverse(order.begin(), order.end());

        int current_num = 0;
        std::vector<int> scc_num(n, -1);

        std::function<void(int)> dfs_fill = [&](int v) {
            scc_num[v] = current_num;
            for (auto u : reversed_g[v])
                if (scc_num[u] == -1)
                    dfs_fill(u);
        };

        for (auto i : order)
            if (scc_num[i] == -1) {
                dfs_fill(i);
                current_num++;
            }

        return scc_num;
    }
};

struct two_sat {
    int n;
    strongly_connected_component g;

    two_sat(int n = 0) : n(n), g(n << 1) {}

    int size() const {
        return n;
    }

    void add(int v, int value_v) {
        assert(0 <= value_v && value_v <= 1);
        assert(0 <= v && v < n);
        g.add((v << 1) ^ value_v ^ 1, (v << 1) ^ value_v);
    }

    void add(int v, int value_v, int u, int value_u) {
        assert(0 <= value_v && value_v <= 1 && 0 <= value_u && value_u <= 1);
        assert(0 <= v && v < n && 0 <= u && u < n);
        g.add((v << 1) ^ value_v ^ 1, (u << 1) ^ value_u);
        g.add((u << 1) ^ value_u ^ 1, (v << 1) ^ value_v);
    }

    std::vector<int> solve() const {
        const std::vector<int> scc = g.scc();
        std::vector<int> solution(n);
        for (int i = 0; i < n; i++) {
            if (scc[i << 1] == scc[i << 1 | 1])
                return std::vector<int>();

            solution[i] = scc[i << 1] < scc[i << 1 | 1];
        }
        return solution;
    }

    bool any() const {
        const std::vector<int> scc = g.scc();
        for (int i = 0; i < n; i++)
            if (scc[i << 1] == scc[i << 1 | 1])
                return false;

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int e, n, max_coord, extra_e;
    cin >> e >> n >> max_coord >> extra_e;

    two_sat g(n + max_coord);
    g.add(n, 1);
    for (int i = n + 1; i < n + max_coord; i++)
        g.add(i - 1, 1, i, 0);

    while (e--) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g.add(v, 1, u, 1);
    }

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        g.add(i, 0, n + l, 1);
        if (r != max_coord)
            g.add(i, 0, n + r, 0);
    }

    while (extra_e--) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g.add(v, 0, u, 0);
    }

    auto solution = g.solve();
    if (solution.empty()) {
        cout << "-1\n";
        return 0;
    }

    vector<int> answer;
    for (int i = 0; i < n; i++)
        if (solution[i])
            answer.push_back(i);

    int x = n;
    while (x < len(solution) && solution[x] == 1)
        x++;

    cout << len(answer) << ' ' << x - n << '\n';
    for (int i = 0; i < len(answer); i++)
        cout << answer[i] + 1 << " \n"[i == len(answer) - 1];
}