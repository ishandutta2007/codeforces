#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int mod = 1000000007;
const int Maxd = 10;

int t, k;
int pw10[Maxn];
int good[Maxn], dp[Maxn][Maxn];
int bydig[Maxn];

int Solve(const string &s, bool incl)
{
    int res = 0;
    for (int i = 1; i < s.length(); i++)
        res = (res + bydig[i]) % mod;
    int st = Maxn - 1;
    for (int i = 0; i < s.length(); i++) {
        int lft = int(s.length()) - 1 - i;
        for (int d = (i == 0? 1: 0); d < s[i] - '0'; d++)
            if (st == -1) res = (res + pw10[lft]) % mod;
            else if (d == 4 || d == 7)
                if (st <= k) res = (res + pw10[lft]) % mod;
                else {
                    res = (res + dp[lft][k]) % mod;
                    res = (res + good[lft]) % mod;
                }
            else {
                if (st <= k) res = (res + dp[lft][k - st]) % mod;
                res = (res + good[lft]) % mod;
            }
        int d = s[i] - '0';
        if (st == -1) continue;
        if (d == 4 || d == 7)
            if (st <= k) st = -1;
            else st = 1;
        else st++;
    }
    if (incl && st == -1) res = (res + 1) % mod;
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> t >> k;
    pw10[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw10[i] = ll(pw10[i - 1]) * 10ll % mod;
    dp[0][Maxn - 1] = 1;
    for (int i = 1; i < Maxn; i++) {
        good[i] = ll(good[i - 1]) * 10ll % mod;
        for (int j = 0; j < Maxn; j++) {
            if (j <= k)
                good[i] = (good[i] + 2ll * dp[i - 1][j]) % mod;
            else dp[i][1] = (dp[i][1] + 2ll * dp[i - 1][j]) % mod;
            int nj = min(Maxn - 1, j + 1);
            dp[i][nj] = (dp[i][nj] + 8ll * dp[i - 1][j]) % mod;
        }
    }
    for (int i = 0; i < Maxn; i++)
        for (int j = 1; j <= k; j++)
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
    for (int i = 1; i < Maxn; i++)
        bydig[i] = (9ll * good[i - 1] + 2ll * dp[i - 1][k]) % mod;
    while (t--) {
        string l, r; cin >> l >> r;
        int res = (Solve(r, true) - Solve(l, false) + mod) % mod;
        printf("%d\n", res);
    }
    return 0;
}