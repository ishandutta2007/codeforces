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

    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<array<int, 2>> childs(n);
    for (auto &[left, right] : childs) {
        cin >> left >> right;
        left--, right--;
    }

    vector<int> order;

    y_combinator([&](auto dfs, int v) -> void {
        if (v == -1)
            return;

        dfs(childs[v][0]);
        order.push_back(v);
        dfs(childs[v][1]);
    })(0);

    vector<bool> good(n);
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && s[order[i]] == s[order[j]])
            j++;

        if (j != n && s[order[j]] > s[order[i]])
            for (int k = i; k < j; k++)
                good[order[k]] = true;
    }

    vector<bool> paint(n);

    y_combinator([&](auto dfs, int v, int up) -> void {
        if (up > k)
            return;

        bool painted = false;
        if (childs[v][0] != -1) {
            dfs(childs[v][0], up + 1);
            painted = paint[childs[v][0]];
        }

        if (painted)
            paint[v] = true;
        else if (good[v]) {
            paint[v] = true;
            k -= up;
        }

        if (paint[v] && childs[v][1] != -1)
            dfs(childs[v][1], 1);
    })(0, 1);

    for (auto v : order)
        cout << string(1 + paint[v], s[v]);

    cout << '\n';
}