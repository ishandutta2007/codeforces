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

const int N = (int) 3e5 + 100;
vector <pair <int, int>> g[N];
int w[N];
vector <long long> mxUp[N];

void dfsUp(int v, int par)
{
    mxUp[v].push_back(w[v]);
    for (auto p : g[v])
    {
        int to = p.first;
        if (to == par) continue;
        dfsUp(to, v);
        mxUp[v].push_back(mxUp[to][0] - p.second + w[v]);
        sort(mxUp[v].begin(), mxUp[v].end());
        reverse(mxUp[v].begin(), mxUp[v].end());
        while ((int) mxUp[v].size() > 2)
            mxUp[v].pop_back();
    }
}

long long ans;
void dfsDown(int v, int par, long long x)
{
    mxUp[v].push_back(x);
    sort(mxUp[v].begin(), mxUp[v].end());
    reverse(mxUp[v].begin(), mxUp[v].end());
    while ((int) mxUp[v].size() > 2)
        mxUp[v].pop_back();

    ans = max(ans, mxUp[v][0]);
    
    for (auto p : g[v])
    {
        int to = p.first;
        if (to == par) continue;
        long long nx = mxUp[v][0];
        if (mxUp[v][0] == mxUp[to][0] - p.second + w[v])
            nx = mxUp[v][1];
        dfsDown(to, v, nx + w[to] - p.second);
    }
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    dfsUp(0, 0);
    dfsDown(0, 0, 0LL);

    printf("%lld\n", ans);

	return 0;
}