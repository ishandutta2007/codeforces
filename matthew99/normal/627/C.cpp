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
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 200000;

int d, V, n;

pair<int, int> a[maxn + 5];

LL dp[maxn + 5];

int Min[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(Min, -1, sizeof Min);
	scanf("%d%d%d", &d, &V, &n);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y);
	a[n++] = mp(0, 0);
	a[n++] = mp(d, 0);
	sort(a, a + n);
	REP(i, 0, n - 1) if (a[i].x + V < a[i + 1].x) { printf("-1\n"); return 0; }
	LL ans = 0;
	int lst = 0, cur = 0;
	REP(i, 1, n)
	{
		cur = a[i - 1].x;
		while (a[lst].x + V < a[i].x)
		{
			ans += (LL)(a[lst].x + V - cur) * a[lst].y;
			cur = a[lst].x + V;
			int best = -1;
			for (int j = lst + 1; j <= n; j += j & -j) if (best == -1 || (Min[j] != -1 && a[Min[j]].y < a[best].y)) best = Min[j];
			lst = best;
		}
		ans += (LL)(a[i].x - cur) * a[lst].y;
		cur = a[i].x;
		if (a[i].y < a[lst].y) lst = i;
		for (int j = i; j > 0; j -= j & -j) if (Min[j] == -1 || a[Min[j]].y > a[i].y) Min[j] = i;
	}
	printf("%I64d\n", ans);
	return 0;
}