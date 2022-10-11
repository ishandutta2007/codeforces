#include <iostream>
#include <cstdio>
#include <algorithm>
#define fi first
#define se second
using namespace std;

const int N = 200005, A = 25;

int n, a, b, hp[N], dg[N];
long long su = 0, cur = 0;
pair<int, int> sa[N];
bool vis[N];

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    b = min(b, n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", hp + i, dg + i);
        su += dg[i];
        sa[i] = make_pair(hp[i] - dg[i], i);
    }
    if (b == 0)
    {
        printf("%lld", su);
        return 0;
    }
    sort(sa + 1, sa + n + 1, greater<pair<int, int>>());
    for (int i = 1; i < b && sa[i].fi > 0; i++)
    {
        su += sa[i].fi;
        vis[sa[i].se] = true;
    }
    long long ans = su + max(0, sa[b].fi);
    for (int i = 1; i <= n; i++)
    {
        long long cur = (1LL << a) * hp[i] - dg[i];
        cur += (vis[i] ? su - (hp[i] - dg[i]) + max(0, sa[b].fi) : su);
        ans = max(ans, cur);
    }
    printf("%lld", ans);
}