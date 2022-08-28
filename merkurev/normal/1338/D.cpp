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

int ans;

pair <int, int> dfs(int v, int par)
{
    int bstTake = 0;
    int bstNot = 0;

    for (int to : g[v])
    {
        if (to == par)
            continue;
        pair <int, int> p = dfs(to, v);
        int curTake = p.first, curNot = p.second;

        ans = max(ans, bstTake + curTake + (int) g[v].size() - 2);
        ans = max(ans, bstNot + curNot + 1);

        bstTake = max(bstTake, curTake);
        bstNot = max(bstNot, curNot);
    }

    int ourTake = 1 + bstNot;
    int ourNot = (int) g[v].size() - 2 + bstTake;
    ourNot = max(ourNot, 0);

    ourTake = max(ourTake, ourNot);
    return make_pair(ourTake, ourNot);
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
    if (n == 2)
    {
        printf("1\n");
        return 0;
    }
    int v = 0;
    while ((int) g[v].size() == 1)
        v++;
    
    dfs(v, v);

    printf("%d\n", ans);


	return 0;
}