#include<bits/stdc++.h>
using namespace std;
const int nax = 300000 + 10;
const int INF = 1e9;
int n, m;

template <typename T>
using min_heap = priority_queue<T, vector <T>, greater<T>>;


void solve() {
    cin >> n >> m;
    vector <string> s(n);
    vector <vector <char>> deg(n, vector <char>(m, 0));

    for (int i = 0 ; i < n ; ++ i)
        cin >> s[i];

    auto inside = [&](int i, int j) -> bool {
        return !(i < 0 || i >= n || j < 0 || j >= m);
    };

    auto usable = [&](int i, int j) -> bool {
        if (!inside(i, j)) return false;
        if (deg[i][j] > 0) return false;
        return true;
    };

    vector <int> di = {-1, 0, 1, 0};
    vector <int> dj = {0, -1, 0, 1};

    for (int i = 0 ; i < n ; ++ i)
    for (int j = 0 ; j < m ; ++ j) {
        if (s[i][j] == '#') {
            for (int k = 0 ; k < 4 ; ++ k) {
                int ni = i + di[k], nj = j + dj[k];
                if (!inside(ni, nj)) continue;
                deg[ni][nj] += 1;
            }
        }
    }
//
//    for (int i = 0 ; i < n ; ++ i, cout << '\n')
//    for (int j = 0 ; j < m ; ++ j) {
//        cout << int(usable(i, j));
//    }

    const int INF = 1e9;

    min_heap <tuple <int, int, int>> pq;
    vector <vector <int>> dist(n, vector <int>(m, INF));

    for (int i = 0 ; i < n ; ++ i) {
        if (!usable(i, 0)) continue;
        dist[i][0] = 1 - (s[i][0] == '#');
        pq.emplace(dist[i][0], i, 0);
    }

    vector <vector <pair <int, int>>> to_parent(n, vector <pair <int, int>>(m));

    while (!pq.empty()) {
        auto [d, i, j] = pq.top();
        pq.pop();
        if (d > dist[i][j]) continue;
        for (int dj: {-1, 1}) 
        for (int di : {-1, 1}) {
            if (!usable(i + di, j + dj)) continue;
            int &v = dist[i + di][j + dj];
            if (d + (s[i + di][j + dj] != '#') < v) {
                v = d + (s[i + di][j + dj] != '#');
                pq.emplace(v, i + di, j + dj);
                to_parent[i + di][j + dj] = make_pair(i, j);
            }
        }
    }
    pair <int, int> min_dist = make_pair(INF, INF);

    for (int i = 0 ; i < n ; ++ i) {
        min_dist = min(min_dist, make_pair(dist[i][m - 1], i));
    }
    if (min_dist.first == INF) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";// << min_dist.second << '\n';
    int x = min_dist.second, y = m - 1;

    while (y >= 0) {
        s[x][y] = '#';
        tie(x, y) = to_parent[x][y];
        if (y == 0) {
            s[x][y] = '#';
            break;
        }
    }

    for (int i = 0 ; i < n ; ++ i)
        cout << s[i] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}