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

const int N = (int) 2e5 + 100;
int p[N];

vector <int> g[N], rg[N];

int qu[N];

int d[N];

set <int> nx[N];

void bfs(int s)
{
    for (int i = 0; i < N; i++)
        d[i] = N;
    d[s] = 0;
    int sz = 0;
    qu[sz++] = s;
    for (int i = 0; i < sz; i++)
    {
        int v = qu[i];
        for (int to : rg[v])
        {
            if (d[to] != N) continue;
            d[to] = d[v] + 1;
            qu[sz++] = to;
        }
    }

    for (int i = 0; i < N; i++)
        for (int to : g[i])
            if (d[to] == d[i] - 1)
                nx[i].insert(to);
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &p[i]);
        p[i]--;
    }

    bfs(p[k - 1]);

    int mn = 0, mx = 0;
    for (int i = 1; i < k; i++)
    {
        if (nx[p[i - 1]].count(p[i]) == 0)
            mn++;
        if (!(nx[p[i - 1]].size() == 1 && *nx[p[i - 1]].begin() == p[i]))
            mx++;
    }

    printf("%d %d\n", mn, mx);



	return 0;
}