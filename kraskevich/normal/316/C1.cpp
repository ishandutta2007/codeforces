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

#define PII pair<int, int>
#define F first
#define S second

const int N = 89;
const int V = N * N;
const int E = 4 * N * N;
const int INF = 1000 * 1000 * 1000;

int a[N][N], id[N][N], cnt = 1;

struct edge
{
    int from, to, cap, flow, cost, rev;
    edge() {}
    edge(int _from, int _to, int _cap, int _cost, int _rev): from(_from), to(_to), cap(_cap), flow(0), cost(_cost), rev(_rev) {}
};

edge e[E];
int phi[V];
int par[N];
int pe[N];
int d[V];
vector<int> g[V];
int st, en;
int tot = 0;
int n;

void add_edge(int fr, int to, int cap, int cost)
{
    int v1 = tot++;
    int v2 = tot++;
    e[v1] = edge(fr, to, cap, cost, v2);
    e[v2] = edge(to, fr, 0, -cost, v1);
    g[fr].push_back(v1);
    g[to].push_back(v2);
}


void find_path()
{
    fill(d, d + n, INF);
    d[st] = 0;
    set<PII> q;
    q.insert(PII(0, st));
    while (q.size())
    {
        int v = q.begin()->S;
        q.erase(q.begin());
        for (int i = 0; i < g[v].size(); i++)
        {
            int to = e[g[v][i]].to;
            if (e[g[v][i]].cap == e[g[v][i]].flow)
                continue;
            int w = phi[v] - phi[to] + e[g[v][i]].cost;
            if (d[v] + w < d[to])
            {
                q.erase(PII(d[to], to));
                d[to] = d[v] + w;
                q.insert(PII(d[to], to));
                par[to] = v;
                pe[to] = i;
            }
        }
    }
}

int work()
{
    fill(phi, phi + n, 0);
    int cost = 0;
    int flow = 0;
    for (;;)
    {
        find_path();
        for (int i = 0; i < n; i++)
            phi[i] = (d[i] == INF ? INF : d[i] - d[st]);
        int add = INF;
        for (int v = en; v != st; v = par[v])
        {
            int p = par[v];
            int i = pe[v];
            add = min(add, e[g[p][i]].cap - e[g[p][i]].flow);
        }
        for (int v = en; v != st; v = par[v])
        {
            int p = par[v];
            int i = pe[v];
            e[g[p][i]].flow += add;
            e[e[g[p][i]].rev].flow -= add;
            cost += e[g[p][i]].cost * add;
        }
        //cerr << "OK" << endl;
        flow += add;
        if (flow == (n - 1) / 2)
            break;
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

int main()
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