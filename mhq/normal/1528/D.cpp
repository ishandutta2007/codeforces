#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 605;
ll dist[maxN][maxN];
ll travel[maxN][maxN];
bool used[maxN];
ll mn[2 * maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = 1e17;
            travel[i][j] = 1e17;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        travel[a][b] = c;
    }
    for (int start = 0; start < n; start++) {
        dist[start][start] = 0;
        memset(used, 0, sizeof used);
        for (int iter = 0; iter < n; iter++) {
            int who = -1;
            for (int x = 0; x < n; x++) {
                if (!used[x] && (who == -1 || dist[start][x] < dist[start][who])) who = x;
            }
            assert(who !=- 1);
            used[who] = true;
            for (int r = 0; r < 2 * n; r++) {
                mn[r] = 1e18;
            }
            for (int where = 0; where < n; where++) {
                if (travel[who][where] < 1e10) {
                    int to = (where + dist[start][who]) % n;
                    mn[to] = min(mn[to], dist[start][who] + travel[who][where]);
                }
            }
            ll cur = 1e18;
            for (int r = 0; r < 2 * n; r++) {
                cur++;
                cur = min(cur, mn[r]);
                if (r >= n) {
                    dist[start][r - n] = min(dist[start][r - n], cur);
                }
                else {
                    dist[start][r] = min(dist[start][r], cur);
                }
            }
        }
        for (int x = 0; x < n; x++) {
            cout << dist[start][x] << " ";
        }
        cout << '\n';
    }
    return 0;
}