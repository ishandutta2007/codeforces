#include <bits/stdc++.h>

using namespace std;
//#pragma GCC optimize("O3")

typedef long long ll;
typedef long double ld;
int n, m, t;
const int maxN = 1005;
char c[maxN][maxN];
int dist[maxN][maxN];
int mom[maxN][maxN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main() {
  //  freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    memset(mom, -1, sizeof mom);
    for (int clr = 0; clr < 1; clr++) {
        memset(dist, -1, sizeof dist);
        queue < pair < int, int > > q;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                bool ok = true;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                    if (c[i][j] == c[nx][ny]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    dist[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                mom[i][j] = dist[i][j];
            }
        }
    }
    for (int it = 1; it <= t; it++) {
        int i, j;
        ll p;
        cin >> i >> j >> p;
        if (dist[i][j] == -1) {
            cout << c[i][j] << '\n';
        }
        else {
            if (p <= mom[i][j]) {
                cout << c[i][j] << '\n';
            }
            else if ((p - mom[i][j]) % 2 == 0) {
                cout << c[i][j] << '\n';
            }
            else {
                cout << ((char)(('0' ^ '1') ^ c[i][j])) << '\n';
                }
            }
    }
    return 0;
}