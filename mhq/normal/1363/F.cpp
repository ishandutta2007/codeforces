#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s, t;
const int maxN = 2000 + 10;
int cntA[maxN][26];
int cntB[maxN][26];
int dp[maxN][maxN];
int n;
void solve() {
    cin >> n;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            cntA[i + 1][j] = cntA[i][j] + ((s[i] - 'a') == j);
            cntB[i + 1][j] = cntB[i][j] + ((t[i] - 'a') == j);
        }
    }
    bool ok = true;
    for (int i = 0; i < 26; i++) {
        if (cntA[n][i] != cntB[n][i]) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = n + 10;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i < n && j < n && s[i] == t[j]) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            }
            if (i < n) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
            int symb = t[j] - 'a';
            if (j < n && cntA[i][symb] > cntB[j][symb]) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            }
        }
    }
    cout << dp[n][n] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}