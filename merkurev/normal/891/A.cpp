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


const int N = 2005;
int a[N];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


    int n;
    scanf("%d", &n);
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i] );
    for (int i = 0; i < n; i++)
        if (a[i] == 1)
            cnt1++;

    if (cnt1 > 0)
    {
        printf("%d\n", n - cnt1);
        return 0;
    }

    int mn = n + 1;
    for (int i = 0; i < n; i++)
    {
        int g = 0;
        for (int j = i; j < n; j++)
        {
            g = gcd(g, a[j] );
            if (g == 1)
                mn = min(mn, j - i + 1);
        }
    }
    if (mn > n)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", mn - 1 + n - 1);


	return 0;
}