#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

struct matching {
    int n, m;
    std::vector<std::vector<int>> g;
    std::vector<int> p_left, p_right;

    matching(int n = 0, int m = 0) :
        n(n), m(m), g(n), p_left(n, -1), p_right(m, -1)
    {}

    std::pair<int, int> size() const {
        return {n, m};
    }

    void add(int left, int right) {
        g[left].push_back(right);
    }

    std::vector<int> used;
    int timer;

    bool khun(int v) {
        if (used[v] == timer)
            return false;

        used[v] = timer;
        for (auto u : g[v])
            if (p_right[u] == -1) {
                p_right[u] = v;
                p_left[v] = u;
                return true;
            }

        for (auto u : g[v])
            if (khun(p_right[u])) {
                p_right[u] = v;
                p_left[v] = u;
                return true;
            }

        return false;
    }

    int solve() {
        std::fill(p_left.begin(), p_left.end(), -1);
        std::fill(p_right.begin(), p_right.end(), -1);
        used.assign(n, 0);
        timer = 0;

        int pairs = 0;
        for (int i = 0; i < n; i++) {
            timer++;
            pairs += khun(i);
        }
        return pairs;
    }

    void dfs(int v) {
        if (used[v])
            return;

        used[v] = 1;
        for (auto u : g[v])
            if (u != p_left[v])
                dfs(p_right[u]);
    }

    std::pair<std::vector<int>, std::vector<int>> minimum_vertex_covering() {
        int pairs = solve();
        used.assign(n, 0);

        for (int i = 0; i < n; i++)
            if (p_left[i] == -1)
                dfs(i);

        std::vector<int> left;
        std::vector<bool> used_right(m);

        for (int i = 0; i < n; i++)
            if (!used[i]) {
                left.push_back(i);
            } else if (p_left[i] != -1) {
                for (auto j : g[i])
                    used_right[j] = true;
            }

        std::vector<int> right;
        for (int i = 0; i < m; i++)
            if (used_right[i])
                right.push_back(i);

        assert(int(left.size() + right.size()) == pairs);
        return std::make_pair(left, right);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));
    matching g(2 * n, 2 * n);

    for (int i = 0; i < n; i++)
        g.add(i, i + n);

    for (int i = 0; i < n; i++) {
        auto consider = [&](int value) {
            int pos = lower_bound(a.begin(), a.begin() + i, value) - a.begin();
            if (pos != i && a[pos] == value) {
                g.add(i, pos);
                g.add(i + n, pos + n);
            }
        };

        for (int j = 1; j * j <= a[i]; j++)
            if (a[i] % j == 0) {
                consider(j);
                if (j * j != a[i])
                    consider(a[i] / j);
            }
    }

    cout << g.solve() - n << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}