#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec<vec<int>> g(n);
    vec<vec<int>> dist(n, vec<int>(n, n));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
        dist[v][u] = dist[u][v] = 1;
    }

    for (int m = 0; m < n; m++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][m] + dist[m][j]);

    vec<vec<int>> ans(n, vec<int>(n));
    for (int x = 0; x < n; x++)
        for (int y = x; y < n; y++) {
            vec<char> used(n);
            bool ok = true;
            for (int i = 0; i < n; i++)
                if (dist[x][i] + dist[i][y] == dist[x][y]) {
                    ok &= !used[dist[x][i]];
                    used[dist[x][i]] = 1;
                }
            if (!ok)
                continue;

            ans[x][y] = 1;
            for (int i = 0; i < n; i++)
                if (dist[x][i] + dist[i][y] > dist[x][y]) {
                    int now = 0;
                    for (auto j : g[i])
                        if (dist[x][j] + 1 == dist[x][i] && dist[y][j] + 1 == dist[y][i])
                            now++;
                    ans[x][y] = 1ll * ans[x][y] * now % MOD;
                }
            ans[y][x] = ans[x][y];
        }

    for (auto xs : ans) {
        for (auto x : xs)
            cout << x << ' ';
        cout << '\n';
    }
}