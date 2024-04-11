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




int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    unsigned long long k, d, t;
    scanf("%llu%llu%llu", &k, &d, &t);
    unsigned long long a = (k + d - 1) / d;
    unsigned long long p = a * d;
    unsigned long long tp = p + k;
    unsigned long long cnt = (2 * t) / tp;
    unsigned long long rem = 2 * t - cnt * tp;
    double ans = cnt * p;
    if (2 * k >= rem)
        ans += rem / 2.;
    else
    {
        ans += k;
        rem -= 2 * k;
        ans += rem;
    }
    printf("%.5lf\n", ans);




	return 0;
}