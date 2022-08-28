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


const int N = (int) 1e5 + 100;
int ans[N];
int p[N];

void solve()
{
    int n;
    long long k;
    scanf("%d%lld", &n, &k);

    k--;

    for (int i = 0; i < n; i++)
        ans[i] = 0;

    for (int i = 0; i < n - 1 && k; i++)
    {
        if ((k >> i) & 1)
        {
            ans[n - 2 - i] = 1;
            k ^= (1LL << i);
        }
    }

    if (k > 0)
    {
        printf("-1\n");
        return;
    }

    for (int i = 0; i < n; i++)
        p[i] = i + 1;

    for (int i = 0; i < n - 1; i++)
    {
        int r = i;
        while (r < n - 1 && ans[r])
            r++;
        reverse(p + i, p + r + 1);
        i = r;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);
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