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

const int maxn = 1000100;
const int maxm = 2000100;

int n, m;

struct data
{
	int x, y, l, r;
	
	data() { }
	data(int _x, int _y, int _l, int _r): x(_x), y(_y), l(_l), r(_r) { }

};

multiset<int> adj[maxn + 5];

data ed[maxm + 5];

map<int, vector<int> > all;

int now;
int dis[maxn + 5];

inline void adde(int x, int y)
{
	adj[x].insert(y);
	if (dis[x] <= now && chkmin(dis[y], now + 1))
	{
		if (dis[y] < oo) all[dis[y]].pb((m << 1) + y);
	}
}

inline void dele(int x, int y)
{
	adj[x].erase(adj[x].find(y));
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	if (n == 1)
	{
		printf("0\n");
		return 0;
	}
	REP(i, 0, m)
	{
		int x, y, l, r;
		scanf("%d%d%d%d", &x, &y, &l, &r), --x, --y;
		int l0 = l, l1 = l;
		if (l & 1) ++l0;
		else ++l1;
		ed[i << 2] = data(x << 1, y << 1 | 1, l0, r);
		ed[i << 2 | 1] = data(y << 1, x << 1 | 1, l0, r);
		ed[i << 2 | 2] = data(x << 1 | 1, y << 1, l1, r);
		ed[i << 2 | 3] = data(y << 1 | 1, x << 1, l1, r);
	}
	memset(dis, oo, sizeof dis);
	m <<= 2;
	REP(i, 0, m) if (ed[i].l < ed[i].r)
	{
		if (!ed[i].l && !ed[i].x) dis[0] = 0;
		all[ed[i].l].pb(i << 1 | 1);
		all[ed[i].r].pb(i << 1);
	}
	int ans = oo;
	for (auto uu : all)
	{
		now = uu.x;
		set<int> to_check;
		set<int> to_expand;
		for (auto u : uu.y)
		{
			if (u < (m << 1))
			{
				int tmp = u >> 1;
				if (u & 1) 
				{
					adde(ed[tmp].x, ed[tmp].y);
				}
				else 
				{
					dele(ed[tmp].x, ed[tmp].y);
					to_check.insert(ed[tmp].x);
				}
			}
			else to_expand.insert(u - (m << 1));
		}
		for (auto u : to_expand) if (dis[u] <= now)
		{
			for (auto v : adj[u])
				if (chkmin(dis[v], now + 1))
				{
					if (dis[v] < oo) all[dis[v]].pb((m << 1) + v);
				}
		}
		for (auto u : to_check)
		{
			if (adj[u].empty()) dis[u] = oo;
		}
		chkmin(ans, dis[(n - 1) << 1]);
		chkmin(ans, dis[(n - 1) << 1 | 1]);
	}
	if (ans >= oo) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}