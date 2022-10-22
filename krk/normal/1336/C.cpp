#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3005;
const int mod = 998244353;

string S;
string T;
int dp[Maxn][Maxn];
int res;

int main()
{
    cin >> S;
    cin >> T;
    for (int i = 0; i < S.length(); i++)
        if (i < T.length() && T[i] == S[0] || i >= T.length())
            dp[i][i] = 2;
    for (int l = 0; l < S.length(); l++)
        for (int i = 0, j = i + l; j < S.length(); i++, j++) if (dp[i][j]) {
            if (i == 0 && j + 1 >= T.length()) res = (res + dp[i][j]) % mod;
            int ind = j - i + 1;
            if (ind >= S.length()) continue;
            if (i > 0 && (i - 1 < T.length() && T[i - 1] == S[ind] || i - 1 >= T.length()))
                dp[i - 1][j] = (dp[i - 1][j] + dp[i][j]) % mod;
            if (j + 1 < S.length() && (j + 1 < T.length() && T[j + 1] == S[ind] || j + 1 >= T.length()))
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
        }
    printf("%d\n", res);
    return 0;
}