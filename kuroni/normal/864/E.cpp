#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct TItem
{
    int t, d, p, i;
} a[105];
int ans[105][2005], trace[105][2005], n, i, j, sum = 0, tmp = 0;
vector<int> res;

inline bool operator<(const TItem &a, const TItem &b)
{
    return a.d < b.d;
}

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].p);
        a[i].i = i;
    }
    sort(a + 1, a + n + 1);
    trace[0][0] = -1;
    for (i = 1; i <= n; i++)
    {
        for (j = sum; j >= 0; j--)
        {
            if (trace[i - 1][j] != 0 && (trace[i][j] == 0 || ans[i - 1][j] > ans[i][j]))
            {
                ans[i][j] = ans[i - 1][j];
                trace[i][j] = -1;
            }
            if (trace[i - 1][j] != 0 && j + a[i].t < a[i].d && (trace[i][j + a[i].t] == 0 || ans[i - 1][j] + a[i].p > ans[i][j + a[i].t]))
            {
                ans[i][j + a[i].t] = ans[i - 1][j] + a[i].p;
                trace[i][j + a[i].t] = i;
            }
        }
        sum += a[i].t;
    }
    for (i = 0; i <= sum; i++)
        if (trace[n][i] != 0 && ans[n][i] > ans[n][tmp])
            tmp = i;
    printf("%d\n", ans[n][tmp]);
    for (i = n; i >= 1; i--)
    {
        if (trace[i][tmp] != -1)
        {
            res.push_back(a[trace[i][tmp]].i);
            tmp -= a[trace[i][tmp]].t;
        }
    }
    printf("%d\n", res.size());
    while (!res.empty())
    {
        printf("%d ", res.back());
        res.pop_back();
    }
}