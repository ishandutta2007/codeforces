#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

const LL lim = 1000000000000LL;

LL dis(int x, int y)
{
	return (LL)x * x + (LL)y * y;
}

int n;
int x[maxn + 5], y[maxn + 5];
int ans[maxn + 5];

int curx = 0, cury = 0;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
	{
		scanf("%d%d", x + i, y + i);
	}
	curx = 0, cury = 0;
	for (int i = 0; i < n; ++i)
	{
		ans[i] = 1;
		if (dis(curx + ans[i] * x[i], cury + ans[i] * y[i]) > dis(curx - ans[i] * x[i], cury - ans[i] * y[i])) ans[i] = -1;
		while (dis(curx + ans[i] * x[i], cury + ans[i] * y[i]) > 2 * lim)
		{
			int j = rand() % i;
			ans[j] = -ans[j];
			curx += 2 * ans[j] * x[j];
			cury += 2 * ans[j] * y[j];
			if (dis(curx + ans[i] * x[i], cury + ans[i] * y[i]) > dis(curx - ans[i] * x[i], cury - ans[i] * y[i])) ans[i] = -1;
		}
		curx += ans[i] * x[i];
		cury += ans[i] * y[i];
	}
	REP(i, 0, n) printf("%d ", ans[i]);
	return 0;
}