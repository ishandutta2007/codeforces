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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


long long solve(long long n, long long x)
{
//    eprintf("n = %lld, x = %lld\n", n, x);
    if (x == 1 && n == 2)
        return 1;
    if (x % 2 == 0)
        return x / 2;
    long long nn = (n + 1) / 2;
    long long nx = x / 2 + ( (2 * nn != n) ? 1 : 0);
    long long add = n - nn;
//    eprintf("nn = %lld, nx = %lld, add = %lld\n", nn, nx, add);
    return solve(nn, nx) + add;
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    long long n;
    scanf("%lld", &n);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        long long x;
        scanf("%lld", &x);
        x--;
        long long ans = solve(n, x);
        printf("%lld\n", ans + 1);
    }




	return 0;
}