#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 205;
vector<pair<int,int>> g[maxN];
int d[maxN][maxN];
int dist[maxN];
int ans[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
//            g[i].clear();
        for (int j = 1; j <= n; j++) {
            d[i][j] = -2;
        }
    }
    vector<pair<pair<int,int>,int>> edges;
    for (int i = 1; i <= m; i++) {
        int x, y, b;
        cin >> x >> y >> b;
        if (b == 1) {
            edges.emplace_back(make_pair(x, y), +1);
            edges.emplace_back(make_pair(y, x), -1);
            d[x][y] = 1;
        } else {
            edges.emplace_back(make_pair(x, y), +1);
            edges.emplace_back(make_pair(y, x), +1);
//            g[x].emplace_back(y);
//            g[y].emplace_back(x);
            d[x][y] = 0;
        }
    }
    int val = -1e9;
    for (int who = 1; who <= n; who++) {
        for (int j = 1; j <= n; j++) {
            dist[j] = 1e9;
        }
        dist[who] = 0;
        for (int iter = 1; iter <= 2 * n; iter++) {
            bool ch = false;
            for (auto& it : edges) {
                if (dist[it.first.second] > dist[it.first.first] + it.second) {
                    ch = true;
                    dist[it.first.second] = dist[it.first.first] + it.second;
                }
            }
            if (!ch) break;
        }
        bool ok = true;
        for (int x = 1; x <= n; x++) {
            if (dist[x] < 0) ok = false;
            for (int y = 1; y <= n; y++) {
                if (d[x][y] == -2) continue;
                if (d[x][y] == 0 && abs(dist[x] - dist[y]) != 1) ok = false;
                if (d[x][y] == 1 && dist[y] - dist[x] != 1) ok = false;
            }
        }
        if (ok) {
            int mx = 0;
            for (int j = 1; j <= n; j++) mx = max(mx, dist[j]);
            if (mx > val) {
                val = mx;
                for (int j = 1; j <= n; j++) {
                    ans[j] = dist[j];
                }
            }
        }
    }
    if (val < -100) {
        cout << "NO\n";
    } else {
        cout << "YES\n" << val << '\n';
        for (int j = 1; j <= n; j++) cout << ans[j] << " ";
        cout << '\n';
    }

    return 0;
}