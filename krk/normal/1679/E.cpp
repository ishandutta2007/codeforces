#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 18;
const int MaxN = 1 << 17;
const int Maxl = 1005;

int pw[Maxn][Maxl];
char tmp[Maxl];
int tot;
int n;
char str[Maxl];
int cur[Maxn];
int dp[MaxN][Maxn];

void Add(int inl, int inr)
{
    int mask = 0;
    int curq = tot;
    for (int l = inl, r = inr; l >= 0 && r < n; l--, r++) {
        char a = str[l], b = str[r];
        if (a == '?') swap(a, b);
        if (a == '?') curq -= l != r;
        else if (b == '?') { mask |= 1 << int(a - 'a'); curq--; }
        else if (a != b) break;
        for (int i = 1; i < Maxn; i++)
            dp[mask][i] = (dp[mask][i] + pw[i][curq]) % mod;
    }
}

int main()
{
    for (int i = 1; i < Maxn; i++) {
        pw[i][0] = 1;
        for (int j = 1; j < Maxl; j++)
            pw[i][j] = ll(pw[i][j - 1]) * i % mod;
    }
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
        tot += str[i] == '?';
    for (int i = 0; i < n; i++) {
        Add(i, i);
        if (i + 1 < n)
            Add(i, i + 1);
    }
    for (int j = 0; j < 17; j++)
        for (int i = 0; i < MaxN; i++) if (!(i & 1 << j)) {
            int ni = (i | (1 << j));
            for (int z = 0; z < Maxn; z++)
                dp[ni][z] = (dp[ni][z] + dp[i][z]) % mod;
        }
    int q; scanf("%d", &q);
    while (q--) {
        scanf("%s", tmp);
        int tlen = strlen(tmp);
        int mask = 0;
        for (int i = 0; i < tlen; i++)
            mask |= 1 << int(tmp[i] - 'a');
        printf("%d\n", dp[mask][tlen]);
    }
    return 0;
}