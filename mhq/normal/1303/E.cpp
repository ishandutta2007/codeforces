#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 405;
int dp[maxN][maxN];
string s;
string t;
const int INF = (int)1e9;
int nxt[maxN][26];
void solve() {
    cin >> s >> t;
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            nxt[i][j] = nxt[i + 1][j];
            if (i == s.size() - 1) nxt[i][j] = s.size() + 10;
            if (s[i] == j + 'a') nxt[i][j] = i;
        }
    }
    for (int len = 1; len <= t.size(); len++) {
        int n = t.size();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i <= len; i++) {
            for (int j = 0; j <= n - len; j++) {
                if (i && dp[i - 1][j] < s.size()) {
                    dp[i][j] = min(nxt[dp[i - 1][j]][t[i - 1] - 'a'] + 1, dp[i][j]);
                }
                if (j && dp[i][j - 1] < s.size()) {
                    dp[i][j] = min(nxt[dp[i][j - 1]][t[len + j - 1] - 'a'] + 1, dp[i][j]);
                }
            }
        }
        if (dp[len][n - len] <= s.size() + 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
   // freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
       solve();
    }
    return 0;
}