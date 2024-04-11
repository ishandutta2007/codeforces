#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <unordered_set>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < n; ++i)
 
using ll = long long;
using ull = unsigned long long;
 
const int mod = 1000000000 + 7;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    bool f[2000][2000];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            f[i][j] = (c == 'R');
        }
    }
 
    if (n == 1 && m == 1) {
        cout << 1 << "\n";
        return 0;
    }
 
    vector<vector<int>> rocks_right(2001, vector<int>(2001, 0)), rocks_down(2001, vector<int>(2001, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            rocks_right[i][j] = f[i][j] + rocks_right[i][j + 1];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            rocks_down[j][i] = f[j][i] + rocks_down[j + 1][i];
        }
    }
 
    vector<vector<int>> sum_down(n + 1, vector<int>(m + 1, 0)), sum_right(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp_right(n, vector<int>(m, 0)), dp_down(n, vector<int>(m, 0));
    dp_right[n - 1][m - 1] = 1;
    dp_down[n - 1][m - 1] = 1;
    sum_right[n - 1][m - 1] = 1;
    sum_down[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i == n - 1 && j == m - 1) {
                continue;
            }
            dp_right[i][j] = (sum_right[i][j + 1] - sum_right[i][m - rocks_right[i][j + 1]] + mod) % mod;
            dp_down[i][j] = (sum_down[i + 1][j] - sum_down[n - rocks_down[i + 1][j]][j] + mod) % mod;
 
            sum_right[i][j] = (dp_down[i][j] + sum_right[i][j + 1]) % mod;
            sum_down[i][j] = (dp_right[i][j] + sum_down[i + 1][j]) % mod;
        }
    }
    cout << (dp_right[0][0] + dp_down[0][0]) % mod << "\n";
}