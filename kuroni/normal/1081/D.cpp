#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define fi first
#define se second
using namespace std;

const int N = 100005;

int n, m, k, u, v, w, ans;
pair<int, int> dsu[N];

struct SEdge
{
    int u, v, w;
};
vector<SEdge> ve;

int trace(int u)
{
    return dsu[u].fi < 0 ? u : dsu[u].fi = trace(dsu[u].fi);
}

int connect(int u, int v)
{
    if ((u = trace(u)) == (v = trace(v)))
        return -1;
    if (dsu[u].fi > dsu[v].fi)
        swap(u, v);
    dsu[u].fi += dsu[v].fi;
    dsu[v].fi = u;
    return dsu[u].se += dsu[v].se;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        dsu[i].fi = -1;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &u);
        dsu[u].se = 1;
    }
    while (m--)
    {
        scanf("%d%d%d", &u, &v, &w);
        ve.push_back((SEdge){u, v, w});
    }
    sort(ve.begin(), ve.end(), [](const SEdge &a, const SEdge &b) { return a.w < b.w; });
    for (SEdge &v : ve)
        if (connect(v.u, v.v) == k)
        {
            ans = v.w;
            break;
        }
    while (k--)
        printf("%d ", ans);
}