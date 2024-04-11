#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 15;
const int Inf = 1000000000;

int lst[1 << Maxn][Maxn];
int en[1 << Maxn];
int bits[1 << Maxn];
int sum[1 << Maxn];
int T;
int n;
int a[Maxn];
int dp[1 << Maxn][Maxn][Maxn + 1];
ii par[1 << Maxn][Maxn][Maxn + 1];
int mp[Maxn];

void Gen(int lvl, int mask, int cur)
{
    if (lvl >= n) {
        if (mask == 0) return;
        if (mask == cur) {
            fill((int*)dp[mask], (int*)dp[mask] + Maxn * (Maxn + 1), Inf);
            dp[mask][lst[mask][0]][1] = sum[mask];
        } else {
            int oth = (mask ^ cur);
            for (int i = 0; i < en[mask]; i++)
                for (int j = 1; j <= bits[oth]; j++) if (dp[oth][i][j] < sum[cur])
                    if (sum[cur] < dp[mask][lst[cur][i + 1]][j + 1]) {
                        dp[mask][lst[cur][i + 1]][j + 1] = sum[cur];
                        par[mask][lst[cur][i + 1]][j + 1] = ii(oth, i);
                    }
        }
    } else {
        Gen(lvl + 1, mask, cur);
        Gen(lvl + 1, mask | 1 << lvl, cur | 1 << lvl);
        Gen(lvl + 1, mask | 1 << lvl, cur);
    }
}

vector <ii> res;

void Add(int i, int j)
{
    res.push_back(ii(mp[i], mp[j]));
    for (int z = i; z < n; z++)
        mp[z]--;
}

int main()
{
    for (int i = 0; i < 1 << Maxn; i++) {
        fill(lst[i], lst[i] + Maxn, -1);
        int was = -1;
        for (int j = 0; j < Maxn; j++) if (i & 1 << j) {
            for (int k = was + 1; k <= j; k++)
                lst[i][k] = j;
            was = j;
            en[i] = j;
        }
        bits[i] = __builtin_popcount(i);
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i < 1 << n; i++) {
            int j = __builtin_popcount((i & -i) - 1);
            sum[i] = sum[i ^ 1 << j] + a[j];
        }
        Gen(0, 0, 0);
        int all = (1 << n) - 1;
        int best = 0, bi;
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= n; j++) if (dp[all][i][j] < Inf && j > best) {
                best = j;
                bi = i;
            }
        for (int i = 0; i < n; i++)
            mp[i] = i + 1;
        res.clear();
        int mask = all, ind = bi, lft = best;
        while (lft > 0) {
            int oth = lft > 1? par[mask][ind][lft].first: 0;
            int nind = lft > 1? par[mask][ind][lft].second: -1;
            int cur = (oth ^ mask);
            for (int i = 0; i < n; i++) if (cur & 1 << i)
                if (i != ind) Add(i, ind);
            mask = oth; ind = nind;
            lft--;
        }
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}