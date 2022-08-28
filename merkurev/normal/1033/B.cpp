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


void solve()
{
    long long a, b;
    scanf("%lld%lld", &a, &b);
    if (a - b > 1)
    {
        printf("NO\n");
        return;
    }
    a += b;
    for (long long i = 2; i * i <= a; i++)
        if (a % i == 0)
        {
            printf("NO\n");
            return;
        }
    printf("YES\n");
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();




	return 0;
}