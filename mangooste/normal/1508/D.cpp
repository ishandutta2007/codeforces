#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template <typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun &&fun) : fun(std::forward<const Fun>(fun)) {}

    template <typename... Args>
    auto operator()(Args &&...args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

struct point {
    int x, y;

    point operator-(const point &p) const {
        return {x - p.x, y - p.y};
    }

    bool operator<(const point &p) const {
        return pair{x, y} < pair{p.x, p.y};
    }

    ll operator%(const point &p) const {
        return 1ll * x * p.y - 1ll * y * p.x;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> ord;
    vector<point> p(n);
    vector<int> to(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y >> to[i];
        to[i]--;
        if (to[i] == i) continue;
        ord.push_back(i);
    }

    if (ord.empty()) {
        cout << "0\n";
        return 0;
    }

    int mn = ord[0];
    for (int i = 1; i < len(ord); i++) {
        if (p[ord[i]] < p[mn]) {
            mn = ord[i];
        }
    }

    rotate(ord.begin(), find(all(ord), mn), ord.end());
    sort(1 + all(ord), [&](const int a, const int b) {
        return (p[a] - p[mn]) % (p[b] - p[mn]) > 0;
    });

    vector<pair<int, int>> ops;
    auto make_op = [&](int i, int j) {
        swap(to[i], to[j]);
        ops.emplace_back(i, j);
    };

    vector<int> par(n);
    iota(all(par), 0);

    auto root = y_combinator([&](auto root, int v) -> int {
        return par[v] == v ? v : par[v] = root(par[v]);
    });

    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        for (int j = i; !used[j]; j = to[j]) {
            par[root(j)] = root(i);
            used[j] = true;
        }
    }

    for (int i = 1; i < len(ord) - 1; i++) {
        int r1 = root(ord[i]), r2 = root(ord[i + 1]);
        if (r1 == r2) continue;
        make_op(ord[i], ord[i + 1]);
        par[r1] = r2;
    }

    fill(all(used), false);
    vector<int> path;
    for (int i = mn; !used[i]; i = to[i]) {
        path.push_back(i);
        used[i] = true;
    }
    for (int j = 1; j < len(path); j++) {
        make_op(mn, path[j]);
    }

    for (int i = 0; i < n; i++) {
        assert(to[i] == i);
    }
    cout << len(ops) << '\n';
    for (auto [i, j] : ops) {
        cout << i + 1 << ' ' << j + 1 << '\n';
    }
}