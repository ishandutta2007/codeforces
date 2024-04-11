#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int Mod = 1e9 + 7;
const int maxn = 50;

int n;
LL k;
int p[maxn + 5];

LL dp[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%I64d", &n, &k);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = dp[i - 1];
		if (i >= 2) dp[i] += dp[i - 2];
	}
	for (int i = 1; i <= n; )
	{
		if (dp[n - i] >= k)
		{
			printf("%d ", i);
			++i;
		}
		else
		{
			k -= dp[n - i];
			printf("%d ", i + 1);
			printf("%d ", i);
			i += 2;
		}
	}
	return 0;
}