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


const int N = (int) 1e5 + 100;
char str[N];

int a[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	scanf("%d%d", &n, &k);
	k++;
	scanf("%s", str);

	int ans = n;
	int sz = 0;
	for (int i = 0; i < n; i++)
		if (str[i] == '0')
			a[sz++] = i;
	for (int i = 0; i + k <= sz; i++)
	{
		int l = a[i], r = a[i + k - 1];
		
		int lb = i, rb = i + k - 1;
		while (rb - lb > 1)
		{
			int mb = (lb + rb) / 2;
			int x = a[mb];
			if (r - x < x - l)
				rb = mb;
			else
				lb = mb;
		}
		ans = min(ans, max(a[lb] - l, r - a[lb] ) );
		ans = min(ans, max(a[rb] - l, r - a[rb] ) );
	}

	printf("%d\n", ans);

	return 0;
}