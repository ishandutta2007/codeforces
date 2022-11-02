#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef int i32;

#define PII pair<int, int>
#define F first
#define S second

const int N = 100;
const int V = N * N;
const int E = 10 * N * N;
const int INF = 1000 * 1000 * 1000;

int a[N][N], id[N][N], cnt = 1;

struct edge
{
    int from, to, cap, flow, cost, rev;
    edge() {}
    edge(int _from, int _to, int _cap, int _cost, int _rev): from(_from), to(_to), cap(_cap), flow(0), cost(_cost), rev(_rev) {}
};

edge e[E];
int pv[V];
int pe[V];
int d[V];
int tot = 0;
int n, st, en;

void add_edge(int fr, int to, int cap, int cost)
{
    int v1 = tot++;
    int v2 = tot++;
    e[v1] = edge(fr, to, cap, cost, v2);
    e[v2] = edge(to, fr, 0, -cost, v1);
}

int work()
{
    int cost = 0, flow = 0;
    for (;;)
    {
        if (flow == (n - 1) / 2)
            break;
        fill(d, d + n, INF);
        d[st] = 0;
        for (int i = 0; i < n; i++)
        {
            bool any = false;
            for (int j = 0; j < tot; j++)
            {
                if (e[j].flow == e[j].cap)
                    continue;
                int a = e[j].from;
                int b = e[j].to;
                if (d[b] > d[a] + e[j].cost)
                {
                    d[b] = d[a] + e[j].cost;
                    pv[b] = a;
                    pe[b] = j;
                    any = true;
                }
            }
            if (!any)
                break;
        }
        int add = INF;
        for (int v = en; v != st; v = pv[v])
            add = min(add, e[pe[v]].cap - e[pe[v]].flow);
        flow += add;
        cost += d[en] * add;
        for (int v = en; v != st; v = pv[v])
        {
            e[pe[v]].flow += add;
            e[e[pe[v]].rev].flow -= add;
        }
    }
    return cost;
}

int f(int i, int j)
{
    int res = (i + j) % 2;
    return res;
}

int ABS(int a)
{
    return a > 0 ? a : -a;
}

i32 main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int nn, mm;
    cin >> nn >> mm;
    for (int i = 0; i < nn; i++)
        for (int j = 0; j < mm; j++)
            cin >> a[i][j];
    n = nn * mm + 2;
    st = 0;
    en = n - 1;
    for (int i = 0; i < nn; i++)
        for (int j = 0; j < mm; j++)
            if (f(i, j) == 0)
            {
                id[i][j] = cnt++;
                add_edge(0, id[i][j], 1, 0);
            }
    for (int i = 0; i < nn; i++)
        for (int j = 0; j < mm; j++)
            if (f(i, j) == 1)
            {
                id[i][j] = cnt++;
                add_edge(id[i][j], en, 1, 0);
            }
    for (int i = 0; i < nn; i++)
        for (int j = 0; j < mm; j++)
            for (int x = 0; x < nn; x++)
                for (int y = 0; y < mm; y++)
                    if (f(i, j) == 0 && ABS(i - x) + ABS(j - y) == 1)
                        add_edge(id[i][j], id[x][y], 1, a[i][j] == a[x][y] ? 0 : 1);

    cout << work();

    return 0;
}