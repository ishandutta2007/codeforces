#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ord(n);
    iota(all(ord), 0);
    shuffle(all(ord), mt19937(239));

    vector edge(n, vector(n, -1));
    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        auto &[v, u, c] = edges[i];
        cin >> v >> u >> c;
        v--, u--;
        if (v > u) swap(v, u);
        edge[v][u] = i;
        if (c != -1) c--;
    }

    vector<vector<int>> gauss;
    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            if (edge[a][b] == -1) continue;
            for (int c = b + 1; c < n; c++) {
                if (edge[a][c] == -1 || edge[b][c] == -1) continue;
                int f = edge[a][b], s = edge[b][c], t = edge[a][c];
                gauss.push_back(vector<int>(m + 1));
                gauss.back()[f]++;
                gauss.back()[s]++;
                gauss.back()[t]++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        auto [v, u, c] = edges[i];
        if (c != -1) {
            gauss.push_back(vector<int>(m + 1));
            gauss.back()[i]++;
            gauss.back()[m] = (3 - c) % 3;
        }
    }

    if (len(gauss) < m) gauss.resize(m, vector<int>(m + 1));
    vector<bool> used(len(gauss));
    for (int i = 0; i < m; i++) {
        int pos = 0;
        while (pos < len(gauss) && (gauss[pos][i] == 0 || used[pos])) pos++;
        if (pos == len(gauss)) continue;

        swap(gauss[pos], gauss[i]);
        used[i] = true;
        for (int j = 0; j < len(gauss); j++) {
            if (i == j) continue;
            int coeff = gauss[i][i] * gauss[j][i] % 3;
            if (coeff == 0) continue;
            for (int pos = i; pos <= m; pos++) {
                gauss[j][pos] -= coeff * gauss[i][pos] % 3;
                if (gauss[j][pos] < 0) gauss[j][pos] += 3;
            }
            assert(gauss[j][i] == 0);
        }
    }

    vector<int> ans(m);
    for (int i = m - 1; i >= 0; i--) {
        if (gauss[i][i] == 0) continue;
        ans[i] = (3 - gauss[i][m]) * gauss[i][i] % 3;
    }

    for (auto &v : gauss) {
        int tot = v[m];
        for (int i = 0; i < m; i++) {
            tot += ans[i] * v[i];
        }
        if (tot % 3 != 0) {
            cout << "-1\n";
            return;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] + 1 << " \n"[i == m - 1];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}