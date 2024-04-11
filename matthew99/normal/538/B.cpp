#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <set>

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

const int oo = 0x3f3f3f3f;

const int maxn = 1000000;

int dp[maxn + 5];
int pre[maxn + 5];

int alln;
int all[maxn + 5];

inline void prepare()
{
	REP(j, 0, 1 << 7)
	{
		int tmp = 0;
		REP(k, 0, 7) (tmp *= 10) += (j >> k) & 1;
		if (tmp <= maxn) all[alln++] = tmp;
	}
	sort(all, all + alln);
	dp[0] = 0, pre[0] = -1;
	REP(i, 1, maxn + 1)
	{
		dp[i] = oo;
		REP(j, 0, alln)
			if (all[j] > i) break;
			else if (dp[i - all[j]] + 1 < dp[i]) dp[i] = dp[i - all[j]] + 1, pre[i] = all[j];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	int n;
	scanf("%d", &n);
	printf("%d\n", dp[n]);
	while (n)
	{
		printf("%d ", pre[n]);
		n -= pre[n];
	}
	return 0;
}