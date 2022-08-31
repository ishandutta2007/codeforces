#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int maxn = 1e6;
long long dp[maxn + 100];
int cnt[maxn + 100];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for (int i = 0; i < maxn; i++)
	{
		dp[i + 1] = max(dp[i + 1], dp[i] );
		dp[i + 2] = max(dp[i + 2], dp[i] + i * 1LL * cnt[i] );
	}
	printf("%I64d\n", dp[maxn - 1] );



	return 0;
}