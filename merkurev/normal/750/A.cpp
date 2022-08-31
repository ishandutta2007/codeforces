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

	int n, k;
	scanf("%d%d", &n, &k);
	int t = 4 * 60 - k;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i * 5 <= t)
		{
			t -= 5 * i;
			ans++;
		}
	}
	printf("%d\n", ans);




	return 0;
}