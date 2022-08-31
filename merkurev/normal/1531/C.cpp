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


const int N = 105;
char f[N][N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    
    int k;
    scanf("%d", &k);
    if (k == 2)
    {
        printf("-1\n");
        return 0;
    }
    memset(f, '.', sizeof f);

    int n = 1;
    while (n * n < k)
        n++;

    bool ch = false;
    if (k == n * n - 2)
    {
        ch = true;
        k -= 2;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++)
        {
            f[i][j] = 'o';
            k--;
        }
    for (int i = 0; i < n -1; i++)
    {
        if (k >= 1)
        {
            f[n - 1][i] = f[i][n - 1] = 'o';
            k -= 2;
        }
    }
    if (k == 1)
    {
        f[n - 1][n - 1] = 'o';
        k--;
    }
    else if (k == -1)
    {
        f[n - 2][n - 2] = '.';
        k++;
    }

    if (ch)
    {
        n++;
        f[n - 1][0] = f[0][n - 1] = 'o';
    }


    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c", f[n - 1 - i][j]);
        printf("\n");
    }


	return 0;
}