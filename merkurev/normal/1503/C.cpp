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



int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    vector <pair <int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, c;
        scanf("%d%d", &a, &c);
        v.emplace_back(a, c);
    }
    sort(v.begin(), v.end());

    int rmax = v[0].first;
    long long ans = 0;

    for (auto &p : v) {
        ans += p.second;
        ans += max(0, p.first - rmax);
        rmax = max(rmax, p.first + p.second);
    }
    printf("%lld\n", ans);

	return 0;
}