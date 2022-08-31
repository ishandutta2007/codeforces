#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


char str[5];

int K = 24;
int MX = (1 << K);
int dp[1 << 24];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

#ifdef LOCAL
	scanf("%d", &K);
	MX = (1 << K);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		vector <int> v;
		for (int j = 0; j < 3; j++)
		{
			v.push_back(str[j] - 'a');
		}
		sort(v.begin(), v.end() );
		v.resize(unique(v.begin(), v.end() ) - v.begin() );
		int m = (int) v.size();
		for (int mask = 1; mask < (1 << m); mask++)
		{
			int rmask = 0, k = -1;
			for (int j = 0; j < m; j++)
				if (mask & (1 << j) )
				{
					k *= -1;
					rmask |= (1 << v[j] );
				}
			dp[rmask] += k;
		}
	}
	for (int i = 0; i < K; i++)
	{
		for (int j = MX - 1; j >= 0; j--)
			if ((j & (1 << i) ) == 0)
				dp[j | (1 << i) ] += dp[j];
	}
	long long ans = 0;
	for (int i = 0; i < MX; i++)
	{
		ans ^= dp[i] * 1LL * dp[i];
	}
	printf("%lld\n", ans);


	return 0;
}