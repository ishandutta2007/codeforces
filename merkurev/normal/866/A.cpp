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
    int a;
    scanf("%d", &a);

    if (a == 1)
    {
        printf("1 1\n1\n");
        return 0;
    }
    
    int n = 2 * (a - 1);
    int m = 2;
    printf("%d %d\n1 2\n", n, m);

	return 0;
}