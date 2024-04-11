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

const int maxn = 100100;

int n, m;
vector<pair<int, int> > adj[maxn + 5];

vector<pair<int, int> > ob[maxn + 5];

set<pair<int, int> > dpl[maxn + 5];
set<pair<int, int> > dpr[maxn + 5];

priority_queue<pair<int, int> > q;

int dis[maxn + 5];

inline auto peekr(int u, int x, int d)
{
	auto tmp = dpr[x].upper_bound(mp(u + d, oo));
	if (tmp == dpr[x].begin()) return dpr[x].end();
	return --tmp;
}

inline auto peekl(int u, int x, int d)
{
	return dpl[x].lower_bound(mp(u - d, -oo));
}

inline void insertl(int u, int v, int x, int d)
{
	{
		auto tmp = peekl(u, x, d);
		if (tmp != dpl[x].end() && tmp->x == u - d) 
		{
			auto tmp0 = *tmp;
			dpl[x].erase(tmp);
			dpl[x].insert(mp(tmp0.x, tmp0.y + v));
		}
		else dpl[x].insert(mp(u - d, v));
	}
	{
		auto tmp = peekr(u, x, d);
		if (tmp != dpr[x].end())
			q.push(mp((tmp->x - (u - d)) >> 1, (tmp->x + (u - d)) >> 1));
	}
}

inline void insertr(int u, int v, int x, int d)
{
	{
		auto tmp = peekr(u, x, d);
		if (tmp != dpr[x].end() && tmp->x == u + d) 
		{
			auto tmp0 = *tmp;
			dpr[x].erase(tmp);
			dpr[x].insert(mp(tmp0.x, tmp0.y + v));
		}
		else dpr[x].insert(mp(u + d, v));
	}
	{
		auto tmp = peekl(u, x, d);
		if (tmp != dpl[x].end())
			q.push(mp(((u + d) - tmp->x) >> 1, ((u + d) + tmp->x) >> 1));
	}
}

inline void go(int d, int x)
{
	while (!q.empty())
	{
		auto u = q.top();
		if (u.x < d) break;
		q.pop();
		int wl = u.x;
		int wr = -u.x;
		int sum = 0;
		bool yesl = 0, yesr = 0;
		auto tmpl = dpl[x].lower_bound(mp(u.y - wl, -oo));
		if (tmpl != dpl[x].end() && tmpl->x == u.y - wl)
		{
			yesl = 1;
			sum += tmpl->y;
		}
		auto tmpr = dpr[x].lower_bound(mp(u.y - wr, -oo));
		if (tmpr != dpr[x].end() && tmpr->x == u.y - wr)
		{
			yesr = 1;
			sum += tmpr->y;
		}
		if (yesl && yesr)
		{
			dpl[x].erase(tmpl);
			dpr[x].erase(tmpr);
			if (sum > 0) insertl(u.y, sum, x, u.x);
			else insertr(u.y, sum, x, u.x);
		}
	}
}

void dfs(int x, int f = -1)
{
	for (auto y : adj[x])
		if (y.x != f)
		{
			dis[y.x] = dis[x] + y.y;
			dfs(y.x, x);
			go(dis[x], y.x);

			if (SZ(dpl[x]) + SZ(dpr[x]) < SZ(dpl[y.x]) + SZ(dpr[y.x])) 
			{
				swap(dpl[x], dpl[y.x]);
				swap(dpr[x], dpr[y.x]);
			}
			for (auto u : dpl[y.x]) insertl(u.x + dis[x], u.y, x, dis[x]);
			dpl[y.x].clear();

			for (auto u : dpr[y.x]) insertr(u.x - dis[x], u.y, x, dis[x]);
			dpr[y.x].clear();

		}

	vector<pair<int, int> > to_add;

	for (auto u : ob[x])
	{
		{
			auto tmp = peekr(u.x - 1, x, dis[x]);
			if (tmp != dpr[x].end() && tmp->x == u.x - 1 + dis[x]) 
			{
				if (u.y + tmp->y <= 0) continue;
				to_add.pb(mp(u.x, u.y + tmp->y));
				dpr[x].erase(tmp);
			}
			else to_add.pb(mp(u.x, u.y));
		}
		{
			auto tmp = peekl(u.x + 1, x, dis[x]);
			if (tmp != dpl[x].end() && tmp->x == u.x + 1 - dis[x]) 
			{
				to_add.pb(mp(u.x, -u.y + tmp->y));
				dpl[x].erase(tmp);
			}
			else to_add.pb(mp(u.x, -u.y));
		}
	}

	go(dis[x] - 2, x);
	for (auto u : to_add) 
	{
		if (u.y > 0) insertl(u.x - 1, u.y, x, dis[x] - 2);
		if (u.y < 0) insertr(u.x + 1, u.y, x, dis[x] - 2);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n - 1)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w), --u, --v, w *= 4;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	scanf("%d", &m);
	REP(i, 0, m)
	{
		int d, f, p;
		scanf("%d%d%d", &d, &f, &p), --p, d *= 4;
		ob[p].pb(mp(d, f));
	}
	dfs(0);
	vector<pair<int, int> > seq;
	for (auto u : dpl[0]) seq.pb(mp(u.x - 2, u.y));
	for (auto u : dpr[0]) seq.pb(mp(u.x + 2, u.y));
	sort(ALL(seq));
	int ans = 0;
	int tmp = 0;
	for (auto u : seq)
	{
		tmp += u.y;
		chkmax(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}