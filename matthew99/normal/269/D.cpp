//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <set>
#include <vector>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define foreach(e, x) for (__typeof__((x).begin()) e = (x).begin(); e != (x).end(); ++e)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

using namespace std;

const int oo = 0x3f3f3f3f;

const int maxn = 100000;

const int max_abs = (int)1e9;

struct data
{
	int l, r, h;

	data() { }
	data(const int &_l, const int &_r, const int &_h): l(_l), r(_r), h(_h) { }

};

int n, t;

data a[maxn + 5];

pair<int, int> pos[(maxn << 1) + 5];

int ans = 0;

void init()
{
	scanf("%d%d", &n, &t);
	REP(i, 0, n)
		scanf("%d%d%d", &a[i].h, &a[i].l, &a[i].r), pos[i << 1] = mp(a[i].l, i), pos[i << 1 | 1] = mp(a[i].r, -i - 1);
}

int ra[maxn + 5], rb[maxn + 5];

vector<int> v[maxn + 5];

int dp[maxn + 5];

bool cmp(const int &x, const int &y)
{
	return a[x].h < a[y].h;
}

set<pair<int, int> > ed;

void solve()
{
	set<pair<int, int> > all;
	sort(pos, pos + (n << 1));
	all.insert(mp(0, n));
	all.insert(mp(t, n + 1));
	memset(ra, -oo, sizeof ra);
	memset(rb, -oo, sizeof rb);
	REP(i, 0, n << 1)
	{
		if (pos[i].y >= 0) 
		{
			__typeof__(all.begin()) pre = all.lower_bound(mp(a[pos[i].y].h, pos[i].y)), nxt = pre--;
			ed.erase(mp(nxt->y, pre->y));
			ed.insert(mp(nxt->y, pos[i].y));
			ed.insert(mp(pos[i].y, pre->y));
			all.insert(mp(a[pos[i].y].h, pos[i].y));
		}
		else
		{
			int x = -pos[i].y - 1;
			all.erase(mp(a[x].h, x));
		}
	}
	foreach(e, ed) v[e->x].pb(e->y);
	static int pos0[maxn + 5];
	REP(i, 0, n) pos0[i] = i;
	sort(pos0, pos0 + n, cmp);
	dp[n] = 2e9;
	pos0[n] = n + 1;
	a[n] = data(-1e9, 1e9, 0);
	a[n + 1] = data(-1e9, 1e9, t);
	REP(i, 0, n + 1)
	{
		const int &x = pos0[i];
		REP(j, 0, SZ(v[x]))
			dp[x] = max(dp[x], min(dp[v[x][j]], min(a[v[x][j]].r, a[x].r) - max(a[v[x][j]].l, a[x].l)));
	}
	ans = dp[n + 1];
}

void output()
{
	printf("%d\n", ans);
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