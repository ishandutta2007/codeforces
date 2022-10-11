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
vector<vector<int>> used;
const vector<int> dx = {1, -1, 0, 0};
const vector<int> dy = {0, 0, 1, -1};

bool ok(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y) {
    used[x][y] = 1;
    for (int dir = 0; dir < 4; dir++) {
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        if (ok(xx, yy) && table[xx][yy] != '#' && !used[xx][yy]) {
            dfs(xx, yy);
        }
    }
}

void solve() {
    table.clear();
    used.clear();
    cin >> n >> m;
    table.resize(n);
    for (auto &el : table) {
        cin >> el;
    }
    bool any_good = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j] == 'G') {
                any_good = true;
            }
        }
    }
    if (!any_good) {
        cout << "YES\n";
        return;
    }
    bool chk = true;
    chk &= (table[n - 1][m - 1] != 'B');
    table[n - 1][m - 1] = 'G';
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (table[x][y] != 'B') {
                continue;
            }
            for (int dir = 0; dir < 4; dir++) {
                int xx = x + dx[dir];
                int yy = y + dy[dir];
                if (!ok(xx, yy)) {
                    continue;
                }
                chk &= (table[xx][yy] != 'G');
                if (table[xx][yy] == '.') {
                    table[xx][yy] = '#';
                }
            }
        }
    }
    chk &= (table[n - 1][m - 1] == 'G');
    used.resize(n, vector<int>(m, 0));
    dfs(n - 1, m - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j] == 'G') {
                chk &= (used[i][j]);
            }
        }
    }
    cout << (chk ? "YES\n" : "NO\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}