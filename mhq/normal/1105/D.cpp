#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 1005;
int n, m, p;
const int maxK = 15;
int s[maxK], ans[maxK];
char c[maxN][maxN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue < pair < int, int > > q[maxK];
bool in_q[maxN][maxN][maxK];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //cin >> c[i][j];
            if (c[i][j] >= '0' && c[i][j] <= '9') {
                ans[c[i][j] - '0']++;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
                    if (c[ni][nj] != '.') continue;
                    in_q[ni][nj][c[i][j] - '0'] = true;
                    q[c[i][j] - '0'].push(make_pair(ni, nj));
                }
            }
        }
    }
    while (true) {
        bool was_upd = false;
        for (int i = 1; i <= p; i++) {
            int step = 0;
            while (true) {
                if (q[i].empty()) break;
                queue < pair < int, int > > nxt_q;
                while (!q[i].empty()) {
                    auto it = q[i].front();
                    q[i].pop();
                    int x = it.first;
                    int y = it.second;
                    if (c[x][y] != '.') continue;
                    was_upd = true;
                    ans[i]++;
                    c[x][y] = (char)(i + '0');
                    for (int j = 0; j < 4; j++) {
                        int nx = x + dx[j];
                        int ny = y + dy[j];
                        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                        if (c[nx][ny] != '.') continue;
                        if (in_q[nx][ny][i]) continue;
                        in_q[nx][ny][i] = true;
                        nxt_q.push(make_pair(nx, ny));
                    }
                }
                q[i] = nxt_q;
                if (step == s[i] - 1) break;
                step++;
            }
        }
        if (!was_upd) break;
    }
    for (int i = 1; i <= p; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}