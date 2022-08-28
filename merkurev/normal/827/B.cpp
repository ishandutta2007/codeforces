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
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	scanf("%d%d", &n, &k);

	int rem = n - k - 1;
	int small = rem / k;
	int cntBig = rem % k; 

	int ans = 2 + 2 * small + min(cntBig, 2);
	printf("%d\n", ans);

	for (int i = 1; i <= k; i++)
		printf("%d %d\n", 1, i + 1);
	for (int i = k + 1; i < n; i++)
		printf("%d %d\n", (i - k) + 1, i + 1);

	return 0;
}