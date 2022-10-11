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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> col(n, vector<int>(m));
        for (auto &i : col) {
            for (auto &el : i) {
                char cur;
                cin >> cur;
                el = cur - '0';
            }
        }
        vector<string> table(n);
        for (auto &el : table) {
            cin >> el;
        }
        vector<vector<pair<int, int>>> where(n, vector<pair<int, int>>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (table[i][j] == 'L') {
                    where[i][j] = mp(i, j - 1);
                } else if (table[i][j] == 'R') {
                    where[i][j] = mp(i, j + 1);
                } else if (table[i][j] == 'U') {
                    where[i][j] = mp(i - 1, j);
                } else {
                    where[i][j] = mp(i + 1, j);
                }
            }
        }
        const int LOG = 22;
        for (int level = 1; level < LOG; level++) {
            vector<vector<pair<int, int>>> new_where(n, vector<pair<int, int>>(m));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int x = where[i][j].first, y = where[i][j].second;
                    new_where[i][j] = where[x][y];
                }
            }
            swap(where, new_where);
        }
        int cnt = 0, black = 0;
        vector<vector<char>> used(n, vector<char>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (col[i][j] == 0) {
                    int x = where[i][j].first, y = where[i][j].second;
                    if (!used[x][y]) {
                        used[x][y] = 1;
                        black++;
                        cnt++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (col[i][j] == 1) {
                    int x = where[i][j].first, y = where[i][j].second;
                    if (!used[x][y]) {
                        used[x][y] = 1;
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << ' ' << black << '\n';
    }
}