#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxl = 26;
const int Maxlen = 20004;
const int Maxn = 23;
const int Inf = 1000000000;
const int mod = 998244353;

char tmp[Maxlen];
int n;
string s[Maxn];
int cnt[Maxn][Maxl];
int mn[Maxn + 1][Maxl], cur[Maxn + 1];
int dp[1 << Maxn];
ll res;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

void Gen(int lvl, int mask, int mult)
{
    if (lvl >= n) {
        if (!mask) return;
        int add = (mult * cur[lvl]) % mod;
        if (add < 0) add += mod;
        dp[mask] = (dp[mask] + add) % mod;
    } else {
        for (int j = 0; j < Maxl; j++)
            mn[lvl + 1][j] = mn[lvl][j];
        cur[lvl + 1] = cur[lvl];
        Gen(lvl + 1, mask, mult);
        cur[lvl + 1] = 1;
        for (int j = 0; j < Maxl; j++) {
            mn[lvl + 1][j] = min(mn[lvl][j], cnt[lvl][j]);
            cur[lvl + 1] = ll(cur[lvl + 1]) * (mn[lvl + 1][j] + 1) % mod;
        }
        Gen(lvl + 1, mask | 1 << lvl, -mult);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Read(s[i]);
        for (int j = 0; j < s[i].length(); j++)
            cnt[i][s[i][j] - 'a']++;
    }
    fill(mn[0], mn[0] + Maxl, Inf);
    Gen(0, 0, -1);
    for (int b = 0; b < n; b++)
        for (int i = 0; i < 1 << n; i++) if (!(i & 1 << b))
            dp[i | 1 << b] = (dp[i | 1 << b] + dp[i]) % mod;
    for (int i = 1; i < 1 << n; i++) {
        int sum = 0, cnt = 0;
        for (int j = 0; j < n; j++) if (i & 1 << j) {
            cnt++;
            sum += j + 1;
        }
        res ^= (ll(dp[i]) * ll(cnt) * ll(sum));
    }
    cout << res << endl;
    return 0;
}