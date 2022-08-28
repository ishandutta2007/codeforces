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



const long long INF = (long long) 1e18;

const int LOG = 20;
const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);

struct Tree 
{
    long long mx[SZ];
    long long _add[SZ];

    Tree()
    {
        for (int i = 0; i < SZ; i++)
            mx[i] = -INF;
    }

    void push(int v, long long x)
    {
        mx[v] += x;
        _add[v] += x;
    }

    void push(int v)
    {
        if (_add[v] == 0)
            return;
        push(2 * v, _add[v]);
        push(2 * v + 1, _add[v]);
        _add[v] = 0;
    }

    void update(int v)
    {
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void add(int v, int tl, int tr, int l, int r, long long x)
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

    void add(int l, int r, long long x)
    {
        add(1, 0, LEVEL - 1, l, r, x);
    }

    long long getMax()
    {
        return mx[1];
    }
}
tree;



const int N = (int) 1e6 + 100;
int a[N];
long long ca[N];
int b[N];
long long cb[N];
int x[N], y[N], r[N];

vector <pair <int, long long>> as;
vector <pair <int, long long>> bs;
vector <pair <pair <int, int>, long long>> xys;


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%lld", &a[i], &ca[i]);
        as.emplace_back(a[i], ca[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%lld", &b[i], &cb[i]);
        bs.emplace_back(b[i], cb[i]);
    }

    for (int i = 0; i < k; i++)
    {
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
        xys.emplace_back(make_pair(x[i], y[i]), r[i]);
    }

    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    sort(xys.begin(), xys.end());

    

    int prv = -1;
    for (auto p : bs)
    {
        if (p.first == prv)
            continue;
        tree.add(p.first, p.first, INF - p.second);
        prv = p.first;
    }

    int ptr = 0;
    long long ans = -INF;
    for (auto p : as)
    {
        while (ptr < (int) xys.size() && xys[ptr].first.first < p.first)
        {
            tree.add(xys[ptr].first.second + 1, LEVEL - 1, xys[ptr].second);
            ptr++;
        }
        long long cur = tree.getMax() - p.second;
        ans = max(ans, cur);
    }

    printf("%lld\n", ans);

	return 0;
}