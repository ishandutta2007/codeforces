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
int a[N];
int b[N];

int lg[N];
long long x[N];

const int LOG = 17;
long long mn[LOG][N];
long long mx[LOG][N];

void calc_sparse(int n)
{
    for (int i = 1; i <= n + 1; i++)
    {
        lg[i] = lg[i - 1];
        while ((2 << lg[i]) <= i)
            lg[i]++;
    }
    for (int i = 0; i <= n; i++)
    {
        mx[0][i] = x[i];
        mn[0][i] = x[i];
    }
    for (int i = 1; i < LOG; i++)
        for (int j = 0; j + (1 << i) <= n + 1; j++)
        {
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
            mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            //eprintf("(%d, %d) : %lld %lld\n", i, j, mn[i][j], mx[i][j]);
        }
}

long long get_min(int l, int r)
{
    int len = r - l + 1;
    int q = lg[len];
    //eprintf("%d %d .. %d %d\n", q, l, q, r - (1 << q) + 1);
    return min(mn[q][l], mn[q][r - (1 << q) + 1]);
}

long long get_max(int l, int r)
{
    int len = r - l + 1;
    int q = lg[len];
    return max(mx[q][l], mx[q][r - (1 << q) + 1]);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    
    for (int i = 0; i < n; i++)
    {
        x[i + 1] = x[i] + a[i] - b[i];
    }

    calc_sparse(n);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        //eprintf("[%d, %d] : %lld, %lld, %lld, %lld\n", l, r, x[l], x[r + 1], get_min(l, r + 1), get_max(l, r + 1));
        if (x[r + 1] != x[l] || get_max(l, r + 1) != x[l])
        {
            printf("-1\n");
        }
        else
            printf("%lld\n", x[l] - get_min(l, r + 1));
    }

	return 0;
}