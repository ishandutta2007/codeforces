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

struct disjoin_set_union {
    int components;
    std::vector<int> parent, rank;

    disjoin_set_union(int n = 0) : components(n), parent(n), rank(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int size() const {
        return rank.size();
    }

    void set_default() {
        components = size();
        std::fill(rank.begin(), rank.end(), 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int root(int v) {
        return (v ^ parent[v]) == 0 ? v : parent[v] = root(parent[v]);
    }

    bool unite(int v, int u) {
        v = root(v), u = root(u);
        if (v == u)
            return false;

        if (rank[v] < rank[u])
            std::swap(v, u);

        rank[v] += rank[u];
        parent[u] = v;
        components--;
        return true;
    }

    bool connected(int v, int u) {
        return root(v) == root(u);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &s : a) cin >> s;

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] == '1' && a[i + 1][j] == '1' && a[i][j + 1] == '1' && a[i + 1][j + 1] == '1') {
                ans = 4;
            }
        }
    }
    
    const vector dx{1, 0, -1, 0};
    const vector dy{0, 1, 0, -1};
 
    auto check_cell = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };

    disjoin_set_union dsu(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '0') continue;
            for (int d = 0; d < 4; d++) {
                int ii = i + dx[d], jj = j + dy[d];
                if (check_cell(ii, jj) && a[ii][jj] == '1') {
                    dsu.unite(i * m + j, ii * m + jj);
                }
            }
        }
    }

    vector used(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1' || used[i][j]) continue;
            set<pair<int, int>> cells;
            
            y_combinator([&](auto dfs, int x, int y) -> void {
                cells.emplace(x, y);
                assert(!used[x][y]);
                used[x][y] = true;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        int xx = x + dx, yy = y + dy;
                        if (check_cell(xx, yy) && a[xx][yy] == '0' && !used[xx][yy]) {
                            dfs(xx, yy);
                        }
                    }
                }
            })(i, j);

            set<pair<int, int>> st;
            bool ok = true;
            for (auto [x, y] : cells) {
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        if (!check_cell(x + dx, y + dy)) {
                            ok = false;
                            break;
                        }
                        if (cells.count({x + dx, y + dy})) continue;
                        if (a[x + dx][y + dy] != '1') {
                            ok = false;
                            break;
                        }
                        st.emplace(x + dx, y + dy);
                    }
                }
                if (!ok) break;
            }
            if (!ok) continue;

            auto [any_x, any_y] = *st.begin();
            for (auto &[x, y] : st) {
                if (!dsu.connected(x * m + y, any_x * m + any_y)) {
                    ok = false;
                    break;
                }
                int cnt = 0;
                for (int d = 0; d < 4; d++) {
                    cnt += st.count({x + dx[d], y + dy[d]});
                }
                if (cnt != 2) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans = max(ans, len(st));
        }
    }
    cout << ans << '\n';
}