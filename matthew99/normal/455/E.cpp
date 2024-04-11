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

const int maxn = 100000, maxm = 100000;

int n, m;
int sum[maxn + 5];
int a[maxn + 5];

vector<pair<int, int> > all[maxn + 5];

int ans[maxm + 5];

inline int calc(int l, int mid, int r) { return a[mid] * (mid - l) + sum[r] - sum[mid]; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	sum[0] = 0;
	REP(i, 0, n) scanf("%d", a + i), sum[i + 1] = sum[i] + a[i];
	scanf("%d", &m);
	REP(i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y), --y;
		all[y].pb(mp(x, i));
	}
	static int p[maxn + 5], st[maxn + 5];
	int tot = 0;
	REP(i, 0, n)
	{
		while (tot)
		{
			int old = calc(st[tot - 1], p[tot - 1], i + 1);
			int now = calc(st[tot - 1], i, i + 1);
			if (now > old) break;
			--tot;
		}
		if (!tot) st[tot] = 0;
		else
		{
			int l = st[tot - 1], r = p[tot - 1] + 1;
			while (l < r)
			{
				int mid = (l + r) >> 1;
				if (calc(mid, p[tot - 1], i + 1) > calc(mid, i, i + 1)) r = mid;
				else l = mid + 1;
			}
			st[tot] = l;
		}
		p[tot++] = i;
		for (auto x : all[i])
		{
			int tmp = i + 1 - x.x;
			int best = upper_bound(st, st + tot, tmp) - st - 1;
			ans[x.y] = calc(tmp, p[best], i + 1);
		}
	}
	REP(i, 0, m) printf("%d\n", ans[i]);
	return 0;
}