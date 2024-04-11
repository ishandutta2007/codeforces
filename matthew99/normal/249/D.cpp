#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <ctime>
#include <iostream>
#include <vector>
#include <climits>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
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

const int maxn = 200000;

LL ans;

int n, A, B, C, D;

pair<LL, LL> a[maxn + 5];

void init()
{
	scanf("%d%d/%d%d/%d", &n, &B, &A, &D, &C);
	if (!(A * D - B * C))
	{
		printf("0\n");
		exit(0);
	}
	REP(i, 0, n) 
	{
		int a, b;
		scanf("%d%d", &a, &b);
		::a[i].x = (LL)a * D - (LL)b * C;
		::a[i].y = (LL)A * b - (LL)B * a;
	}
}

LL dp[maxn + 5];

void solve()
{
	REP(i, 0, n) a[i].y = -a[i].y;
	sort(a, a + n);
	REP(i, 0, n) a[i].y = -a[i].y;
	static LL c[maxn + 5];
	memset(c, 0, sizeof c);
	ans = 0;
	REP(i, 0, n + 1) c[i] = 0;
	c[0] = LLONG_MIN;
	for (int i = n - 1; i >= 0; --i)
	{
		if (a[i].x <= 0 || a[i].y <= 0) continue;
		dp[i] = lower_bound(c, c + n, -a[i].y) - c;
		c[dp[i]] = -a[i].y;
		ans = max(ans, dp[i]);
	}
}

void output()
{
	cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	solve();
	output();
	return 0;
}