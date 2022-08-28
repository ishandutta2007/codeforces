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

const int N = (int) 2e5 + 100;
vector <int> g[N];

int cnt0;
int cnt1;

int solve(int v, int par)
{
    int cur = 0;
    for (int to : g[v])
    {
        if (to == par)
            continue;
        if (solve(to, v) == 0)
            cur = 1;
    }
    if (cur == 0)
        cnt0++;
    else if (v != par)
        cnt1++;
    return cur;
}

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        g[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cnt0 = 0;
    cnt1 = 0;
    solve(0, 0);


    printf("%d\n", cnt0 - cnt1);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();

	return 0;
}