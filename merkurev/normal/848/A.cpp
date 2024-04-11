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
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
  
    a[1] = 0;
    for (int k = 2; a[k - 1] < N; k++)
    {
        a[k] = a[k - 1] + k;
        for (int i = 1; i <= k; i++)
            a[k] = min(a[k], a[i] + a[k - i] + i * (k - i) );
    }
    for (int i = 0; i <= 10; i++)
        eprintf("%d : %d\n", i, a[i] );
       
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 26; i++)
    {
        int x = 0;
        while (a[x + 1] <= n)
            x++;
        for (int it = 0; it < x; it++)
            printf("%c", 'a' + i);
        n -= a[x];
    }
    printf("\n");
    if (n != 0) throw;

	return 0;
}