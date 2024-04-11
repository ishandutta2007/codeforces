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

const int maxn = 300100, maxm = 300100;

int n, qn;
pair<int, int> a[maxn + 5];

map<pair<int, int>, int> id;

int bel[maxn + 5];
int cnt[maxn + 5];

set<int> adj[maxn + 5];

bool isq[maxm + 5];
int ans[maxm + 5];

vector<int> allq[maxn + 5];
int fir[maxn + 5];

int sz[maxn + 5], Max[maxn + 5];

vector<int> seq;

void dfs(int x, int f = -1)
{
	seq.pb(x);
	Max[x] = 0;
	sz[x] = 1;
	for (auto y : adj[x]) if (y != f)
	{
		dfs(y, x);
		sz[x] += sz[y];
		chkmax(Max[x], sz[y]);
	}
}

vector<int> walk[maxn + 5];
pair<int, int> dis[maxn + 5];

#define forall(i, a) for (int i##bel = bel[(a)], i = (a); bel[i] == i##bel; ++i)

void work(int rt)
{
	seq.clear();
	dfs(rt);
	int x = -1;
	for (auto u : seq)
	{
		chkmax(Max[u], sz[rt] - sz[u]);
		if (!~x || Max[u] < Max[x]) x = u;
	}

	{
		queue<int> q;
		for (auto u : seq)
		{
			forall(i, u) 
				if (u == x)
				{
					dis[i] = mp(0, i - bel[i]);
					q.push(i);
				}
				else dis[i] = mp(oo, -1);
		}

		while (!q.empty())
		{
			int u = q.front(); q.pop();
			for (auto v : walk[u]) if (chkmin(dis[v], mp(dis[u].x + 1, dis[u].y)))
				q.push(v);
		}
	}

	vector<pair<int, int> > ev;
	vector<pair<int, int> > q;
	for (auto u : seq) forall(i, u)
	{
		if (fir[i] < oo) ev.pb(mp(fir[i], i));
		for (auto qid : allq[i]) q.pb(mp(qid, i));
	}
	sort(ALL(ev));
	sort(ALL(q));

	static int fenp[maxn + 5], fens[maxn + 5];
	REP(i, 0, cnt[x] + 1) fenp[i] = fens[i] = oo;

	int ptr = 0;
	for (auto u : q)
	{
		while (ptr < SZ(ev) && ev[ptr].x < u.x)
		{
			for (int i = dis[ev[ptr].y].y + 1; i <= cnt[x]; i += i & -i)
				chkmin(fenp[i], dis[ev[ptr].y].x - dis[ev[ptr].y].y);
			for (int i = dis[ev[ptr].y].y + 1; i > 0; i -= i & -i)
				chkmin(fens[i], dis[ev[ptr].y].x + dis[ev[ptr].y].y);
			++ptr;
		}
		for (int i = dis[u.y].y + 1; i > 0; i -= i & -i)
			if (fenp[i] < oo) chkmin(ans[u.x], fenp[i] + dis[u.y].x + dis[u.y].y);
		for (int i = dis[u.y].y + 1; i <= cnt[x]; i += i & -i)
			if (fens[i] < oo) chkmin(ans[u.x], fens[i] + dis[u.y].x - dis[u.y].y);
	}

	for (auto y : adj[x]) adj[y].erase(x);
	for (auto y : adj[x]) work(y);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	sort(a, a + n);
	REP(i, 0, n) id[a[i]] = i;
	REP(i, 1, n)
	{
		if (a[i].x == a[i - 1].x && a[i].y == a[i - 1].y + 1) 
		{
			walk[i - 1].pb(i);
			walk[i].pb(i - 1);
			bel[i] = bel[i - 1];
		}
		else bel[i] = i;
		if (id.count(mp(a[i].x - 1, a[i].y)))
		{
			int j = id[mp(a[i].x - 1, a[i].y)];
			walk[i].pb(j);
			walk[j].pb(i);
			adj[bel[i]].insert(bel[j]);
			adj[bel[j]].insert(bel[i]);
		}
	}
	bel[n] = -1;
	REP(i, 0, n) ++cnt[bel[i]];

	scanf("%d", &qn);
	memset(fir, oo, sizeof fir);
	REP(i, 0, qn)
	{
		int ty, x;
		{
			int cx, cy;
			scanf("%d%d%d", &ty, &cx, &cy);
			x = id[mp(cx, cy)];
		}
		if (ty == 1) isq[i] = 0, chkmin(fir[x], i);
		else isq[i] = 1, allq[x].pb(i);
	}
	memset(ans, oo, sizeof ans);
	work(0);
	REP(i, 0, qn) if (isq[i])
	{
		if (ans[i] >= oo) printf("-1\n");
		else printf("%d\n", ans[i]);
	}
	return 0;
}