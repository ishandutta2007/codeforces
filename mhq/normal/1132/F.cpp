#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 505;
int dp[maxN][maxN][26];
int tot[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    string s;
    cin >> s;
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            tot[l][r] = 1e9;
            for (int z = 0; z < 26; z++) dp[l][r][z] = 1e9;
            if (l == r) {
                dp[l][r][s[l] - 'a'] = 0;
                tot[l][r] = 1;
                continue;
            }
            for (int p = l; p <= r; p++) {
                tot[l][r] = min(tot[l][r], 1 + min(tot[l][p - 1], dp[l][p - 1][s[p] - 'a']) + min(tot[p + 1][r], dp[p + 1][r][s[p] - 'a']));
                dp[l][r][s[p] - 'a'] = min(dp[l][r][s[p] - 'a'], min(tot[l][p - 1], dp[l][p - 1][s[p] - 'a']) + min(tot[p + 1][r], dp[p + 1][r][s[p] - 'a']));
            }
        }
    }
    cout << tot[0][n - 1] << '\n';
    return 0;
}