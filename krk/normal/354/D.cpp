#include <bits/stdc++.h>
using namespace std;

const int Maxm = 780;
const int Maxn = 100005;
const int Inf = 300005;

int sz[Maxm + 1];
int n, k;
vector <int> bycol[Maxn];
int dp[Maxm + Maxn], add;
int res = Inf;

int main()
{
    for (int i = 1; i <= Maxm; i++)
        sz[i] = i + sz[i - 1];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        int r, c; scanf("%d %d", &r, &c);
        r = n - r;
        c--;
        if (r >= Maxm) add += 3;
        else bycol[c].push_back(r); 
    }
    fill(dp, dp + Maxm + Maxn, Inf);
    dp[0] = 0;
    for (int j = 0; j < n; j++) {
        sort(bycol[j].rbegin(), bycol[j].rend());
        int sav = int(bycol[j].size());
        int mn = dp[j];
        for (int i = 0, d = j + 1; i < Maxm; i++, d++) {
            if (!bycol[j].empty() && bycol[j].back() == i) bycol[j].pop_back();
            mn = min(mn, dp[d]);
            dp[d] = min(dp[d], mn + 2 + sz[i + 1]) + 3 * int(bycol[j].size());
        }
        dp[j + 1] = min(dp[j + 1], dp[j] + 3 * sav);
    }
    for (int d = n; d < Maxm + Maxn; d++)
        res = min(res, dp[d]);
    res += add;
    printf("%d\n", res);
    return 0;
}