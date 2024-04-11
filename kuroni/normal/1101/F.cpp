#include <iostream>
#include <cstdio>
using namespace std;

const int N = 405;

int n, m, l, r, c, t, a[N], f[N][N][N];
long long ans = 0;

int find_ans(int l, int r, int t)
{
    t = min(t, r - l);
    int &ret = f[l][r][t];
    if (ret > -1)
        return ret;
    if (t == 0)
        return ret = a[r] - a[l];
    int le = l, ri = r;
    while (le <= ri)
    {
        int md = (le + ri) / 2;
        if (find_ans(l, md, t - 1) < a[r] - a[md])
            le = md + 1;
        else
            ri = md - 1;
    }
    return ret = min(max(find_ans(l, ri, t - 1), a[r] - a[ri]), max(find_ans(l, le, t - 1), a[r] - a[le]));
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                f[i][j][k] = -1;
    while (m--)
    {
        scanf("%d%d%d%d", &l, &r, &c, &t);
        ans = max(ans, 1LL * find_ans(l, r, t) * c);
    }
    printf("%lld", ans);
}