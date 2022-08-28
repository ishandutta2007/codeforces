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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}


const int N = (int) 1e6 + 100;

int a[N];


void solve(int n, int g)
{
    if (n == 1)
    {
        printf("%d ", g);
        return;
    }
    if (n == 3)
    {
        printf("%d %d %d\n", g, g, 3 * g);
        return;
    }
    for (int i = 0; i < (n + 1) / 2; i++)
        printf("%d ", g);
    solve(n / 2, 2 * g);
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    solve(n, 1);



	return 0;
}