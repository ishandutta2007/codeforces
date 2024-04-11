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


const int MOD = (int) 1e9 + 7;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
}
int sub(int a, int b)
{
    ssub(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}


const int LOG = 60;
const int N = (int) 5e5 + 100;
long long x[N];
int cnt[LOG][2];


void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &x[i]);

    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < LOG; j++)
            cnt[j][(x[i] >> j) & 1LL]++;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int sAnd = 0, sOr = 0;
        for (int j = 0; j < LOG; j++)
        {
            int curX = (1LL << j) % MOD;

            int curAnd = ((x[i] >> j) & 1LL) * cnt[j][1];
            int curOr = n - (((x[i] >> j) & 1LL) == 0) * cnt[j][0];

            sadd(sAnd, mul(curAnd, curX));
            sadd(sOr, mul(curOr, curX));
        }
        sadd(ans, mul(sAnd, sOr));
    }
    printf("%d\n", ans);
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