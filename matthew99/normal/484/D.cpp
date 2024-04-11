#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <ctime>
#include <vector>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1e6;

int n;
int a[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	if (n == 1)
	{
		printf("0\n");
		return 0;
	}
	REP(i, 0, n) scanf("%d", a + i);
	LL dp = 0;
	LL Max0 = -oo, Max1 = -oo;
	REP(i, 0, n)
	{
		LL tmp0 = dp;
		dp = max(dp, max(Max0 - a[i], Max1 + a[i]));
		Max0 = max(Max0, tmp0 + a[i]);
		Max1 = max(Max1, tmp0 - a[i]);
	}
	printf("%I64d\n", dp);
	return 0;
}