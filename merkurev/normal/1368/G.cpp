#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
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

const int DX[4] = {-1, 1, 0, 0};
const int DY[4] = {0, 0, -1, 1};
const char D[5] = "DURL";

const int SZ = (int) 2e5 + 100;
char f[SZ];

int n, m;

int getDir(char c)
{
    for (int i = 0; i < 4; i++)
        if (D[i] == c)
            return i;
    throw;
}
int getId(int x, int y)
{
    return x * m + y;
}
int getX(int id)
{
    return id / m;
}
int getY(int id)
{
    return id % m;
}
bool inF(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

vector <int> g[SZ], rg[SZ];
const int LOG = 18;
const int LEVEL = (1 << LOG);
const int SIZE = (LEVEL << 1);

struct Tree
{
    int mn[SIZE], cnt[SIZE];
    int _add[SIZE];

    Tree()
    {
        for (int i = 0; i < LEVEL; i++)
            cnt[LEVEL + i] = 1;
        for (int i = LEVEL - 1; i >= 1; i--)
            cnt[i] = cnt[2 * i] + cnt[2 * i + 1];
    }

    void update(int v)
    {
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
        cnt[v] = 0;
        if (mn[2 * v] == mn[v])
            cnt[v] += cnt[2 * v];
        if (mn[2 * v + 1] == mn[v])
            cnt[v] += cnt[2 * v + 1];
    }

    void push(int v, int x)
    {
        _add[v] += x;
        mn[v] += x;
    }

    void push(int v)
    {
        if (_add[v] == 0)
            return;
        push(2 * v, _add[v]);
        push(2 * v + 1, _add[v]);
        _add[v] = 0;
    }

    void add(int v, int tl, int tr, int l, int r, int x)
    {
        if (r < tl || tr < l)
            return;
        if (l <= tl && tr <= r)
        {
            push(v, x);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        add(2 * v, tl, tm, l, r, x);
        add(2 * v + 1, tm + 1, tr, l, r, x);
        update(v);
    }

    void add(int l, int r, int x)
    {
        add(1, 0, LEVEL - 1, l, r, x);
    }

    int getNZ()
    {
        return LEVEL - cnt[1];
    }
}
tree;

int tin[SZ], tout[SZ];

int timer;
long long ans = 0;
long long curAns = 0;


void buildTree(int v)
{
    tin[v] = timer++;

    for (int to : rg[v])
        buildTree(to);

    tout[v] = timer - 1;
}

void addNode(int v)
{
    tree.add(tin[v], tout[v], 1);

    //eprintf("timer = %d; [%d, %d]\n", timer, tin[v], tout[v]);

    curAns = tree.getNZ();
}

void removeNode(int v)
{
    tree.add(tin[v], tout[v], -1);

    curAns = tree.getNZ();
}

void solveTree(int v)
{
    int x = getX(v), y = getY(v);
    int dir = getDir(f[v]);
    int px = x + DX[dir], py = y + DY[dir];
    int pv = getId(px, py);

    addNode(pv);

    //eprintf("v = %d, pv = %d, curAns = %lld\n", v, pv, curAns);

    ans += curAns;

    for (int to : rg[v])
        solveTree(to);

    removeNode(pv);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &m);
    int sz = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", f + sz);
        sz += m;
    }
    for (int i = 0; i < sz; i++)
    {
        int x = getX(i), y = getY(i);
        int dir = getDir(f[i]);
        int nx = x + 2 * DX[dir], ny = y + 2 * DY[dir];
        if (inF(nx, ny))
        {
            int ni = getId(nx, ny);
     //       eprintf("%d -> %d\n", i, ni);
            g[i].push_back(ni);
            rg[ni].push_back(i);
        }
    }
    int active = 0;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
        {
            if ((x + y) % 2 == active)
                continue;
            int id = getId(x, y);
            if ((int) g[id].size() != 0)
                continue;
            rg[sz].push_back(id);
        }
    buildTree(sz);

    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
        {
            if ((x + y) % 2 != active)
                continue;
            int id = getId(x, y);
            if ((int) g[id].size() != 0)
                continue;
            solveTree(id);
        }

    printf("%lld\n", ans);

	return 0;
}