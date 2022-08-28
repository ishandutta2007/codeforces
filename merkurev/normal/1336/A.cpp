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
vector <int> g[N];

int sz[N];
int h[N];
int val[N];

void dfs(int v, int par, int ch)
{
    h[v] = ch;
    sz[v] = 1;
    for (int to : g[v])
    {
        if (to == par)
            continue;
        dfs(to, v, ch + 1);
        sz[v] += sz[to];
    }
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, 0, 1);
    for (int i = 0; i < n; i++)
        val[i] = sz[i] - h[i];

    sort(val, val + n);
    reverse(val, val + n);
    long long ans = 0;
    for (int i = 0; i < n - k; i++)
        ans += val[i];

    printf("%lld\n", ans);


	return 0;
}