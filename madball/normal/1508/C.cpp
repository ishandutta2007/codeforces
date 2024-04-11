#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

int read()
{
    char c;
    while (true)
    {
        c = getchar();
        if ('0' <= c && c <= '9')
            break;
    }
    int res = c - '0';
    while (true)
    {
        c = getchar();
        if (!('0' <= c && c <= '9'))
            return res;
        res = res * 10 + c - '0';
    }
}

struct Edge
{
    int a, b, c;
    Edge() {}
    Edge(int a, int b, int c) : a(a), b(b), c(c) {}
    bool operator < (const Edge& e) const
    {
        return c < e.c;
    }
} edges[200500];

struct Dsu
{
    int par[666];
    int rank[666];
    Dsu() {}
    void init()
    {
        For(i, 666)
            par[i] = i;
        memset(rank, sizeof(rank), 0);
    }
    int get_par(int i)
    {
        if (par[i] == i)
            return i;
        return par[i] = get_par(par[i]);
    }
    bool merge(int a, int b)
    {
        a = get_par(a);
        b = get_par(b);
        if (a == b)
            return false;
        if (rank[a] < rank[b])
            swap(a, b);
        if (rank[a] == rank[b])
            ++rank[a];
        par[b] = a;
        return true;
    }
} dsu;

lint kruskal(int n, int m)
{
    dsu.init();
    lint res = 0;
    int cnt = n - 1;
    for (int i = 0; cnt; ++i)
        if (dsu.merge(edges[i].a, edges[i].b))
        {
            res += edges[i].c;
            --cnt;
        }
    return res;
}

vector<pair<int, int>> graph[200500];
vector<int> igraph[666];

lint prim(int n, int m)
{
    static priority_queue<pair<int, int>> by_degree;
    static priority_queue<pair<int, int>> by_edge;
    static int deg[200500];
    for (auto e : graph[0])
    {
        ++deg[e.first];
        by_edge.emplace(-e.second, e.first);
    }
    deg[0] = -200500;
    for (int i = 1; i < n; ++i)
        by_degree.emplace(-deg[i], i);
    lint res = 0;

    for (int iter = 1; iter < n; ++iter)
    {
        while (deg[by_degree.top().second] < 0 || deg[by_degree.top().second] != -by_degree.top().first)
            by_degree.pop();
        while (!by_edge.empty() && deg[by_edge.top().second] < 0)
            by_edge.pop();

        int cur, curw;
        if (iter + by_degree.top().first > 0)
        {
            cur = by_degree.top().second;
            curw = 0;
        }
        else
        {
            cur = by_edge.top().second;
            curw = -by_edge.top().first;
        }

        res += curw;
        deg[cur] = -200500;
        for (auto e : graph[cur])
            if (deg[e.first] >= 0)
            {
                ++deg[e.first];
                by_degree.emplace(-deg[e.first], e.first);
                by_edge.emplace(-e.second, e.first);
            }
    }
    return res;
}

char been[666];
bool dfs(int v, int n, int from = -1)
{
    been[v] = 1;
    int ptr = 0;
    for (auto e : igraph[v])
        if (e == from)
            ;
        else if (been[e] == 1)
            return true;
        else if (been[e] == 0)
            dfs(e, n, v);
    been[v] = 2;
    return false;
}

bool has_loop(int n, int m)
{
    For(i, n)
        if (!been[i] && dfs(i, n))
            return true;
    return false;
}

void solve()
{
    int n = read();
    int m = read();
    int x = 0;
    For(i, m)
    {
        int a = read();
        int b = read();
        int c = read();
        --a;
        --b;
        x ^= c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
        edges[i] = { a, b, c };
    }
    For(i, n)
        sort(all(graph[i]));
    if (n < 635)
        For(i, n)
        {
            int ptr = 0;
            For(j, n)
                if (i == j)
                    ;
                else if (ptr < sz(graph[i]) && graph[i][ptr].first == j)
                    ++ptr;
                else
                    igraph[i].emplace_back(j);
        }
    lint res;
    if (n >= 635 || has_loop(n, m))
        res = prim(n, m);
    else
    {
        res = (lint)1e18;
        int m2 = m;
        For(i, n) for (auto j : igraph[i])
            if (i < j)
                edges[m2++] = Edge(i, j, 0);
        sort(edges, edges + m2);
        int ptr = 0;
        while (ptr < m2 && edges[ptr].c < x)
            ++ptr;
        For(i, m2 - m)
        {
            edges[i].c = x;
            for (int j = i; j + 1 < ptr; ++j)
                swap(edges[j], edges[j + 1]);
            res = min(res, kruskal(n, m2));
            for (int j = ptr - 2; j >= i; --j)
                swap(edges[j], edges[j + 1]);
            edges[i].c = 0;
        }
    }
    printf("%lld\n", res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}