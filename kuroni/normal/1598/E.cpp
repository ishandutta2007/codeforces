#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int m, n, q, czg = 0;
vector<pair<int, int>> ind[N][N];
set<int> se[4 * N];
bool chk[N][N];
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x = 1, y = i, cur = 1, ci = 0;
        czg++; se[czg].insert(0);
        while (x <= m && y <= n) {
            ind[x][y].push_back({czg, ++ci});
            x += (cur == 0); y += (cur == 1);
            cur ^= 1;
        }
        se[czg].insert(ci + 1);
    }
    for (int i = 1; i <= m; i++) {
        int x = i, y = 1, cur = 0, ci = 0;
        czg++; se[czg].insert(0);
        while (x <= m && y <= n) {
            ind[x][y].push_back({czg, ++ci});
            x += (cur == 0); y += (cur == 1);
            cur ^= 1;
        }
        se[czg].insert(ci + 1);
    }
    auto solve = [](int le, int ri) {
        int sz = ri - le - 1;
        return 1LL * sz * (sz - 1) / 2;
    };
    ans = 1LL * m * n;
    for (int i = 1; i <= czg; i++) {
        int le = *se[i].begin(), ri = *prev(se[i].end());
        ans += solve(le, ri);
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        for (auto [zg, i] : ind[u][v]) {
            if (!chk[u][v]) {
                auto it = se[zg].lower_bound(i);
                int le = *prev(it), ri = *it;
                ans += solve(le, i) + solve(i, ri) - solve(le, ri);
                se[zg].insert(i);
            } else {
                se[zg].erase(i);
                auto it = se[zg].lower_bound(i);
                int le = *prev(it), ri = *it;
                ans -= solve(le, i) + solve(i, ri) - solve(le, ri);
            }
        }
        ans -= (1 - chk[u][v]);
        chk[u][v] ^= 1;
        ans += (1 - chk[u][v]);
        cout << ans << '\n';
    }
}