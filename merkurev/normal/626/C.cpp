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

	int n2, n3;
	scanf("%d%d", &n2, &n3);

	int l = 0, r = (int) 5e6;

	while (r - l > 1)
	{
		int m = (l + r) / 2;
		
		int c2 = m / 2;
		int c3 = m / 3;
		int c6 = m / 6;

		int o2 = c2 - c6;
		int o3 = c3 - c6;
		int o23 = c6;
	
		int r2 = max(0, n2 - o2);
		int r3 = max(0, n3 - o3);
		if (r2 + r3 > o23)
			l = m;
		else
			r = m;
	}
	printf("%d\n", r);

	return 0;
}