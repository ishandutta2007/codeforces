#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const double pi = 3.14159265358979323846;

struct cir
{
    long long x, y, r;
} a[1005];
int i, j, n, h[1005];
long long ans = 0, f[2][1005];
vector <int> adj[1005];

inline bool operator < (const cir &a, const cir &b)
{
    return a.r > b.r;
}

inline bool chk(const cir &a, const cir &b)
{
    if (hypot(a.x - b.x, a.y - b.y) >= a.r + b.r)
        return 0;
    return a.r > b.r;
}

void DFS(int x)
{
    long long tmp[2] = {0, 0}, sq = a[x].r * a[x].r;
    for (int i = 0; i < adj[x].size(); i++)
    {
        DFS(adj[x][i]);
        tmp[0] += f[0][adj[x][i]];
        tmp[1] += f[1][adj[x][i]];
    }
    if (h[x] & 1)
        f[0][x] = f[1][x] = max(tmp[0] - sq, tmp[1] + sq);
    else
    {
        f[0][x] = max(tmp[0], tmp[1]) + sq;
        f[1][x] = max(tmp[0], tmp[1]) - sq;
    }
}

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%I64d%I64d%I64d", &a[i].x, &a[i].y, &a[i].r);
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++)
        for (j = i - 1; j >= 1; j--)
        if (chk(a[j], a[i]))
    {
        adj[j].push_back(i);
        h[i] = h[j] + 1;
        break;
    }
    for (i = 1; i <= n; i++)
        if (h[i] == 0)
    {
        DFS(i);
        ans += f[0][i];
    }
    printf("%.8f", ans * pi);
}