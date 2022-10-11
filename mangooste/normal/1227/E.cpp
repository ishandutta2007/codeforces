#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;

int n, m;
vector<string> table;
const vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
const vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

bool ok(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

pair<bool, vector<string>> get(int T) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, n + m + 1));
    for (int i = -1; i <= n; i++) {
        q.push({i, -1});
        q.push({i, m});
    }
    for (int i = 0; i < m; i++) {
        q.push({-1, i});
        q.push({n, i});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j] == '.') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        int d = (!ok(x, y) ? 0 : dist[x][y]);
        q.pop();
        for (int dir = 0; dir < 8; dir++) {
            int tx = x + dx[dir];
            int ty = y + dy[dir];
            if (ok(tx, ty) && dist[tx][ty] > d + 1 && table[tx][ty] == 'X') {
                dist[tx][ty] = d + 1;
                q.push({tx, ty});
            }
        }
    }
    vector<string> current(n, string(m, '.'));
    vector<vector<int>> used(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j] == 'X') {
                if (dist[i][j] - 1 >= T) {
                    current[i][j] = 'X';
                    used[i][j] = T;
                    q.push({i, j});
                }
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        assert(used[x][y] != -1);
        if (used[x][y] == 0) {
            continue;
        }
        for (int dir = 0; dir < 8; dir++) {
            int tx = x + dx[dir];
            int ty = y + dy[dir];
            if (ok(tx, ty) && used[tx][ty] == -1) {
                assert(table[tx][ty] == 'X');
                used[tx][ty] = used[x][y] - 1;
                q.push({tx, ty});
            }
        }
    }
    bool chk = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j] == 'X') {
                chk &= (used[i][j] != -1);
            }
        }
    }
    return make_pair(chk, current);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    table.resize(n);
    for (auto &el : table) {
        cin >> el;
    }
    int L = 0, R = min(n, m) + 1;
    while (R - L > 1) {
        int mid = (L + R) / 2;
        if (get(mid).first) {
            L = mid;
        } else {
            R = mid;
        }
    }
    cout << L << '\n';
    vector<string> ans = get(L).second;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}