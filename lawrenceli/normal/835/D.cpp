#include <bits/stdc++.h>

using namespace std;

const int maxn = 5005;

int n;
char s[maxn];
int dp[maxn][maxn]; //max k s.t. s[l, r] is a k palindrome

int ans[maxn];

int main() {
    cin >> s;
    n = strlen(s);

    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            dp[l][r] = 1;
            l--, r++;
        }

        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            dp[l][r] = 1;
            l--, r++;
        }
    }

    for (int l = 1; l < n; l++) {
        int l2 = (l - 1) / 2;
        for (int i = 0; i + l < n; i++) {
            int j = i + l;
            if (dp[i][j]) {
                dp[i][j] = min(dp[i][i + l2], dp[j - l2][j]) + 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            ans[dp[i][j]]++;

    for (int i = n; i >= 0; i--)
        ans[i] += ans[i + 1];

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}