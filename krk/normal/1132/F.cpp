#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int n;
string s;
int dp[Maxn][Maxn];

int Get(int l, int r)
{
    if (l >= r) return 0;
    if (dp[l][r] == -1) {
        dp[l][r] = Get(l + 1, r);
        for (int i = l + 1; i <= r; i++) if (s[l] == s[i])
            dp[l][r] = max(dp[l][r], 1 + Get(l + 1, i - 1) + Get(i, r));
    }
    return dp[l][r];
}

int main()
{
    cin >> n;
    cin >> s;
    fill((int*)dp, (int*)dp + Maxn * Maxn, -1);
    printf("%d\n", n - Get(0, int(s.length()) - 1));
    return 0;
}