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

    int x, y, z, t1, t2, t3;
    scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);
    int twalk = abs(x - y) * t1;
    int televator = (abs(x - z) + abs(x - y)) * t2 + 3 * t3;
    if (televator <= twalk)
        printf("YES\n");
    else
        printf("NO\n");




	return 0;
}