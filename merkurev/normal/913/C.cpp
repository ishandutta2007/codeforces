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



const long long INF = (long long) 1e18;
const int K = 31;
long long c[K];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    for (int i = 0; i < K; i++)
        c[i] = INF;

    int n, l;
    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; i++)
        scanf("%lld", &c[i] );

    for (int i = n - 1; i > 0; i--)
        c[i - 1] = min(c[i - 1], c[i] );

    for (int i = 1; i < K; i++)
        c[i] = min(c[i], 2 * c[i - 1] );

    long long ans = 0;
    for (int i = 0; i < K; i++)
    {
        ans = min(ans, c[i] );
        if (l & (1 << i) )
            ans += c[i];
    }

    printf("%lld\n", ans);

	return 0;
}