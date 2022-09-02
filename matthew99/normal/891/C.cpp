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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 500100, maxm = 500100;

int n, m;

struct edge
{
	int x, y, w, id;

	edge() { }
	edge(int _x, int _y, int _w): x(_x), y(_y), w(_w) { }

	friend bool operator<(const edge &x, const edge &y)
	{
		return x.w < y.w;
	}

};

edge e[maxm + 5];

int qn;

vector<int> allq[maxm + 5];

bool ok[maxm + 5];

int fa[maxn + 5], sz[maxn + 5];

int get(int x) { return fa[x] == x ? x : get(fa[x]); }

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, m) scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w), e[i].id = i;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		ok[i] = 1;
		int k;
		scanf("%d", &k);
		REP(j, 0, k)
		{
			int x;
			scanf("%d", &x), --x;
			allq[x].pb(i);
		}
	}
	REP(i, 0, n) fa[i] = i, sz[i] = 1;
	sort(e, e + m);
	for (int i = 0, j = 0; i < m; )
	{
		map<int, vector<int> > alle;
		for (j = i; j < m && e[j].w == e[i].w; ++j)
		{
			for (auto u : allq[e[j].id]) alle[u].pb(j);
		}
		for (auto u : alle)
		{
			vector<pair<int, int> > recover;
			for (auto v : u.y)
			{
				int x = get(e[v].x), y = get(e[v].y);
				if (x == y)
				{
					ok[u.x] = 0;
					break;
				}
				if (sz[x] < sz[y]) swap(x, y);
				fa[y] = x;
				sz[x] += sz[y];
				recover.pb(mp(x, y));
			}
			while (!recover.empty())
			{
				int x = recover.back().x;
				int y = recover.back().y;
				recover.pop_back();
				sz[x] -= sz[y];
				fa[y] = y;
			}
		}
		for ( ; i < j; ++i)
		{
			int x = get(e[i].x), y = get(e[i].y);
			if (x != y)
			{
				if (sz[x] < sz[y]) swap(x, y);
				fa[y] = x;
				sz[x] += sz[y];
			}
		}
	}
	REP(i, 0, qn)
	{
		if (ok[i]) puts("YES");
		else puts("NO");
	}
	return 0;
}