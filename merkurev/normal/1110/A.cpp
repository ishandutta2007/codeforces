#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
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



const int N = (int) 1e5 + 100;
int a[N];

int main(int,  char **)
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int b, k;
    scanf("%d%d", &b, &k);

    for (int i = 0; i < k; i++)
        scanf("%d", &a[i]);

    int x = 0;
    if (b % 2 == 0)
    {
        x = a[k - 1] % 2;
    }
    else
    {
        for (int i = 0; i < k; i++)
            x ^= (a[i] % 2);
    }
    printf(x ? "odd\n" : "even\n");

	return 0;
}