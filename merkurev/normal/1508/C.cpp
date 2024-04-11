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

const long long INF = (long long) 1e18;

typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}


const int N = (int) 2e5 + 100;
set <pair <int, int>> edges;

vector <int> comp[N];
int col[N], sz[N];

set <int> torem;

vector <int> g[N];
int gcol[N];

void dfsCol(int v, int c)
{
    gcol[v] = c;
    for (int to : g[v])
        if (gcol[to] == -1)
            dfsCol(to, c);
}

void uni(int a, int b)
{
    if (sz[a] < sz[b])
        swap(a, b);

    torem.insert(b);

    for (int x : comp[b])
    {
        col[x] = a;
        comp[a].push_back(x);
    }
    sz[a] += sz[b];
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    
    vector <pair <int, pair <int, int>>> vedges;
    long long x = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        edges.insert(make_pair(a, b));
        edges.insert(make_pair(b, a));
        vedges.push_back(make_pair(c, make_pair(a, b)));
        x ^= c;
    }
    sort(vedges.begin(), vedges.end());

    vector <int> cols;
    for (int i = 0; i < n; i++)
    {
        col[i] = i;
        sz[i] = 1;
        comp[i].push_back(i);
        cols.push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (int) cols.size(); j++)
        {
            if (col[i] == cols[j] || torem.count(cols[j]))
                continue;
            for (int h : comp[cols[j]])
            {
                if (edges.count(make_pair(i, h)))
                    continue;
                
                //eprintf("i = %d, h = %d\n", i, h);
                //eprintf("col[i] = %d, cols[j] = %d\n", col[i], cols[j]);
                int a = col[i];
                int b = col[h];
                //eprintf("a = %d, b = %d\n", a, b);
                uni(a, b);

                break;
            }
        }

        for (int j = 0; j < (int) cols.size(); j++)
        {
            if (torem.count(cols[j]))
            {
                swap(cols[j], cols.back());
                cols.pop_back();
                j--;
            }
        }
        torem.clear();
    }

    int rcomps = (int) cols.size();

    long long ans = 0;
    long long minin = INF;

    for (auto e : vedges)
    {
        int v = e.second.first;
        int u = e.second.second;

        int a = col[v];
        int b = col[u];

        if (a == b)
            continue;

        ans += e.first;
        uni(a, b);
        g[v].push_back(u);
        g[u].push_back(v);
    }

    memset(gcol, -1, sizeof gcol);
    int gcnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (gcol[i] == -1)
            dfsCol(i, gcnt++);
    }
    
    for (auto e : vedges)
    {
        int v = e.second.first;
        int u = e.second.second;
        if (gcol[v] != gcol[u])
            minin = min(minin, (long long) e.first);
    }

    long long k = n * 1LL * (n - 1) / 2;
    long long rm = k - m;

    eprintf("rm = %lld, n = %d, rcomps = %d\n", rm, n, rcomps);

    if (rm > n - rcomps)
    {
        printf("%lld\n", ans);
        return 0;
    }

    eprintf("%lld vs %lld\n", minin, x);
    ans += min(minin, (long long) x);
    printf("%lld\n", ans);


	return 0;
}