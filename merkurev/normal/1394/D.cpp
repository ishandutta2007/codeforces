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

const long long INF = (long long) 1e12;

const int N = (int) 2e5 + 100;
vector <int> g[N];
int t[N], h[N];

long long dpUp[N], dpDown[N], dpNone[N];

void dfs(int v, int par)
{
    vector <long long> q;

    long long sum = 0;
    int cntUp = 0, cntDown = 0;

    for (int to : g[v])
    {
        if (to == par)
            continue;
        dfs(to, v);
   
        cntUp++;
        sum += dpUp[to];
        q.push_back(dpDown[to] - dpUp[to]);
    }

    sort(q.begin(), q.end());
    
    dpUp[v] = INF;
    dpDown[v] = INF;
    dpNone[v] = INF;


    for (int i = 0; i <= (int) q.size(); i++)
    {
        long long x = min(cntDown, cntUp);

        long long cur = sum + (x + (cntUp - x) + (cntDown - x)) * t[v];

        long long curUp = cur;
        if (cntUp == x)
            curUp += t[v];
        long long curDown = cur;
        if (cntDown == x)
            curDown += t[v];

        dpUp[v] = min(dpUp[v], curUp);
        dpNone[v] = min(dpNone[v], cur);
        dpDown[v] = min(dpDown[v], curDown);

        if (i == (int) q.size())
            break;

        sum += q[i];
        cntUp--;
        cntDown++;
    }



    if (h[par] > h[v])
        dpDown[v] = INF;
    if (h[par] < h[v])
        dpUp[v] = INF;
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, 0);

    printf("%lld\n", dpNone[0]);

	return 0;
}