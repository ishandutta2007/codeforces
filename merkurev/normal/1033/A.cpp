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


int sgn(int x)
{
    if (x > 0) return 1;
    return 0;
}

int ang(int bx, int by, int ax, int ay)
{
    int x = sgn(bx - ax);
    int y = sgn(by - ay);
    return 2 * x + y;
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    int ax, ay, bx, by, cx, cy;
    scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
    if (ang(bx, by, ax, ay) == ang(cx, cy, ax, ay))
        printf("YES\n");
    else
        printf("NO\n");

	return 0;
}