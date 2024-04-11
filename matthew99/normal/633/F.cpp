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

const int maxn = 100000, maxm = 1000;

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

int n;
int a[maxn + 5];

int fa[maxn + 5];

LL down[maxn + 5], up[maxn + 5], mdown[maxn + 5], mup[maxn + 5], mmdown[maxn + 5], mmup[maxn + 5];

void dfs(int x, int f = -1)
{
	fa[x] = f;
	dfn[x] = dfs_tot;
	dfs_seq[dfs_tot++] = x;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		dfs(y, x);
	}
	End[x] = dfs_tot;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	Read(n);
	REP(i, 0, n) Read(a[i]);
	REP(i, 0, n - 1)
	{
		int x, y;
		Read(x), Read(y), --x, --y;
		add_edge(x, y), add_edge(y, x);
	}
	dfs(0);
	for (int i = dfs_tot - 1; i >= 0; --i)
	{
		int x = dfs_seq[i];
		down[x] = mdown[x] = a[x];
		mmdown[x] = 0;
		for (int i = st[x]; i != -1; i = e[i].nxt)
		{
			int y = e[i].id;
			if (fa[x] == y) continue;
			chkmax(mmdown[x], mmdown[y]);
			chkmax(mdown[x], down[x] + down[y]);
			chkmax(down[x], down[y] + a[x]);
		}
		chkmax(mmdown[x], mdown[x]);
	}
	up[dfs_seq[0]] = mup[dfs_seq[0]] = 0;
	REP(i, 0, dfs_tot)
	{
		int x = dfs_seq[i];
		vector<int> all;
		static LL pre[maxn + 5], suf[maxn + 5], mpre[maxn + 5], msuf[maxn + 5];
		static LL mmpre[maxn + 5], mmsuf[maxn + 5];
		for (int j = st[x]; j != -1; j = e[j].nxt)
		{
			int y = e[j].id;
			if (fa[x] == y) continue;
			all.pb(y);
		}
		int m = SZ(all);
		pre[0] = up[x];
		mpre[0] = up[x] + a[x];
		mmpre[0] = mup[x];
		mmsuf[m] = 0;
		suf[m] = 0;
		msuf[m] = 0;
		REP(j, 0, m) pre[j + 1] = max(pre[j], down[all[j]]), mpre[j + 1] = max(mpre[j], pre[j] + down[all[j]] + a[x]), mmpre[j + 1] = max(mmpre[j], mmdown[all[j]]);
		for (int j = m - 1; j >= 0; --j) suf[j] = max(suf[j + 1], down[all[j]]), msuf[j] = max(msuf[j + 1], suf[j + 1] + down[all[j]] + a[x]), mmsuf[j] = max(mmsuf[j + 1], mmdown[all[j]]);
		REP(j, 0, m)
		{
			up[all[j]] = max(pre[j], suf[j + 1]) + a[x];
			mup[all[j]] = max(mpre[j], max(msuf[j + 1], pre[j] + suf[j + 1] + a[x]));
			mmup[all[j]] = max(mmpre[j], mmsuf[j + 1]);
			chkmax(mmup[all[j]], mup[all[j]]);
		}
	}
	LL ans = 0;
	REP(i, 0, n) chkmax(ans, mmup[i] + mmdown[i]);
	printf("%I64d\n", ans);
	return 0;
}