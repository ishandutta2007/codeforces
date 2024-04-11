#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 400005;

int m, n, q, u, v, cnt, dsu[MAX];

int rt(int u)
{
    return dsu[u] < 0 ? u : dsu[u] = rt(dsu[u]);
}

void unity(int u, int v)
{
    if ((u = rt(u)) == (v = rt(v)))
        return;
    if (dsu[u] > dsu[v])
        swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
    cnt--;
}

int main()
{
    scanf("%d%d%d", &m, &n, &q);
    fill(dsu + 1, dsu + m + n + 1, -1);
    cnt = m + n;
    while (q--)
    {
        scanf("%d%d", &u, &v);
        unity(u, v + m);
    }
    printf("%d\n", cnt - 1);
}