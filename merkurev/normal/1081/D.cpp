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


const int N = (int) 1e5 + 100;
int par[N], sz[N];
bool hasImp[N];

int getP(int v)
{
    if (par[v] == v) return v;
    return par[v] = getP(par[v]);
}

bool uni(int a, int b)
{
    a = getP(a);
    b = getP(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    if (hasImp[b])
        hasImp[a] = true;
    return true;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    vector <pair<int, pair<int, int>>> edges;

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < k; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        hasImp[x] = true;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        edges.emplace_back(c, make_pair(a, b));
    }
    sort(edges.begin(), edges.end());

    int ans = 0;
    for (auto e : edges)
    {
        int x = e.first;
        int a = e.second.first;
        int b = e.second.second;
        a = getP(a);
        b = getP(b);
        if (a == b) continue;
        if (hasImp[a] && hasImp[b])
            ans = x;
        uni(a, b);
    }
    for (int i = 0; i < k; i++)
        printf("%d ", ans);
    printf("\n");


	return 0;
}