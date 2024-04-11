
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// check every way to split up t into t1 and t2.
// Let dp[i][j] = length of shortest prefix of s
// so that we can place t1 and t2 as disjoint subsequences
// in that prefix.
// dp[i][j] = min(next_char(t1[i], dp[i - 1][j]), next_char(t2[j], dp[i][j - 1]));
// O(n^3) overall.

const int N = 405;
int q, n, m;
string s, t;
int nxtchar[26][N];
int dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> s >> t;
        n = s.length(), m = t.length();
        for(int c = 0; c < 26; c++) {
            for(int i = 0; i < n; i++) {
                int j = i;
                while(j < n && s[j] != c + 'a') j++;
                nxtchar[c][i] = (j == n ? N : j);
            }
            nxtchar[c][n] = N;
        }
        int ans = N;
        for(int k = 0; k <= m; k++) {
            for(int i = 0; i <= k; i++) {
                for(int j = k; j <= m; j++) {
                    if(i == 0 && j == k) dp[i][j] = 0;
                    else {
                        dp[i][j] = N;
                        if(i > 0 && dp[i - 1][j] < N)
                            dp[i][j] = min(dp[i][j], 1 + nxtchar[t[i - 1] - 'a'][dp[i - 1][j]]);
                        if(j > k && dp[i][j - 1] < N)
                            dp[i][j] = min(dp[i][j], 1 + nxtchar[t[j - 1] - 'a'][dp[i][j - 1]]);
                    }
                }
            }
            ans = min(ans, dp[k][m]);
        }
        cout << (ans <= n ? "YES" : "NO") << endl;
    }
}