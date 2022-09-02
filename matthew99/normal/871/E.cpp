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

const int maxn = 30100, maxk = 210;

int n, K;
int d[maxk + 5][maxn + 5];

int where[maxk + 5];

bool given[maxn + 5];
bool known[maxn + 5];

int index[maxn + 5];

int lst_given = -1;

vector<pair<int, int> > ed;
vector<int> adj[maxn + 5];

pair<int, int> place[maxn + 5];

vector<pair<int, int> > all[maxn + 5];

int now[maxn + 5];

int X;

int fa[maxn + 5];

void dfs0(int x, int f = -1)
{
	fa[x] = f;
	for (auto y : adj[x]) if (y != f)
	{
		dfs0(y, x);
	}
}

int dis[maxn + 5];

void dfs1(int x, int f = -1)
{
	for (auto y : adj[x]) if (y != f)
	{
		dis[y] = dis[x] + 1;
		dfs1(y, x);
	}
}

bool check()
{
	REP(i, 0, K)
	{
		dis[where[i]] = 0;
		dfs1(where[i]);
		REP(j, 0, n) if (dis[j] != d[i][j]) return 0;
	}
	return 1;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	memset(index, -1, sizeof index);
	REP(i, 0, K)
	{
		static int a[maxn + 5];
		int id = -1;
		REP(j, 0, n)
		{
			scanf("%d", a + j);
			if (a[j] == 0) id = j;
		}
		if (!~id || given[id])
		{
			puts("-1");
			return 0;
		}
		memcpy(d[i], a, sizeof d[i]);
		lst_given = id;
		where[i] = id;
		if (i && !known[id])
		{
			int Minp = -1;
			REP(j, 0, n) if (known[j] && (!~Minp || d[i][Minp] > d[i][j])) Minp = j;
			assert(~Minp);
			static int pos[maxn + 5];
			REP(j, 0, n) pos[j] = j;
			sort(pos, pos + n, [&](int x, int y) { return d[i][x] < d[i][y]; });
			int lst = id;
			REP(j, 1, n) 
			{
				bool tmp = known[pos[j]];
				if (d[i][pos[j]] + d[i - 1][pos[j]] == d[i - 1][id])
				{
					known[pos[j]] = 1;
					ed.pb(mp(lst, pos[j]));
					lst = pos[j];
				}
				if (tmp) break;
			}
		}
		index[id] = i;
		given[id] = known[id] = 1;
	}
	REP(i, 0, SZ(ed)) adj[ed[i].x].pb(ed[i].y), adj[ed[i].y].pb(ed[i].x);
	dfs0(where[0]);
	REP(i, 0, n) if (!known[i]) place[i] = mp(d[0][i], where[0]);
	REP(i, 1, K)
	{
		vector<int> path;
		int u = where[i];
		do
		{
			path.pb(u);
			u = fa[u];
		}while (!given[u]);
		path.pb(u);
		REP(j, 0, n)
			if (!known[j])
			{
				int tmp = (d[i][j] - d[index[u]][j] + d[i][u]) >> 1;
				chkmin(place[j], mp((d[i][j] + d[index[u]][j] - d[i][u]) >> 1, path[tmp]));
			}
	}
	REP(i, 0, n) if (!known[i])
	{
		all[place[i].y].pb(mp(i, place[i].x));
	}
	REP(i, 0, n) if (SZ(all[i]))
	{
		static int vdep[maxn + 5];
		memset(vdep, -1, sizeof vdep);
		vdep[0] = i;
		sort(ALL(all[i]), [&](const pair<int, int> &x, const pair<int, int> &y) { return x.y < y.y; });
		for (auto u : all[i])
		{
			if (!~vdep[u.y - 1])
			{
				puts("-1");
				return 0;
			}
			ed.pb(mp(vdep[u.y - 1], u.x));
			vdep[u.y] = u.x;
		}
	}
	REP(i, 0, n) adj[i].clear();
	REP(i, 0, SZ(ed)) adj[ed[i].x].pb(ed[i].y), adj[ed[i].y].pb(ed[i].x);
	if (!check()) puts("-1");
	else
	{
		for (auto u : ed) printf("%d %d\n", u.x + 1, u.y + 1);
	}
	return 0;
}