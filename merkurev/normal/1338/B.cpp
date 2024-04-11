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


const int N = (int) 1e5 + 100;
vector <int> g[N];
int cnt[N];

int c[N];


void dfs(int v, int par, int cc)
{
    c[v] = cc;
    for (int to : g[v])
    {
        if (to == par)
            continue;
        dfs(to, v, cc ^ 1);
    }
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
        if ((int) g[i].size() == 1)
        {
            cnt[g[i][0]]++;
        }

    int ansMax = n - 1;
    for (int i = 0; i < n; i++)
        ansMax -= max(0, cnt[i] - 1);

    int ansMin = 1;

    int v = 0;
    while ((int) g[v].size() != 1)
        v++;
    dfs(v, v, 0);

    for (int i = 0; i < n; i++)
        if ((int) g[i].size() == 1 && c[i] == 1)
            ansMin = 3;

    printf("%d %d\n", ansMin, ansMax);



	return 0;
}