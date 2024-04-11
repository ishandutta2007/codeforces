#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 5e5 + 100;
long long h[N];
vector <pair <int, int>> ch[N];

const int LOG = 19;
const int LEVEL = (1 << LOG);
const int SIZE = (LEVEL << 1);

const long long INF = (long long) 1e18;

struct Tree
{
    long long mn[SIZE];
    long long add[SIZE];

    Tree() : mn(), add() {}

    void push(int v, long long x)
    {
        mn[v] += x;
        add[v] += x;
    }
    void push(int v)
    {
        if (add[v] == 0)
            return;
        push(2 * v, add[v]);
        push(2 * v + 1, add[v]);
        add[v] = 0;
    }
    void update(int v)
    {
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }
    void addVal(int v, int tl, int tr, int l, int r, long long val)
    {
        if (r < tl || tr < l)
            return;
        if (l <= tl && tr <= r)
        {
            push(v, val);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        addVal(2 * v, tl, tm, l, r, val);
        addVal(2 * v + 1, tm + 1, tr, l, r, val);
        update(v);
    }
    void addVal(int l, int r, long long val)
    {
        addVal(1, 0, LEVEL - 1, l, r, val);
    }

    long long getMn(int v, int tl, int tr, int l, int r)
    {
        if (r < tl || tr < l)
            return INF;
        if (l <= tl && tr <= r)
        {
            return mn[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        return min(
                getMn(2 * v, tl, tm, l, r),
                getMn(2 * v + 1, tm + 1, tr, l, r));
    }
    long long getMn(int l, int r)
    {
        return getMn(1, 0, LEVEL - 1, l, r);
    }
}
tree;

struct Qu
{
    int id, l, r;
    Qu() : id(), l(), r() {}
    Qu(int _id, int _l, int _r) : id(_id), l(_l), r(_r) {}
};

long long ans[N];
vector <Qu> qu[N];

int tl[N], tr[N];

void dfsBounds(int v)
{
    tl[v] = tr[v] = v;
    for (auto p : ch[v])
    {
        dfsBounds(p.first);
        tr[v] = tr[p.first];
    }
}

void dfs(int v)
{
    for (auto q : qu[v])
    {
        long long cur = tree.getMn(q.l, q.r);
        ans[q.id] = cur;
    }

    for (auto p : ch[v])
    {
        int to = p.first;
        long long val = p.second;
        tree.addVal(0, LEVEL - 1, val);
        tree.addVal(tl[to], tr[to], -2 * val);

        dfs(to);
        
        tree.addVal(0, LEVEL - 1, -val);
        tree.addVal(tl[to], tr[to], 2 * val);
    }
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++)
    {
        int p, w;
        scanf("%d%d", &p, &w);
        p--;
        ch[p].emplace_back(i, w);
        h[i] = h[p] + w;
    }
    for (int i = 0; i < q; i++)
    {
        int v, l, r;
        scanf("%d%d%d", &v, &l, &r);
        v--;
        l--;
        r--;
        qu[v].emplace_back(i, l, r);
    }

    for (int i = 0; i < n; i++)
        if ((int) ch[i].size() == 0)
            tree.addVal(i, i, h[i]);
        else
            tree.addVal(i, i, INF);

    dfsBounds(0);
    dfs(0);

    for (int i = 0; i < q; i++)
        printf("%lld\n", ans[i]);

	return 0;
}