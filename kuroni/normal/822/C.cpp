#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct que
{
    int l, r, c;
} q1[200005], q2[200005];
int n, x, i, l, r, mc[200005], t, ans = -1, j = 1;

bool cmp_1(const que &a, const que &b)
{
    return a.r < b.r;
}

bool cmp_2(const que &a, const que &b)
{
    return a.l < b.l;
}

int main()
{
    memset(mc, -1, sizeof(mc));
    scanf("%d%d", &n, &x);
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &q1[i].l, &q1[i].r, &q1[i].c);
        q2[i] = q1[i];
    }
    sort(q1 + 1, q1 + n + 1, cmp_1);
    sort(q2 + 1, q2 + n + 1, cmp_2);
    for (i = 1; i <= n; i++)
    {
        while (j <= n && q1[j].r < q2[i].l)
        {
            t = q1[j].r - q1[j].l + 1;
            if (mc[t] == -1 || mc[t] > q1[j].c)
                mc[t] = q1[j].c;
            ++j;
        }
        t = q2[i].r - q2[i].l + 1;
        if (t < x && mc[x - t] != -1 && (ans == -1 || ans > mc[x - t] + q2[i].c))
            ans = mc[x - t] + q2[i].c;
    }
    printf("%d", ans);
}