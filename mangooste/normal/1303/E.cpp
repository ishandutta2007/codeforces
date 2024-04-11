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
        string s, t;
        cin >> s >> t;
        int sz = s.size();
        vector<vector<int>> next(sz, vector<int>(26, -1));
        next[sz - 1][s[sz - 1] - 'a'] = sz - 1;
        for (int i = sz - 2; i >= 0; i--) {
            next[i] = next[i + 1];
            next[i][s[i] - 'a'] = i;
        }
        Fun<bool(string, string)> Check = [&](string a, string b) {
            int n = a.size(), m = b.size();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, sz));
            dp[0][0] = -1;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    if (i + j == 0) {
                        continue;
                    }
                    if (i != 0) {
                        int pos = dp[i - 1][j] + 1;
                        if (pos < sz && next[pos][a[i - 1] - 'a'] != -1) {
                            dp[i][j] = min(dp[i][j], next[pos][a[i - 1] - 'a']);
                        }
                    }
                    if (j != 0) {
                        int pos = dp[i][j - 1] + 1;
                        if (pos < sz && next[pos][b[j - 1] - 'a'] != -1) {
                            dp[i][j] = min(dp[i][j], next[pos][b[j - 1] - 'a']);
                        }
                    }
                }
            }
            return dp[n][m] != sz;
        };
        bool fnd = false;
        for (int i = 0; i <= t.size(); i++) {
            if (Check(t.substr(0, i), t.substr(i, t.size() - i))) {
                fnd = true;
                break;
            }
        }
        cout << (fnd ? "YES\n" : "NO\n");
    }
}