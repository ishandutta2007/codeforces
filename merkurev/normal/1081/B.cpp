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
int m[N];
int col[N];
int cnt = 0;


int main(int,  char **)
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a[i] = n - x;
        m[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        if (m[i] % i != 0)
        {
            printf("Impossible\n");
            return 0;
        }

    printf("Possible\n");
    for (int i = 0; i < n; i++)
    {
        if (m[a[i]] % a[i] == 0)
            col[a[i]] = cnt++;
        m[a[i]]--;
        printf("%d ", col[a[i]] + 1);
    }
    printf("\n");

	return 0;
}