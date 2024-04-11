#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, int> id;
    vector<vector<int>> g;
    vector<int> initial_id;

    auto add_vertex = [&](int x) {
        auto it = id.find(x);
        if (it != id.end())
            return it->second;

        id[x] = len(g);
        g.push_back(vector<int>());
        initial_id.push_back(-1);
        return len(g) - 1;
    };

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        int smallest_bit = __builtin_ctz(value), last = -1;

        while (true) {
            int v = add_vertex(value);
            if (last == -1)
                initial_id[v] = i;
            else
                g[v].push_back(last);

            if (value == 0)
                break;

            last = v;
            if (value == (1 << smallest_bit)) {
                value = 0;
            } else {
                int largest_bit = __lg(value);
                value ^= (1 << (largest_bit + 1)) - (1 << (smallest_bit + 1));
            }
        }
    }

    for (auto &v : g) {
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
    }

    assert(id.find(0) != id.end());
    int root = id[0];

    constexpr int INF = 1e9;
    array<int, 3> answer{-INF, -1, -1};

    y_combinator([&](auto dfs, int v) -> pair<int, int> {
        pair<int, int> best{-INF, -1};
        if (initial_id[v] != -1)
            best = {0, initial_id[v]};

        for (auto u : g[v]) {
            auto current = dfs(u);
            current.first++;
            answer = max(answer, array{current.first + best.first, best.second, current.second});
            best = max(best, current);
        }
        return best;
    })(root);

    cout << answer[1] + 1 << ' ' << answer[2] + 1 << ' ' << answer[0] << '\n';
}