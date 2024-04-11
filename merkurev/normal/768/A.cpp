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
int a[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );

	int mx = a[0], mn = a[0];
	for (int i = 0; i < n; i++)
	{
		mx = max(mx, a[i] );
		mn = min(mn, a[i] );
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != mn && a[i] != mx)
			ans++;

	printf("%d\n", ans);


	return 0;
}