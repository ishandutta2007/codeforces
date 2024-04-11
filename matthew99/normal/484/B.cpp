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

const int maxn = 2e5, max0 = 1e6;

int n;
int a[maxn + 5];

int Max[max0 + 5];

int ans = -oo;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	memset(Max, -oo, sizeof Max);
	REP(i, 0, n) scanf("%d", a + i), Max[a[i]] = a[i];
	REP(i, 0, max0)
		Max[i + 1] = max(Max[i + 1], Max[i]);
	sort(a, a + n);
	n = unique(a, a + n) - a;
	REP(i, 0, n)
	{
		for (int j = 1; a[i] * j <= max0; ++j)
			ans = max(ans, Max[min(max0, a[i] * (j + 1) - 1)] - a[i] * j);
	}
	printf("%d\n", ans);
	return 0;
}