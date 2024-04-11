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
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

const int LOG = 17;
const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);
struct Tree
{
    int mn[SZ];
    int _add[SZ];


    void update(int v)
    {
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }
    void push(int v, int val)
    {
        mn[v] += val;
        _add[v] += val;
    }
    void push(int v)
    {
        if (_add[v] == 0)
            return;
        push(2 * v, _add[v]);
        push(2 * v + 1, _add[v]);
        _add[v] = 0;
    }

    void clear()
    {
        memset(mn, 0, sizeof mn);
        memset(_add, 0, sizeof _add);
    }
    int getMin()
    {
        return mn[1];
    }
    void add(int v, int tl, int tr, int l, int r, int val)
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
        add(2 * v, tl, tm, l, r, val);
        add(2 * v + 1, tm + 1, tr, l, r, val);
        update(v);
    }
    void add(int l, int r, int val)
    {
        add(1, 0, LEVEL - 1, l, r, val);
    }
} tree;

const int N = (int) 1e5 + 100;
vector <int> g[N];
int a[N];
long long gsum[N];


void add_g(long long sum, int sz, int k)
{
    tree.add(0, (sum + sz - 1) / sz, k);
}

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    tree.clear();
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        tree.add(0, a[i], 1);
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        scanf("%d", &k);
        g[i].resize(k);
        gsum[i] = 0;
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &g[i][j]);
            gsum[i] += g[i][j];
        }
        add_g(gsum[i], (int) g[i].size(), -1);
    }
    for (int i = 0; i < m; i++)
    {
        add_g(gsum[i], (int) g[i].size(), 1);
        for (int j = 0; j < (int) g[i].size(); j++)
        {
            add_g(gsum[i] - g[i][j], (int) g[i].size() - 1, -1);
            printf("%d", (tree.getMin() >= 0));
            add_g(gsum[i] - g[i][j], (int) g[i].size() - 1, 1);
        }
        add_g(gsum[i], (int) g[i].size(), -1);
    }
    printf("\n");
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();

	return 0;
}