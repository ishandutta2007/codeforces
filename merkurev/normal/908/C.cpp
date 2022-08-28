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

double sqr(double x)
{
    return x * x;
}
double mySqrt(double x)
{
    if (x < 0) return 0;
    return sqrt(x);
}

const int N = 1005;
int x[N];
double y[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, r;
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i] );

        y[i] = r;
        for (int j = 0; j < i; j++)
            if (abs(x[i] - x[j] ) <= 2 * r)
            {
                double cur = y[j] + mySqrt(sqr(2. * r) - sqr(x[i] - x[j] ) );
                y[i] = max(y[i], cur);
            }

        printf("%.10lf ", y[i] );
    }
    printf("\n");




	return 0;
}