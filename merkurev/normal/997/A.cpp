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


const int N = (int) 3e5 + 100;
char str[N];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    long long x, y;
    scanf("%d%lld%lld", &n, &x, &y);
    scanf("%s", str);

    int k = 0;
    for (int i = 0; i < n; i++)
        if (str[i] == '0' && str[i + 1] != '0')
            k++;
    
    long long ans = (k - 1) * min(x, y) + y;
    if (k == 0) ans = 0;

    printf("%lld\n", ans);

	return 0;
}