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
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m, 0)), kek_table(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char cur;
            cin >> cur;
            if (cur == '#') {
                table[i][j] = kek_table[j][i] = 1;
            }
        }
    }
    bool fnd_row = false;
    for (int i = 0; i < n; i++) {
        if (accumulate(all(table[i]), 0) == 0) {
            fnd_row = true;
        }
    }
    bool fnd_col = false;
    for (int i = 0; i < m; i++) {
        if (accumulate(all(kek_table[i]), 0) == 0) {
            fnd_col = true;
        }
    }
    if (fnd_col ^ fnd_row) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (table[i][j] && (j == 0 || table[i][j - 1] == 0)) {
                cnt++;
            }
        }
        if (cnt > 1) {
            cout << "-1\n";
            return 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (kek_table[i][j] && (j == 0 || kek_table[i][j - 1] == 0)) {
                cnt++;
            }
        }
        if (cnt > 1) {
            cout << "-1\n";
            return 0;
        }
    }
    const vector<int> dx = {1, -1, 0, 0};
    const vector<int> dy = {0, 0, 1, -1};
    vector<vector<char>> used(n, vector<char>(m, 0));
    Fun<void(int, int)> Dfs = [&](int x, int y) {
        used[x][y] = 1;
        for (int d = 0; d < 4; d++) {
            int tx = x + dx[d];
            int ty = y + dy[d];
            if (0 <= tx && tx < n && 0 <= ty && ty < m && table[tx][ty] && !used[tx][ty]) {
                Dfs(tx, ty);
            }
        }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j] && table[i][j]) {
                ans++;
                Dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
}