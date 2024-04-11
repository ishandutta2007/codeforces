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
 
#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() rand()
#endif
 
template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
typedef long long LL;
 
const int oo = 0x3f3f3f3f;
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getchar(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getchar();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

const int maxn = 300000, max0 = 19;

struct edge
{
	int id, nxt;

	edge() { }
	edge(int _id, int _nxt): id(_id), nxt(_nxt) { }

};

int en;
edge e[(maxn << 1) + 5];

int st[maxn + 5];

char s[maxn + 5];

inline void add_edge(int x, int y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int n;

int fa[max0][maxn + 5];

int seq[maxn + 5], tot = 0;

int dep[maxn + 5];

void dfs(int x)
{
	seq[tot++] = x;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == fa[0][x]) continue;
		fa[0][y] = x;
		dep[y] = dep[x] + 1;
		dfs(y);
	}
}

inline void sortx(int *a, int *b, int *c, int n, int m)
{
	static int sum[maxn + 5];
	REP(i, 0, m) sum[i] = 0;
	REP(i, 0, n) ++sum[a[b[i]]];
	REP(i, 1, m) sum[i] += sum[i - 1];
	for (int i = n - 1; i >= 0; --i) c[--sum[a[b[i]]]] = b[i];
}

int sa[maxn + 5], rk[maxn + 5];
int w[maxn + 5];

set<int> all[maxn + 5];
int id[maxn + 5];

int Max = -1, Maxcnt = 0;

void dfs0(int x)
{
	id[x] = x;
	all[id[x]].insert(rk[x]);
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == fa[0][x]) continue;
		dfs0(y);
		if (SZ(all[id[x]]) < SZ(all[id[y]])) swap(id[x], id[y]);
		for (auto it : all[id[y]]) all[id[x]].insert(it);
		all[id[y]].clear();
	}
	int tmp = SZ(all[id[x]]) + w[x];
	if (chkmax(Max, tmp)) Maxcnt = 1;
	else if (Max == tmp) ++Maxcnt;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	srand(time(NULL));
#endif
	memset(st, -1, sizeof st), en = 0;
	Read(n);
	REP(i, 0, n) Read(w[i]);
	scanf("%s", s);
	REP(i, 0, n - 1)
	{
		int x, y;
		Read(x), Read(y), --x, --y;
		add_edge(x, y);
		add_edge(y, x);
	}
	dep[0] = 0;
	fa[0][0] = -1;
	dfs(0);
	REP(i, 1, max0) REP(j, 0, n)
		if (fa[i - 1][j] == -1) fa[i][j] = fa[i - 1][j];
		else fa[i][j] = fa[i - 1][fa[i - 1][j]];
	static int x[maxn + 5], y[maxn + 5];;
	REP(i, 0, n) x[i] = s[i], y[i] = i;
	sortx(x, y, sa, n, CHAR_MAX);
	int cnt = 0;
	rk[sa[0]] = 0;
	REP(i, 1, n) rk[sa[i]] = rk[sa[i - 1]] + (x[sa[i - 1]] != x[sa[i]]);
	while (1 << cnt < n)
	{
		REP(i, 0, n) x[i] = rk[i], y[i] = fa[cnt][i] == -1 ? 0 : rk[fa[cnt][i]] + 1;
		sortx(y, sa, rk, n, n + 1);
		sortx(x, rk, sa, n, n);
		rk[sa[0]] = 0;
		REP(i, 1, n) rk[sa[i]] = rk[sa[i - 1]] + (x[sa[i - 1]] != x[sa[i]] || y[sa[i - 1]] != y[sa[i]]);
		++cnt;
	}
	dfs0(0);
	printf("%d\n%d\n", Max, Maxcnt);
	return 0;
}