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



const int N = 3005;
long long dp[2][N];
int a[N], val[N];
const long long INF = (long long) 1e18;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		a[i] -= i;
		val[i] = a[i];
	}
	
	sort(val, val + n);
	int cnt = unique(val, val + n) - val;
	for (int i = 0; i < n; i++)
		a[i] = find(val, val + cnt, a[i] ) - val;

	int t = 0, nt = 1;
	for (int i = 0; i < cnt; i++)
		dp[t][i] = INF;
	dp[t][0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j + 1 < cnt; j++)
			dp[t][j + 1] = min(dp[t][j + 1], dp[t][j] );
		for (int j = 0; j < cnt; j++)
			dp[nt][j] = dp[t][j] + abs(val[a[i] ] - val[j] );
		swap(t, nt);
	}
	long long ans = INF;
	for (int i = 0; i < cnt; i++)
		ans = min(ans, dp[t][i]);
	printf("%lld\n", ans);

	return 0;
}