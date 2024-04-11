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

    int n;
    scanf("%d", &n);
    int op = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        mx = max(mx, x);
        op += x;
    }
    int x = mx;
    while (n * x - op <= op)
        x++;
    printf("%d\n", x);

	return 0;
}