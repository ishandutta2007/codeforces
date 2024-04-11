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
int cnt[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		for (int k = 1; k * k <= x; k++)
		{
			if (x % k != 0) continue;
			cnt[k]++;
			if (k * k != x)
				cnt[x / k]++;
		}
	}
	int ans = 1;
	for (int i = 2; i < N; i++)
		ans = max(ans, cnt[i] );
	printf("%d\n", ans);



	return 0;
}