
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// 3d DP array [i][j][k]
// value = minimum length regular bracket sequence prefix
// that contains S[1, i] and T[1, j] as subsequences, and requires exactly k
// close-brackets to become regular
// If last character is (: transition to k - 1. Only make this transition if k > 0.
// If last character is ): transition to k + 1. Only make this transition if ) matches S[i] or T[j] and k < n + m.

const int N = 205;
int dp[N][N][2 * N];
int n, m;
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    n = s.length();
    m = t.length();
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k <= n + m; k++) {
                dp[i][j][k] = 1e9;
            }
        }
    }
    for(int k = 0; k <= n + m; k++) {
        dp[0][0][k] = k;
    }
    int i2, j2;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 && j == 0) continue;
            for(int k = n + m; k >= 0; k--) {
                if(k > 0) {
                    i2 = (i > 0 && s[i - 1] == '(' ? i - 1 : i);
                    j2 = (j > 0 && t[j - 1] == '(' ? j - 1 : j);
                    if(i2 < i || j2 < j) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i2][j2][k - 1] + 1);
                    }
                }
                if(k < n + m) {
                    i2 = (i > 0 && s[i - 1] == ')' ? i - 1 : i);
                    j2 = (j > 0 && t[j - 1] == ')' ? j - 1 : j);
                    dp[i][j][k] = min(dp[i][j][k], dp[i2][j2][k + 1] + 1);
                }
            }
        }
    }
    int i = n, j = m, k = 0;
    string ans;
    while(i > 0 || j > 0) {
        if(k > 0) {
            i2 = (i > 0 && s[i - 1] == '(' ? i - 1 : i);
            j2 = (j > 0 && t[j - 1] == '(' ? j - 1 : j);
            if((i2 < i || j2 < j) && dp[i][j][k] == dp[i2][j2][k - 1] + 1) {
                i = i2;
                j = j2;
                k--;
                ans.push_back('(');
                continue;
            }
        }
        i = (i > 0 && s[i - 1] == ')' ? i - 1 : i);
        j = (j > 0 && t[j - 1] == ')' ? j - 1 : j);
        k++;
        ans.push_back(')');
    }
    for(int i = 0; i < dp[0][0][k]; i++) {
        ans.push_back('(');
    }

    string ans2(ans.rbegin(), ans.rend());
    cout << ans2 << endl;
}