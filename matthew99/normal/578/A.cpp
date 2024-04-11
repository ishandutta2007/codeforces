#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	scanf("%d%d", &a, &b);
	int tmp = a - b;
	int tmp0 = tmp / b;
	double ans = 1e100;
	for (int j = tmp0 - 2; j <= tmp0 + 2; ++j)
		if (j > 0 && ((j & 1) == 0))
		{
			if (tmp / j >= b) chkmin(ans, (double)tmp / j);
		}
	tmp = a + b;
	tmp0 = tmp / b;
	for (int j = tmp0 - 2; j <= tmp0 + 2; ++j)
		if (j > 0 && ((j & 1) == 0))
		{
			if (tmp / j >= b) chkmin(ans, (double)tmp / j);
		}
	if (ans > 1e50) printf("-1\n");
	else printf("%.15f\n", ans);
	return 0;
}