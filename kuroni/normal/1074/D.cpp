#include <iostream>
#include <cstdio>
#include <map>
#define fi first
#define se second
using namespace std;

int q, t, l, r, x, lst = 0;
map<int, pair<int, int>> dsu;

pair<int, int> trace(int u)
{
    if (dsu.find(u) == dsu.end() || dsu[u].fi < 0) 
        return make_pair(u, 0);
    else
    {
        pair<int, int> ret = trace(dsu[u].fi);
        return dsu[u] = make_pair(ret.fi, dsu[u].se ^ ret.se);
    }
}

void connect(int l, int r, int x)
{
    pair<int, int> u = trace(l), v = trace(r);
    if (u.fi == v.fi)
        return;
    if (dsu.find(u.fi) == dsu.end())
        dsu[u.fi] = make_pair(-1, 0);
    if (dsu.find(v.fi) == dsu.end())
        dsu[v.fi] = make_pair(-1, 0);
    if (dsu[u.fi].fi > dsu[v.fi].fi)
        swap(u.fi, v.fi);
    dsu[u.fi].fi += dsu[v.fi].fi;
    dsu[v.fi] = make_pair(u.fi, u.se ^ v.se ^ x);
}

int find_ans(int l, int r)
{
    pair<int, int> u = trace(l), v = trace(r);
    return u.fi == v.fi ? u.se ^ v.se : -1;
}

int main()
{
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d%d", &t, &l, &r);
        if (lst == -1)
            lst = 1;
        l ^= lst;
        r ^= lst;
        if (l > r)
            swap(l, r);
        ++l;
        ++r;
        if (t == 1)
        {
            scanf("%d", &x);
            x ^= lst;
            connect(l - 1, r, x);
        }
        else
            printf("%d\n", lst = find_ans(l - 1, r));
    }
}