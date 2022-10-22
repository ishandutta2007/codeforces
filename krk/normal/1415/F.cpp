#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 5005;
const int Inf = 2000000007;

int n;
int T[Maxn], X[Maxn];
ii dp[Maxn][Maxn];
bool has[Maxn][Maxn];
int mn[Maxn];

ii getInterval(int Told, int Xold, int nw, int lst)
{
    int lef = min(Xold, X[nw]), rig = max(Xold, X[nw]);
    int lft = T[nw] - Told - (rig - lef);
    if (lft < 0) return ii(Inf, -Inf);
    ii res = ii(lef - lft / 2, rig + lft / 2);
    lft = T[nw] - T[lst];
    res.first = max(res.first, X[nw] - lft);
    res.second = min(res.second, X[nw] + lft);
    return res;
}

ii getInterval(int old, int nw, int lst)
{
    return getInterval(T[old], X[old], nw, lst);
}

bool Valid(const ii &p) { return p.first <= p.second; }

int main()
{
    fill((ii*)dp, (ii*)dp + Maxn * Maxn, ii(Inf, -Inf));
    fill(mn, mn + Maxn, Inf);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &T[i], &X[i]);
    dp[1][0] = ii(0, 0);
    mn[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) if (Valid(dp[i][j])) {
            if (dp[i][j].first <= X[i] && X[i] <= dp[i][j].second)
                has[i + 1][i - 1] = true;
            else if (T[i] - T[i - 1] >= abs(X[i] - X[i - 1])) 
                mn[i + 1] = min(mn[i + 1], T[i - 1] + abs(X[i] - X[i - 1]));
            ii got = getInterval(i - 1, i, j);
            if (!Valid(got)) continue;
            ii cand = ii(min(got.first, dp[i][j].first), max(got.second, dp[i][j].second));
            dp[i + 1][j].first = min(dp[i + 1][j].first, cand.first);
            dp[i + 1][j].second = max(dp[i + 1][j].second, cand.second);
        }
        for (int j = 0; j < i; j++) if (has[i][j]) {
            if (T[i] - T[j] >= abs(X[i] - X[j]))
                mn[i + 1] = min(mn[i + 1], max(T[i - 1], T[j] + abs(X[i] - X[j])));
            ii cand = getInterval(j, i, i - 1);
            if (!Valid(cand)) continue;
            dp[i + 1][i - 1].first = min(dp[i + 1][i - 1].first, cand.first);
            dp[i + 1][i - 1].second = max(dp[i + 1][i - 1].second, cand.second);
        }
        if (mn[i] < Inf) {
            if (T[i] - mn[i] >= abs(X[i] - X[i - 1]))
                mn[i + 1] = min(mn[i + 1], max(T[i - 1], mn[i] + abs(X[i] - X[i - 1])));
            ii cand = getInterval(mn[i], X[i - 1], i, i - 1);
            if (!Valid(cand)) continue;
            dp[i + 1][i - 1].first = min(dp[i + 1][i - 1].first, cand.first);
            dp[i + 1][i - 1].second = max(dp[i + 1][i - 1].second, cand.second);
        }
    }
    for (int j = 0; j <= n; j++) if (dp[n + 1][j].first <= dp[n + 1][j].second) {
        printf("YES\n");
        return 0;
    }
    for (int j = 0; j <= n; j++) if (has[n + 1][j]) {
        printf("YES\n");
        return 0;
    }
    if (mn[n + 1] < Inf)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}