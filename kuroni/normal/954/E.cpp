#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005;

struct SNode
{
    int a, t;
};
vector<SNode> pos, neg;
int n, T, a[N], t[N];
long long mn = 0, cur = 0;
double ans = 0;

int main()
{
    scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", t + i);
        t[i] -= T;
        if (t[i] < 0)
        {
            mn -= 1LL * t[i] * a[i];
            neg.push_back((SNode){a[i], -t[i]});
        }
        else if (t[i] == 0)
            ans += a[i];
        else
            pos.push_back((SNode){a[i], t[i]});
    }
    sort(pos.begin(), pos.end(), [](const SNode &a, const SNode &b) { return a.t < b.t; });
    for (SNode u : pos)
    {
        ans += min((double)(mn - cur) / u.t, (double)u.a);
        cur = min(cur + 1LL * u.t * u.a, mn);
    }
    mn = cur;
    cur = 0;
    sort(neg.begin(), neg.end(), [](const SNode &a, const SNode &b) { return a.t < b.t; });
    for (SNode u : neg)
    {
        ans += min((double)(mn - cur) / u.t, (double)u.a);
        cur = min(cur + 1LL * u.t * u.a, mn);
    }
    printf("%.16f", ans);
}