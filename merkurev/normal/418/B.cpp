#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Member
{
	int monNeed;
	int mask;
	int cost;
	Member() : monNeed(), mask(), cost() {}
	bool operator < (const Member &A) const
	{
		return monNeed < A.monNeed;
	}
	void read()
	{
		int n;
		mask = 0;
		scanf("%d%d%d", &cost, &monNeed, &n);
		for (int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			a--;
			mask |= (1 << a);
		}
	}
};



const int maxn = 105;
Member M[maxn];

const long long inf = 4e18;
long long dp[(1 << 20) + 100];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, b;
	scanf("%d%d%d", &n, &m, &b);
	for (int i = 0; i < n; i++)
		M[i].read();
	sort(M, M + n);
	for (int i = 0; i < (1 << m); i++)
		dp[i] = inf;
	dp[0] = 0;
	long long ans = inf;
	int fullMask = (1 << m) - 1;

	for (int i = 0; i < n; i++)
	{
		int curm = M[i].mask;
		int curMon = M[i].monNeed;
		long long add = M[i].cost;
		for (int j = 0; j < (1 << m); j++)
		{
			dp[j | curm] = min(dp[j | curm], dp[j] + add);
		}
		long long curAns = dp[fullMask] + curMon * 1LL * b;
		ans = min(ans, curAns);
	}
	if (ans == inf)
		ans = -1;
	printf("%I64d\n", ans);


	return 0;
}