#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

struct matching {
    int n, m;
    std::vector<std::vector<int>> g;
    std::vector<int> p_left;
    std::vector<int> p_right;

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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c == 'B' ? 1 : 0;
        }

    int tot = 0;
    vector<vector<bool>> used(n, vector<bool>(m));

    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--) {
            int sum = 0;
            if (i + 1 < n && j + 1 < m)
                sum ^= a[i + 1][j + 1];

            if (i + 1 < n)
                sum ^= a[i + 1][j];

            if (j + 1 < m)
                sum ^= a[i][j + 1];

            if (sum ^ a[i][j]) {
                sum ^= 1;
                tot++;
                used[i][j] = true;
            }

            a[i][j] = sum;
        }

    matching mat(n - 1, m - 1);
    bool any = false;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
            if (used[i][j] && used[n - 1][j] && used[i][m - 1]) {
                mat.add(i, j);
                any = true;
            }

    int sz = mat.solve();
    cout << tot - used[n - 1][m - 1] - sz + (used[n - 1][m - 1] ^ (sz & 1)) << '\n';
}