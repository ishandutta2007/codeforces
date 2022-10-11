#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct TNode
{
    int v, i;
} a[3005];
struct TAns
{
    int x, y, z;
} ans;
int f[3005][3005], i, j, n, l, r, res[3005];

inline bool operator < (const TNode &a, const TNode &b)
{
    return a.v > b.v;
}

inline bool operator > (const TAns &x, const TAns &y)
{
    return y.x == 0 ||
    a[x.x].v - a[x.x + 1].v > a[y.x].v - a[y.x + 1].v ||
    (a[x.x].v - a[x.x + 1].v == a[y.x].v - a[y.x + 1].v &&
    (a[x.y].v - a[x.y + 1].v > a[y.y].v - a[y.y + 1].v ||
    (a[x.y].v - a[x.y + 1].v == a[y.y].v - a[y.y + 1].v &&
    a[x.z].v - a[x.z + 1].v > a[y.z].v - a[y.z + 1].v)));
}

void init()
{
    for (int i = 1; i <= n; i++)
    {
        f[i][i] = i;
        for (int j = i + 1; j <= n; j++)
            f[i][j] = (a[j].v - a[j + 1].v > a[f[i][j - 1]].v - a[f[i][j - 1] + 1].v) ? j : f[i][j - 1];
    }
}

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].v);
        a[i].i = i;
    }
    sort(a + 1, a + n + 1);
    init();
    for (i = 1; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
        {
            if (2 * min(n - j, min(i, j - i)) < max(i, j - i))
                continue;
            l = j + max((i + 1) / 2, (j - i + 1) / 2);
            r = min(n, j + 2 * min(i, j - i));
            if ((TAns) {i, j, f[l][r]} > ans)
                ans = (TAns) {i, j, f[l][r]};
        }
    for (i = 1; i <= ans.x; i++)
        res[a[i].i] = 1;
    for (i = ans.x + 1; i <= ans.y; i++)
        res[a[i].i] = 2;
    for (i = ans.y + 1; i <= ans.z; i++)
        res[a[i].i] = 3;
    for (i = ans.z + 1; i <= n; i++)
        res[a[i].i] = -1;
    for (i = 1; i <= n; i++)
        printf("%d ", res[i]);
}