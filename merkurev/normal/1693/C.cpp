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


typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

const int INF = (int) 1e9 + 100;
const int N = (int) 2e5 + 100;
int e[N][2];
vector <int> g[N], rg[N];
vector <int> good[N];
int dist[N];

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
        scanf("%d%d", &e[i][0], &e[i][1]);
        g[e[i][0]].push_back(i);
        rg[e[i][1]].push_back(i);
    }
    priority_queue<pair<int, int>> qu;
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[n] = 0;
    qu.push(make_pair(-dist[n], n));

    while (!qu.empty())
    {
        auto p = qu.top();
        qu.pop();
        int v = p.second;
        if (-p.first != dist[v])
            continue;
        for (int eid : rg[v])
        {
            int to = e[eid][0];
            good[to].push_back(dist[v]);
            int nd = dist[v] + 1 + (int) g[to].size() - (int) good[to].size();
            if (nd < dist[to])
            {
                dist[to] = nd;
                qu.push(make_pair(-dist[to], to));
            }
        }
    }

    printf("%d\n", dist[1]);

	return 0;
}