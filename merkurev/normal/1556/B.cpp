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


const long long INF = (long long) 1e18;
const int N = (int) 1e5 + 100;
int a[N];

long long solve(int n, int x)
{
    long long ans = 0;
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            ans += abs(i - pos);
            pos += 2;
        }
    }
    return ans;
}

void solve()
{
    int n;
    scanf("%d", &n);
    int cnt[2] = {0, 0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i] %= 2;
        cnt[a[i]]++;
    }
    long long ans = INF;
    if (cnt[0] == cnt[1] || cnt[0] == cnt[1] + 1)
        ans = min(ans, solve(n, 0));
    if (cnt[0] == cnt[1] || cnt[1] == cnt[0] + 1)
        ans = min(ans, solve(n, 1));
    if (ans == INF)
        ans = -1;
    printf("%lld\n", ans);
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