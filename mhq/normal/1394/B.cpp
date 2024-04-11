#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, k;
const int maxN = 2e5 + 10;
vector < pair < int, int > > from[maxN];
vector < pair < int, int > > to[maxN];
const int maxT = 10;
bool bad[maxT][maxT][maxT][maxT];
bool he_bad[maxT][maxT];
int ans = 0;
int who[maxT];
void rec(int v) {
    if (v == (k + 1)) {
        ans++;
        return;
    }
    for (int i = 1; i <= v; i++) {
        if (he_bad[v][i]) continue;
        who[v] = i;
        bool can = true;
        for (int j = 1; j < v; j++) {
            if (bad[v][i][j][who[j]]) {
                can = false;
                break;
            }
        }
        if (can) rec(v + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        from[u].emplace_back(w, v);
        to[v].emplace_back(w, u);
    }
    for (int i = 1; i <= n; i++) {
        sort(from[i].begin(), from[i].end());
    }
    for (int i = 1; i <= n; i++) {
        vector < pair < int, int > > all;
        for (auto& it : to[i]) {
            int we = it.first;
            int who = it.second;
            int id = lower_bound(from[who].begin(), from[who].end(), make_pair(we, -1)) - from[who].begin();
            assert(from[who][id].first == we);
            all.emplace_back(from[who].size(), id + 1);
        }
        sort(all.begin(), all.end());
        for (int c = 0; c + 1 < all.size(); c++) {
            if (all[c] == all[c + 1]) {
                he_bad[all[c].first][all[c].second] = true;
            }
        }
        all.erase(unique(all.begin(), all.end()), all.end());
        for (int c = 0; c < all.size(); c++) {
            for (int d = c + 1; d < all.size(); d++) {
                bad[all[d].first][all[d].second][all[c].first][all[c].second] = true;
            }
        }
    }
    rec(1);
    cout << ans;
    return 0;
}