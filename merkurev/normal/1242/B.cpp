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




set <pair <int, int>> es;
set <int> nused;

void dfs(int v)
{
    nused.erase(v);

    vector <int> go;
    for (int to : nused)
        if (!es.count(make_pair(v, to)))
            go.push_back(to);
    for (int x : go)
        nused.erase(x);
    for (int x : go)
        dfs(x);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
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
        es.insert(make_pair(a, b));
        es.insert(make_pair(b, a));
    }


    for (int i = 0; i < n; i++)
        nused.insert(i);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!nused.count(i))
            continue;
        ans++;
        dfs(i);
    }
    printf("%d\n", ans - 1);

	return 0;
}