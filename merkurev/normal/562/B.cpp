#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cassert>
#include <cmath>
using namespace std;

typedef long long int int64;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int N = 1e6 + 100;
int pos[N];
int a[N];
int dp[N];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	fill(pos, pos + N, -1);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		dp[i] = max(dp[i], 1);
		ans = max(ans, dp[i]);
		int x = a[i];
		for (int y = 2 * x; y <= 1e6; y += x)
		{
			if (pos[y] == -1)
				continue;
			int p = pos[y];
			dp[p] = max(dp[p], dp[i] + 1);
		}
	}

	cout << ans << endl;

	return 0;
}