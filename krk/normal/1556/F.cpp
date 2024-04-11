#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 14;
const int mod = 1000000007;
const int Maxm = 2000005;

int n;
int a[Maxn];
int inv[Maxm];
int prob[Maxn][Maxn];
vector <int> V[1 << Maxn];
int dp[1 << Maxn];
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

void Gen(int lvl, int mask, int submask)
{
    if (lvl >= n) {
        if (submask == 0 || submask == mask) return;
        int omask = (mask ^ submask);
        int cur = dp[submask];
        for (int i = 0; i < V[submask].size(); i++)
            for (int j = 0; j < V[omask].size(); j++)
                cur = ll(cur) * prob[V[submask][i]][V[omask][j]] % mod;
        //printf("mask = %d, submask = %d, omask = %d, cur = %d\n", mask, submask, omask, cur);
        dp[mask] = (dp[mask] - cur + mod) % mod;
    } else {
        Gen(lvl + 1, mask, submask);
        Gen(lvl + 1, mask | 1 << lvl, submask);
        Gen(lvl + 1, mask | 1 << lvl, submask | 1 << lvl);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < Maxm; i++)
        inv[i] = Inv(i);
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i & 1 << j)
                V[i].push_back(j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            prob[i][j] = ll(a[i]) * inv[a[i] + a[j]] % mod;
    fill(dp, dp + (1 << n), 1);
    Gen(0, 0, 0);
    for (int submask = 1; submask < 1 << n; submask++) {
        int cur = dp[submask];
        int omask = (((1 << n) - 1) ^ submask);
        for (int i = 0; i < V[submask].size(); i++)
            for (int j = 0; j < V[omask].size(); j++)
                cur = ll(cur) * prob[V[submask][i]][V[omask][j]] % mod;
        res = (res + ll(cur) * ll(V[submask].size())) % mod;
    }
    printf("%d\n", res);
    return 0;
}