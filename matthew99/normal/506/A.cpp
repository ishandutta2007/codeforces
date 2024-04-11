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

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 30000;
const int max0 = 1000;

int n, d;
int a[maxn + 5];

int dp[maxn + 5][max0 + 5];
int ans = 0;

template<typename T> bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &d);
	REP(i, 0, n)
	{
		static int x;
		scanf("%d", &x);
		++a[x - d];
	}
	memset(dp, -oo, sizeof dp);
	dp[0][max0 >> 1] = a[0];
	ans = a[0];
	REP(i, 0, maxn)
	{
		REP(j, 0, max0)
		{
			int dis = d + j - (max0 >> 1);
			if (dp[i][j] >= 0)
			{
				chkmax(ans, dp[i][j]);
				if (i + dis - 1 < maxn && j >= 0) chkmax(dp[i + dis - 1][j - 1], dp[i][j] + a[i + dis - 1]);
				if (i + dis < maxn) chkmax(dp[i + dis][j], dp[i][j] + a[i + dis]);
				if (i + dis + 1 < maxn) chkmax(dp[i + dis + 1][j + 1], dp[i][j] + a[i + dis + 1]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}