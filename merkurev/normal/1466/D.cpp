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
int w[N], deg[N];


void solve()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        w[i] = 0;
        deg[i] = 0;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        deg[a]++;
        deg[b]++;
    }

    vector <int> v;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < deg[i]; j++)
            v.push_back(w[i]);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i = 1; i <= n - 1; i++)
    {
        printf("%lld ", sum);
        if (i - 1 < (int) v.size())
            sum += v[i - 1];
    }
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