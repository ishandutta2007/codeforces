#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxK = 1005;
const int maxN = 12;
int n, m, k, w;
char lvl[maxK][maxN][maxN];
int dist[maxK][maxK];
const int INF = (int)1e9;
pair < int, int > mn_ed[maxK];
bool used[maxK];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k >> w;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t < m; t++) {
                cin >> lvl[i][j][t];
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = i + 1; j <= k; j++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    dist[i][j] += (lvl[i][x][y] != lvl[j][x][y]);
                }
            }
            dist[i][j] *= w;
            dist[j][i] = dist[i][j];
        }
    }
    for (int i = 1; i <= k; i++) {
        dist[0][i] = dist[i][0] = n * m;
    }
    vector < pair < int, int > > ans;
    for (int i = 1; i <= k; i++) {
        mn_ed[i] = make_pair(dist[0][i], 0);
    }
    used[0] = true;
    int val = 0;
    for (int iter = 0; iter < k; iter++) {
        pair < int, int > best = make_pair(INF, -1);
        for (int i = 1; i <= k; i++) {
            if (!used[i]) best = min(best, make_pair(mn_ed[i].first, i));
        }
        int v = best.second;
        used[v] = true;
        val += best.first;
        ans.emplace_back(v, mn_ed[v].second);
        for (int i = 1; i <= k; i++) {
            if (!used[i] && dist[i][v] < mn_ed[i].first) {
                mn_ed[i] = make_pair(dist[i][v], v);
            }
        }
    }
    cout << val << '\n';
    for (auto it : ans) cout << it.first << " " << it.second << '\n';
    return 0;
}