#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 2000005;
const ll Inf = 1000000000000000000ll;

int n, k, l;
char tmp[Maxn];
int ones[Maxn];
lli dp[Maxn];

lli Solve(ll cost)
{
    fill(dp, dp + Maxn, lli(-Inf, 0));
    dp[0] = lli(0, 0);
    for (int i = 0; i + 1 <= n; i++) {
        lli cand = lli(dp[i].first + ones[i], dp[i].second);
        dp[i + 1] = max(dp[i + 1], cand);
        cand = lli(dp[i].first + l - cost, dp[i].second - 1);
        if (i + l <= n)
            dp[i + l] = max(dp[i + l], cand);
    }
    return dp[n];
}

ll coverMax()
{
    int lef = 0, rig = n + 1;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        lli got = Solve(mid);
        if (-Solve(mid).second <= k) rig = mid - 1;
        else lef = mid + 1;
    }
    return Solve(rig + 1).first + ll(k) * (rig + 1);
}

int main()
{
    scanf("%d %d %d", &n, &k, &l);
    if (ll(k) * l >= n) { printf("0\n"); return 0; }
    scanf("%s", tmp);
    for (int i = 0; i < n; i++)
        ones[i] = bool(isupper(tmp[i]));
    ll res = coverMax();
    for (int i = 0; i < n; i++)
        ones[i] = bool(islower(tmp[i]));
    res = max(res, coverMax());
    printf("%I64d\n", max(0ll, n - res));
    return 0;
}