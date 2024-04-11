#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct TEdge
{
    int u, v, w;
} a[300005];
struct TNode
{
    int u, val;
};
int n, m, i, u, v, w, res = 0, maxi[300005];
vector <TNode> upd;

inline bool operator < (const TEdge &a, const TEdge &b)
{
    return a.w < b.w;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++)
        scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
    sort(a + 1, a + m + 1);
    for (i = 1; i <= m; i++)
    {
        upd.push_back({a[i].v, maxi[a[i].u] + 1});
        if (a[i].w != a[i + 1].w)
        {
            while (!upd.empty())
            {
                res = max(res, upd.back().val);
                maxi[upd.back().u] = max(upd.back().val, maxi[upd.back().u]);
                upd.pop_back();
            }
        }
    }
    printf("%d", res);
}