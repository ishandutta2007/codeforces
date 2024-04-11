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

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    array<int, 2> sizes;
    cin >> n >> sizes[0] >> sizes[1];

    array<vector<int>, 2> parent;
    parent.fill(vector<int>(n));
    for (int j : {0, 1})
        iota(all(parent[j]), 0);

    array<vector<set<int>>, 2> components;
    components.fill(vector<set<int>>(n));
    for (int j : {0, 1})
        for (int i = 0; i < n; i++)
            components[j][i].insert(i);

    array<set<pair<int, int>>, 2> roots;
    for (int j : {0, 1})
        for (int i = 0; i < n; i++)
            roots[j].emplace(1, i);

    auto root = y_combinator([&](auto root, int id, int v) -> int {
        return parent[id][v] == v ? v : parent[id][v] = root(id, parent[id][v]);
    });

    auto unite = [&](int id, int v, int u) {
        v = root(id, v);
        u = root(id, u);
        assert(v != u);

        if (len(components[id][v]) < len(components[id][u]))
            swap(v, u);

        roots[id].erase({len(components[id][v]), v});
        roots[id].erase({len(components[id][u]), u});

        parent[id][u] = v;
        for (auto x : components[id][u])
            components[id][v].insert(x);

        roots[id].emplace(len(components[id][v]), v);
        set<int>().swap(components[id][u]);
    };

    for (int j : {0, 1})
        for (int i = 0; i < sizes[j]; i++) {
            int v, u;
            cin >> v >> u;
            v--, u--;
            unite(j, v, u);
        }

    vector<pair<int, int>> answer;
    for (int it = 0; it < n - 1 - max(sizes[0], sizes[1]); it++) {
        int current_root = roots[0].begin()->second;

        for (auto x : components[0][current_root]) {
            int root_x = root(1, x);
            roots[1].erase({len(components[1][root_x]), root_x});
            roots[1].emplace(0, *components[1][root_x].begin());
        }

        for (auto x : components[0][current_root]) {
            int root_x = root(1, x);
            roots[1].erase({0, *components[1][root_x].begin()});
            components[1][root_x].erase(x);

            if (len(components[1][root_x]))
                roots[1].emplace(0, *components[1][root_x].begin());
        }

        assert(!roots[1].empty());
        int first = -1, second = -1;

        for (auto x : components[0][current_root]) {
            int candidate = roots[1].begin()->second;
            if (root(1, candidate) == root(1, x)) {
                if (len(roots[1]) == 1)
                    continue;

                candidate = next(roots[1].begin())->second;
            }

            assert(root(1, candidate) != root(1, x));
            first = x, second = candidate;
            break;
        }
        assert(first != -1);

        for (auto x : components[0][current_root]) {
            int root_x = root(1, x);
            if (len(components[1][root_x]))
                roots[1].erase({0, *components[1][root_x].begin()});

            components[1][root_x].insert(x);
            roots[1].emplace(0, *components[1][root_x].begin());
        }

        for (auto x : components[0][current_root]) {
            int root_x = root(1, x);
            roots[1].erase({0, *components[1][root_x].begin()});
            roots[1].emplace(len(components[1][root_x]), root_x);
        }

        answer.emplace_back(first, second);
        for (int j : {0, 1})
            unite(j, first, second);
    }

    cout << len(answer) << '\n';
    for (const auto &[v, u] : answer)
        cout << v + 1 << ' ' << u + 1 << '\n';
}