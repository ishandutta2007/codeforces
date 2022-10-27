#include<bits/stdc++.h>
using namespace std;
const int nax = 5e5 + 10;
const int64_t INF = 1e17;
template <typename T>
using min_heap = priority_queue <T, vector <T>, greater<T>>;

int n, m;
string s[nax];
int64_t p, q;
int64_t cost[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    cin >> cost[1] >> cost[0];

    for (int i = 0 ; i < n ; ++ i) {
        cin >> s[i];
    }

    vector <vector <int64_t>> dist(n, vector <int64_t>(m, INF));

    min_heap <tuple <int64_t, int, int>> pq;

    auto inside = [&](int i, int j) -> bool {
        return !(i < 0 || i >= n || j < 0 || j >= m);
    };



    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < m ; ++ j) {
            if (s[i][j] == '.') {
                pq.emplace(0, i, j);
                dist[i][j] = 0;
            }
        }
    }

    const vector <int> di[2] = {
        {0, 0, -2, 2},
        {-1, 1, -1, 1}
    };
    const vector <int> dj[2] = {
        {-2, 2, 0, 0},
        {-1, -1, 1, 1}
    };
    const vector <string> ac[2] = {
        {"L", "R", "U", "D"},
        {"LU", "DL", "UR", "RD"}
    };

    while (!pq.empty()) {

        auto [d, i, j] = pq.top();
        pq.pop();
        if (d > dist[i][j]) continue;

        for (int k = 0 ; k < 2 ; ++ k) {
            for (int v = 0 ; v < 4 ; ++ v) {
                int ni = i + di[k][v], nj = j + dj[k][v];
                if (!inside(ni, nj)) continue;
                bool ok = false;
                for (char x : ac[k][v]) if (x == s[ni][nj]) ok = true;
                if (ok && d + cost[k] < dist[ni][nj]) {
                    dist[ni][nj] = d + cost[k];
                    pq.emplace(dist[ni][nj], ni, nj);
                }
            }
        }
    }

    int64_t ans = INF;

    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < m ; ++ j) {
            if (i + 1 < n) {
                ans = min(ans, dist[i][j] + dist[i + 1][j]);
            }
            if (j + 1 < m)
                ans = min(ans, dist[i][j] + dist[i][j + 1]);
        }
    }
    if (ans == INF) ans = -1;

    cout << ans << '\n';

}
/*
    div1
*/