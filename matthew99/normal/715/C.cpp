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

int ex_gcd(const int &a, const int &b, int &x, int &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

const int maxn = 100100;

struct edge
{
	int id, g, nxt;

	edge() { }
	edge(int _id, int _g, int _nxt): id(_id), g(_g), nxt(_nxt) { }

};

edge e[(maxn << 1) + 5];
int st[maxn + 5], en = 0;

inline void add_edge(int x, int y, int z)
{
	e[en] = edge(y, z, st[x]), st[x] = en++;
}

int n, Mod;

int sz[maxn + 5];
int Max[maxn + 5];
int dfs_seq[maxn + 5], dfs_tot = 0;

void pre_dfs(int x, int f = -1)
{
	dfs_seq[dfs_tot++] = x;
	sz[x] = 1;
	Max[x] = 0;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		pre_dfs(y, x);
		sz[x] += sz[y];
		chkmax(Max[x], sz[y]);
	}
}

int pw[maxn + 5];
int inv[maxn + 5];

int col[maxn + 5];
int dep[maxn + 5];
int val[maxn + 5];
int ival[maxn + 5];

void formal_dfs(int x, int f = -1)
{
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		if (f == -1) col[y] = y;
		else col[y] = col[x];
		dep[y] = dep[x] + 1;
		val[y] = ((val[x] * 10LL) + e[i].g) % Mod;
		ival[y] = (ival[x] + (LL)e[i].g * pw[dep[x]] % Mod) % Mod;
		formal_dfs(y, x);
	}
}

bool del_edge(int x, int y)
{
	for (int *i = st + x; *i != -1; i = &e[*i].nxt)
		if (e[*i].id == y)
		{
			*i = e[*i].nxt;
			return 1;
		}
	return 0;
}

LL ans = 0;

map<int, int> sub[maxn + 5];

void work(int rt)
{
	dfs_tot = 0;
	pre_dfs(rt);
	int x = -1;
	REP(i, 0, dfs_tot)
	{
		int y = dfs_seq[i];
		chkmax(Max[y], sz[rt] - sz[y]);
		if (x == -1 || Max[y] < Max[x]) x = y;
	}
	REP(i, 0, dfs_tot) sub[dfs_seq[i]].clear();
	col[x] = -1;
	val[x] = ival[x] = dep[x] = 0;
	formal_dfs(x);
	map<int, int> full;
	REP(i, 0, dfs_tot)
	{
		int y = dfs_seq[i];
		++full[ival[y]];
		if (~col[y]) ++sub[col[y]][ival[y]];
	}
	REP(i, 0, dfs_tot)
	{
		int y = dfs_seq[i];
		int need = (LL)inv[dep[y]] * val[y] % Mod;
		need = (-need + Mod) % Mod;
		ans += full[need];
		if (~col[y]) ans -= sub[col[y]][need];
	}
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		assert(del_edge(e[i].id, x));
		work(e[i].id);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &Mod);
	int step, tmp;
	ex_gcd(Mod, 10, tmp, step);
	(((step %= Mod) += Mod) %= Mod);
	inv[0] = pw[0] = 1;
	REP(i, 0, maxn) inv[i + 1] = (LL)inv[i] * step % Mod;
	REP(i, 0, maxn) pw[i + 1] = (LL)pw[i] * 10 % Mod;
	memset(st, -1, sizeof st), en = 0;
	REP(i, 0, n - 1)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	work(0);
	ans -= n;
	cout << ans << endl;
	return 0;
}