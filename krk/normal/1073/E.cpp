#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxl = 21;
const int Maxd = 10;
const int Maxm = 1 << Maxd;
const int mod = 998244353;

int pw[Maxl];
ll l, r;
int k;
int allcnt[Maxl][Maxm], allsum[Maxl][Maxm];
int cnt[Maxl][Maxd][Maxm], sum[Maxl][Maxd][Maxm];

int Get(ll num)
{
    stringstream ss; ss << num;
    string s; ss >> s;
    int res = 0;
    for (int i = 1; i < s.length(); i++)
        for (int d = 1; d < Maxd; d++)
            res = (res + sum[i][d][0]) % mod;
    int mask = 0;
    int cur = 0;
    for (int i = 0; i < s.length(); i++) {
        int d = s[i] - '0';
        for (int j = i == 0? 1: 0; j < d; j++)
            res = (ll(res) + ll(cnt[int(s.length()) - i][j][mask]) * cur % mod * pw[int(s.length()) - i] + sum[int(s.length()) - i][j][mask]) % mod;
        mask |= 1 << d;
        cur = (10ll * cur + d) % mod;
    }
    return res;
}

int main()
{
    scanf("%I64d %I64d %d", &l, &r, &k);
    for (int i = 0; i < Maxm; i++)
        if (__builtin_popcount(i) <= k)
            allcnt[0][i]++;
    pw[0] = 1;
    for (int i = 1; i < Maxl; i++)
        pw[i] = ll(pw[i - 1]) * 10 % mod;
    for (int i = 1; i < Maxl; i++)
        for (int j = 0; j < Maxd; j++)
            for (int k = 0; k < Maxm; k++) {
                cnt[i][j][k] = allcnt[i - 1][k | (1 << j)];
                sum[i][j][k] = (ll(allcnt[i - 1][k | (1 << j)]) * ll(j) % mod * pw[i - 1] + allsum[i - 1][k | (1 << j)]) % mod;
                allcnt[i][k] = (allcnt[i][k] + cnt[i][j][k]) % mod;
                allsum[i][k] = (allsum[i][k] + sum[i][j][k]) % mod;
            }
    int res = (Get(r + 1) - Get(l) + mod) % mod;
    cout << res << endl;
    return 0;
}