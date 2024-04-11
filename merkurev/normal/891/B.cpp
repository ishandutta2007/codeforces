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


const int N = 40;
long long a[N], v[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i] );
        v[i] = a[i];
    }
    sort(v, v + n);
    for (int i = 0; i < n; i++)
    {
        int x = lower_bound(v, v + n, a[i] ) - v;
        x = (x + 1) % n;
        printf("%lld ", v[x] );
    }
    printf("\n");
    


	return 0;
}