#include<bits/stdc++.h>
using namespace std;
const int nax = 5010;
int n;
char s[5010];
int lcp[nax][nax];
int dp[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T --) {
        cin >> n >> s + 1;
        /// first compute lcp table
        /// s[123456789..n]
        /// lcp s[i....n] s[j....n]
        for (int i = 1 ; i <= n + 1 ; ++ i)
        for (int j = 1 ; j <= n + 1 ; ++ j)
            lcp[i][j] = 0;

        for (int i = n - 1 ; i >= 1 ; -- i) {
            for (int j = n ; j > i ; -- j) {
                if (s[i] == s[j]) lcp[i][j] = 1 + lcp[i + 1][j + 1];
            }
        }

        for (int i = 1 ; i <= n ; ++ i) {
            dp[i] = 0; /// maximum length if last insert is i
            for (int j = 1 ; j < i ; ++ j) {
                if (s[i + lcp[j][i]] > s[j + lcp[j][i]]) {
                    dp[i] = max(dp[i], dp[j] -(lcp[j][i]));
                }
            }
            dp[i] += n - i + 1;
        }
        cout << *max_element(dp + 1, dp + 1 + n) << '\n';
        /**
            x[i] x[i..n]  x[j..] x[j...n]
        */
    }
}