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

const int __buffsize = 100000;
char __buff[__buffsize];
char *__buffs, *__buffe;

#define getc() (__buffs == __buffe ? fread(__buff, 1, __buffsize, stdin), __buffe = __buff + __buffsize, *((__buffs = __buff)++) : *(__buffs++))

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getc(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getc();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

#undef getc

const int maxn = 200000;

struct edge
{
	int id, nxt;

	edge() { }
	edge(int _id, int _nxt): id(_id), nxt(_nxt) { }

};

edge e[(maxn << 1) + 5];
int st[maxn + 5], en = 0;

inline void add_edge(int x, int y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int dfs_seq[maxn + 5], dfs_tot = 0;
int dfn[maxn + 5], End[maxn + 5];

int n, K;
int a[maxn + 5];

int fa[maxn + 5];

int cnt[maxn + 5], sz[maxn + 5];

int down[maxn + 5], sum_down[maxn + 5], up[maxn + 5], dp[maxn + 5];

int lim;

void dfs(int x, int f = -1)
{
	cnt[x] = a[x] < lim;
	sz[x] = 1;
	fa[x] = f;
	dfn[x] = dfs_tot;
	dfs_seq[dfs_tot++] = x;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		dfs(y, x);
		cnt[x] += cnt[y];
		sz[x] += sz[y];
	}
	End[x] = dfs_tot;
}

int calc(int __lim)
{
	memset(up, 0, sizeof up);
	memset(down, 0, sizeof down);
	memset(sum_down, 0, sizeof sum_down);
	memset(dp, 0, sizeof dp);
	lim = __lim;
	dfs_tot = 0;
	dfs(0);
	for (int i = dfs_tot - 1; i >= 0; --i)
	{
		int x = dfs_seq[i];
		if (a[x] < lim) continue;
		sum_down[x] = 1;
		for (int i = st[x]; i != -1; i = e[i].nxt)
		{
			int y = e[i].id;
			if (fa[x] == y) continue;
			if (!cnt[y]) sum_down[x] += sz[y];
			else chkmax(down[x], down[y]);
		}
		down[x] += sum_down[x];
	}
	up[dfs_seq[0]] = 0;
	REP(i, 0, dfs_tot)
	{
		int x = dfs_seq[i];
		if (a[x] < lim) continue;
		vector<int> all;
		for (int j = st[x]; j != -1; j = e[j].nxt)
		{
			int y = e[j].id;
			if (fa[x] == y) continue;
			all.pb(y);
		}
		int m = SZ(all);
		static int suf[maxn + 5];
		int sum = 1 + (cnt[x] == cnt[0] ? sz[0] - sz[x] : 0);
		suf[m] = (cnt[x] == cnt[0] ? 0 : up[x]);
		for (int i = m - 1; i >= 0; --i) 
		{
			if (!cnt[all[i]]) sum += sz[all[i]], suf[i] = suf[i + 1];
			else suf[i] = max(suf[i + 1], down[all[i]]);
		}
		int Max = 0;
		REP(i, 0, m)
		{
			up[all[i]] = max(Max, suf[i + 1]) + sum;
			if (!cnt[all[i]]) up[all[i]] -= sz[all[i]];
			else chkmax(Max, down[all[i]]);
		}
	}
	REP(i, 0, n) 
	{
		if (a[i] < lim) continue;
		dp[i] = down[i];
		if (cnt[i] == cnt[0]) dp[i] += sz[0] - sz[i];
		chkmax(dp[i], sum_down[i] + up[i]);
	}
	int ret = 0;
	REP(i, 0, n) chkmax(ret, dp[i]);
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	Read(n), Read(K);
	REP(i, 0, n) Read(a[i]);
	REP(i, 0, n - 1)
	{
		int x, y;
		Read(x), Read(y), --x, --y;
		add_edge(x, y), add_edge(y, x);
	}
	int l = 0, r = 1000000;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (calc(mid) < K) r = mid - 1;
		else l = mid;
	}
	printf("%d\n", l);
	return 0;
}