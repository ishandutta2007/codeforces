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


const int N = 1005;
char str[N];

int main(int,  char **)
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
    scanf("%s", str);
    int n = strlen(str);
    int c0 = 0, c1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            printf("%d %d\n", 3 - 2 * c0, 4);
            c0 = (c0 + 1) & 1;
        }
        else
        {
            printf("%d %d\n", 1, 1 + 2 * c1);
            c1 = (c1 + 1) & 1;
        }
    }

	return 0;
}