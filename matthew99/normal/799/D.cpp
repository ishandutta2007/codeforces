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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

int mul[maxn + 5];

int a, b, h, w, n;

bool dfs(int curh, int curw, int p, int lst = -1)
{
	if (!p)
	{
		if (curh >= a && curw >= b) return 1;
		if (curh >= b && curw >= a) return 1;
		return 0;
	}
	REP(i, 0, 2)
	{
		if (p != n && mul[p - 1] == mul[p] && i < lst) continue;
		if (i == 0)
		{
			if (dfs(min((LL)maxn, (LL)curh * mul[p - 1]), curw, p - 1, i)) return 1;
		}
		else if (dfs(curh, min((LL)maxn, (LL)curw * mul[p - 1]), p - 1, i)) return 1;
	}
	return 0;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
	REP(i, 0, n) scanf("%d", mul + i);
	sort(mul, mul + n, greater<int>());
	REP(i, 0, n + 1)
	{
		if (dfs(h, w, i)) { printf("%d\n", i); return 0; }
	}
	printf("-1\n");
	return 0;
}