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

const int mod = (int)1e9 + 7;
const int N = (int)1e5;

int add(int a, int b)
{
	return (a + b) % mod;
}

int n;
int p[N];
int dp[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);

	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = p[i]; j <= i; j++)
			sum = add(sum, dp[j]);
		dp[i] = add(sum, 2);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = add(ans, dp[i]);

	printf("%d\n", ans);

	return 0;
}