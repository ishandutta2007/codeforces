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
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	scanf("%d%d", &n, &k);
	int l = 1, r = n;
	long long ans = 0;
	for (int i = 0; i < k; i++)
	{
		if (l >= r)
			break;
		int mid = r - l - 1;
		ans += 2 * mid + 1;
		l++;
		r--;
	}

	printf("%lld\n", ans);

	return 0;
}