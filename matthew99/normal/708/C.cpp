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

const int maxn = 400100;

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

inline void add_biedge(int x, int y)
{
	add_edge(x, y);
	add_edge(y, x);
}

int n;

int fa[maxn + 5];

int sz[maxn + 5];

int lim[maxn + 5];

inline void deal(int u)
{
	int Max = 0, sMax = 0;
	for (int i = st[u]; i != -1; i = e[i].nxt)
	{
		int x = e[i].id;
		if (x == fa[u]) continue;
		if (sz[x] > Max) sMax = Max, Max = sz[x];
		else chkmax(sMax, sz[x]);
	}
	for (int i = st[u]; i != -1; i = e[i].nxt)
	{
		int x = e[i].id;
		if (x == fa[u]) continue;
		int tmp = sz[x] == Max ? sMax : Max;
		lim[x] = (n >> 1) + tmp;
	}
}

int Max[maxn + 5];

vector<int> seq;

void dfs(int x, int f = -1)
{
	seq.pb(x);
	fa[x] = f;
	sz[x] = 1;
	Max[x] = 0;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		dfs(y, x);
		sz[x] += sz[y];
		chkmax(Max[x], sz[y]);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	scanf("%d", &n);
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		add_biedge(u, v);
	}
	seq.clear();
	dfs(0);
	int rt = -1;
	REP(i, 0, n)
	{
		chkmax(Max[i], n - sz[i]);
		if (!~rt || Max[i] < Max[rt]) rt = i;
		if ((sz[i] << 1) == n)
		{
			REP(j, 0, n) printf("1 ");
			return 0;
		}
	}
	seq.clear();
	dfs(rt);
	lim[rt] = 0;
	REP(i, 0, n) deal(i);
	for (auto u : seq) if (~fa[u]) chkmax(lim[u], lim[fa[u]]);
	REP(i, 0, n)
	{
		bool ret = 0;
		if (i == rt) ret = 1;
		else if (n - sz[i] <= lim[i]) ret = 1;
		printf("%d ", ret);
	}
	return 0;
}