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


	int k, a, b;
	scanf("%d%d%d", &k, &a, &b);
	int ans = a / k + b / k;

	if (a / k == 0 && b % k != 0) ans = -1;
	if (b / k == 0 && a % k != 0) ans = -1;

	printf("%d\n", ans);

	return 0;
}