#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1505 * 5;
char c[1505][1505];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dist[maxN][maxN];
pair < int, int > f[1505][1505];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int x = -1;
    int y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }
    queue < pair < int, int > > q;
    q.push(make_pair(x, y));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) f[i][j] = make_pair(-1e9, -1e9);
    f[x][y] = make_pair(x, y);
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        x = it.first;
        y = it.second;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int px = (nx % n + n) % n;
            int py = (ny % m + m) % m;
            if (c[px][py] == '#') continue;
            if (f[px][py].first < -1e8) {
                f[px][py] = make_pair(nx, ny);
                q.push(make_pair(nx, ny));
            }
            else if (f[px][py] != make_pair(nx, ny)) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";

    return 0;
}