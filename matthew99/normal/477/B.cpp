#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const int Mod = 1e9 + 7;

const int maxn = 10000;

int n, k;

int a[maxn + 5][4];

int ans;

void init()
{
	scanf("%d%d", &n, &k);
}

int gcd(int x, int y)
{
	while (y) y ^= x ^= y ^= x %= y;
	return x;
}

void solve()
{
	memset(a, -1, sizeof a);
	REP(i, 0, n)
		a[i][0] = 6 * i + 1, a[i][1] = 6 * i + 2, a[i][2] = 6 * i + 3, a[i][3] = 6 * i + 5, ans = a[i][3] * k;
}

void output()
{
	printf("%d\n", ans);
	REP(i, 0, n)
		printf("%d %d %d %d\n", a[i][0] * k, a[i][1] * k, a[i][2] * k, a[i][3] * k);
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