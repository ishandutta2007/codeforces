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
const int INF = (int) 1e9 + 100;

int p[N];
int l[N];
int r[N];

long long val[N];
int ans[N];

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &p[i]);
        p[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        val[i] = 0;
        ans[i] = 0;
        scanf("%d%d", &l[i], &r[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (val[i] < l[i])
        {
            ans[i]++;
            val[i] = r[i];
        }
        else
            val[i] = min(val[i], (long long) r[i]);
        if (i != 0)
        {
            val[p[i]] += val[i];
            ans[p[i]] += ans[i];
        }
    }
    printf("%d\n", ans[0]);
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