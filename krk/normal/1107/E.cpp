#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 115;
const ll Inf = 1000000000000000000ll;

int n;
char str[Maxn];
int seq[Maxn], slen;
ll a[Maxn];
ll dp[Maxn][Maxn][Maxn];
ll res;

ll Get(int l, int r, int c)
{
    if (dp[l][r][c] == -Inf) {
        ll best = a[seq[l] + c];
        if (l < r) best += Get(l + 1, r, 0);
        for (int i = l + 2; i <= r; i += 2)
            best = max(best, Get(l + 1, i - 1, 0) + Get(i, r, c + seq[l]));
        dp[l][r][c] = best;
    }
    return dp[l][r][c];
}

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        for (int j = 1; j < i; j++)
            a[i] = max(a[i], a[j] + a[i - j]);
    }
    slen = 2;
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && str[i] == str[j]) j++;
        seq[slen++] = j - i;
    }
    fill((ll*)dp, (ll*)dp + Maxn * Maxn * Maxn, -Inf);
    cout << Get(2, slen - 1, 0) << endl;
    return 0;
}