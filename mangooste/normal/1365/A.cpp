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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m));
    bool fnd = false;
    int cnt = 0;
    for (auto &i : table) {
        for (auto &el : i) {
            cin >> el;
        }
    }
    vector<int> row(n, 1), col(m, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j]) {
                row[i] = col[j] = 0;
            }
        }
    }
    int empty_row = 0, empty_col = 0;
    for (int i = 0; i < n; i++) {
        if (row[i]) {
            empty_row++;
        }
    }
    for (int i = 0; i < m; i++) {
        if (col[i]) {
            empty_col++;
        }
    }
    cout << (min(empty_col, empty_row) % 2 ? "Ashish\n" : "Vivek\n");
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