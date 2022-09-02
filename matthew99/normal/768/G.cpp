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
	add_edge(x, y), add_edge(y, x);
}

int n;

int rt;

int sz[maxn + 5];
int dfs_tot;
int dfn[maxn + 5], End[maxn + 5];

int fa[maxn + 5];
int Max[maxn + 5], Maxp[maxn + 5], sMax[maxn + 5], Min[maxn + 5];

inline void add_sz(int x, int s, int id)
{
	chkmin(Min[x], s);
	if (s > Max[x]) sMax[x] = Max[x], Max[x] = s, Maxp[x] = id;
	else chkmax(sMax[x], s);
}

void dfs0(int x, int f = -1)
{
	fa[x] = f;
	dfn[x] = dfs_tot++;
	sz[x] = 1;
	Max[x] = 0, Maxp[x] = -1, Min[x] = oo;
	sMax[x] = -1;
	for (int i = st[x]; ~i; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		dfs0(y, x);
		add_sz(x, sz[y], y);
		sz[x] += sz[y];
	}
	End[x] = dfs_tot;
}

vector<int> fen[maxn + 5];

int ans[maxn + 5];

int now[maxn + 5];

void dfs1(int x, int f = -1)
{
	if (~sMax[x])
	{
		int l = sMax[x], r = ans[x];
		while (l < r)
		{
			int mid = (l + r) >> 1;
			int low = Max[x] - mid, up = mid - Min[x];
			int tot = 0;
			if (low <= up)
			{
				--low;
				if (Maxp[x] == fa[x])
				{
					for (int i = up; i > 0; i -= i & -i)
					{
						tot += SZ(fen[i]) - (lower_bound(ALL(fen[i]), End[x]) - lower_bound(ALL(fen[i]), dfn[x]));
						tot -= now[i];
					}
					for (int i = low; i > 0; i -= i & -i)
					{
						tot -= SZ(fen[i]) - (lower_bound(ALL(fen[i]), End[x]) - lower_bound(ALL(fen[i]), dfn[x]));
						tot += now[i];
					}
					for (int i = min(n, up + sz[x]); i > 0; i -= i & -i) tot += now[i];
					for (int i = min(n, low + sz[x]); i > 0; i -= i & -i) tot -= now[i];
				}
				else
				{
					for (int i = up; i > 0; i -= i & -i)
					{
						tot += lower_bound(ALL(fen[i]), End[Maxp[x]]) - lower_bound(ALL(fen[i]), dfn[Maxp[x]]);
					}
					for (int i = low; i > 0; i -= i & -i)
					{
						tot -= lower_bound(ALL(fen[i]), End[Maxp[x]]) - lower_bound(ALL(fen[i]), dfn[Maxp[x]]);
					}
				}
			}
			if (tot) r = mid;
			else l = mid + 1;
		}
		chkmin(ans[x], l);
	}
	for (int i = sz[x]; i <= n; i += i & -i) ++now[i];
	for (int i = st[x]; ~i; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		dfs1(y, x);
	}
	for (int i = sz[x]; i <= n; i += i & -i) --now[i];
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st);
	scanf("%d", &n);
	if (n == 1)
	{
		printf("0\n");
		return 0;
	}
	REP(i, 0, n)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if (u && v) 
		{
			--u, --v;
			add_biedge(u, v);
		}
		else rt = max(u, v) - 1;
	}
	dfs0(rt);
	REP(i, 0, n) if (i != rt) add_sz(i, n - sz[i], fa[i]);
	REP(i, 0, n) ans[i] = Max[i];
	REP(i, 0, n) for (int j = sz[i]; j <= n; j += j & -j) fen[j].pb(dfn[i]);
	REP(i, 0, n + 1) sort(ALL(fen[i]));
	dfs1(rt);
	REP(i, 0, n) printf("%d\n", ans[i]);
	return 0;
}