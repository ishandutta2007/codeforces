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
#include <bitset>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

const int MAXN = (int)2e5 + 5;
const lint INF = (lint)1e18 + 5;
mt19937 rng(34567);

struct Treap
{
    static Treap forest[MAXN];
    static int forestl;
    int left, right;
    int siz;
    int x;
    unsigned int y;
    int res;
    Treap() : left(-1), right(-1), siz(1), x(0), y(rng()), res(0) {}
    void recalc()
    {
        siz = 1 + (left == -1 ? 0 : forest[left].siz) + (right == -1 ? 0 : forest[right].siz);
        int dec = 0;
        if (left == -1)
            res = x;
        else
        {
            dec = forest[left].siz;
            res = min(x - dec, forest[left].res);
        }
        if (right != -1)
            res = min(res, forest[right].res - dec - 1);
    }
};

Treap Treap::forest[MAXN];
int Treap::forestl = 0;

int merge(int a, int b)
{
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    if (Treap::forest[a].y < Treap::forest[b].y)
    {
        Treap::forest[a].right = merge(Treap::forest[a].right, b);
        Treap::forest[a].recalc();
        return a;
    }
    else
    {
        Treap::forest[b].left = merge(a, Treap::forest[b].left);
        Treap::forest[b].recalc();
        return b;
    }
}

pair<int, int> split(int a, int x)
{
    if (a == -1)
        return { -1, -1 };
    if (Treap::forest[a].x >= x)
    {
        auto p = split(Treap::forest[a].left, x);
        Treap::forest[a].left = p.second;
        Treap::forest[a].recalc();
        return { p.first, a };
    }
    else
    {
        auto p = split(Treap::forest[a].right, x);
        Treap::forest[a].right = p.first;
        Treap::forest[a].recalc();
        return { a, p.second };
    }
}

int treap[MAXN];
int deg[MAXN];
vector<int> igraph[MAXN];
int dist[MAXN];
priority_queue<pair<int, int>> pq;

int add_one(int v, int x)
{
    pair<int, int> p = split(treap[v], x);
    Treap::forest[Treap::forestl].x = x;
    Treap::forest[Treap::forestl].res = x;
    p.second = merge(Treap::forestl, p.second);
    treap[v] = merge(p.first, p.second);
    ++Treap::forestl;
    return Treap::forest[treap[v]].res;
}

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

void solve()
{
    int n = read();
    int m = read();
    For(i, m)
    {
        int a = read() - 1;
        int b = read() - 1;
        ++deg[a];
        igraph[b].push_back(a);
    }
    fill(treap, treap + n, -1);
    fill(dist, dist + n, (int)1e9);
    dist[n - 1] = 0;
    pq.emplace(0, n - 1);
    while (!pq.empty())
    {
        int cur, cur_dist;
        tie(cur_dist, cur) = pq.top();
        pq.pop();
        cur_dist = -cur_dist;
        if (cur_dist != dist[cur])
            continue;
        for (auto e : igraph[cur])
        {
            int cur_e = dist[e];
            int nxt_e = add_one(e, cur_dist) + deg[e];
            if (nxt_e < cur_e)
            {
                dist[e] = nxt_e;
                pq.emplace(-nxt_e, e);
            }
        }
    }
    printf("%d\n", dist[0]);
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