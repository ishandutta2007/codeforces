//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[10][10][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            for (int i = 0; i < 10; i++) {
                dp[x][y][i] = INT32_MAX;
            }
        }
    }
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            for (int i = 0; i <= 100; i++) {
                for (int j = 0; j <= 100; j++) {
                    if (i + j == 0) {
                        continue;
                    }
                    dp[x][y][(x * i + y * j) % 10] = min(dp[x][y][(x * i + y * j) % 10], i + j);
                }
            }
        }
    }
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            int ans = 0;
            for (int i = 1; i < n; i++) {
                int t = s[i] - s[i - 1];
                if (t < 0) {
                    t += 10;
                }
                if (dp[x][y][t] == INT32_MAX) {
                    ans = -1;
                    break;
                }
                ans += dp[x][y][t] - 1;
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}