#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    vector<vector<char>> dp(n, vector<char>(m, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j != 0 && a[i][j] != '#') {
                if (i > 0 && dp[i - 1][j]) {
                    dp[i][j] = 1;
                }
                if (j > 0 && dp[i][j - 1]) {
                    dp[i][j] = 1;
                }
            }
        }
    }
    if (dp[n - 1][m - 1] == 0) {
        cout << "0\n";
    } else if (n == 1 || m == 1) {
        cout << "1\n";
    } else {
        queue<pii> q;
        q.push(mp(n - 1, m - 1));
        vector<vector<char>> used(n, vector<char>(m, 0));
        used[n - 1][m - 1] = 1;
        bool fnd = false;
        while (!q.empty()) {
            if (q.front() != mp(0, 0) && q.front() != mp(n - 1, m - 1) && q.size() == 1) {
                fnd = true;
            }
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x > 0 && dp[x - 1][y] && !used[x - 1][y]) {
                q.push(mp(x - 1, y));
                used[x - 1][y] = 1;
            }
            if (y > 0 && dp[x][y - 1] && !used[x][y - 1]) {
                q.push(mp(x, y - 1));
                used[x][y - 1] = 1;
            }
        }
        cout << (fnd ? "1\n" : "2\n");
    }
}