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



struct Point
{
    int x, y, z;

    Point() : x(), y(), z() {}

    Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}

    Point operator - (const Point &A) const
    {
        return Point(x - A.x, y - A.y, z - A.z);
    }

    double len()
    {
        return sqrt((double)x * x + y * y + z * z);
    }

    void read()
    {
        scanf("%d%d%d", &x, &y, &z);
    }
};

const int N = (int) 1e5 + 100;
Point P[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        P[i].read();
    }

    double ans = 1e9;

    for (int a = 1; a < n; a++)
        for (int b = a + 1; b < n; b++)
        {
            double sum = (P[a] - P[0]).len() + (P[b] - P[0]).len() + (P[b] - P[a]).len();
            ans = min(ans, sum / 2);
        }
    printf("%.10lf\n", ans);


	return 0;
}