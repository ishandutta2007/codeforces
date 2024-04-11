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


const int N = 205;
int p[N], g[N];
bool used[N];

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
        p[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        g[p[i]] = i;
    }
    while (true)
    {
        memset(used, false, sizeof used);
        int v = 0;
        while (!used[v])
        {
            used[v] = true;
            v = g[v];
        }
        int i = 0;
        while (i < n && used[i])
            i++;
        if (i == n)
            break;
        int ii = i - 1;
        int ni = g[i];
        int nii = g[ii];
        swap(g[i], g[ii]);
        swap(p[ni], p[nii]);
    }
    int v = 0;
    do
    {
        printf("%d ", v + 1);
        v = g[v];
    }
    while (v != 0);
    printf("\n");
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