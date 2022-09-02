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

const int maxn = 1000, maxm = 10000;

int n, m, L, s, t;

struct edge
{
	int x, y, w;
};

edge ed[maxm + 5];

vector<pair<int, int> > adj[maxn + 5];

inline int check()
{
	static int dis[maxn + 5];
	static bool vis[maxn + 5];
	memset(vis, 0, sizeof vis);
	memset(dis, oo, sizeof dis);
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	dis[s] = 0;
	q.push(mp(0, s));
	while (!q.empty())
	{
		int x = q.top().y; q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (auto y : adj[x]) if (chkmin(dis[y.x], dis[x] + y.y)) q.push(mp(dis[y.x], y.x));
	}
	return dis[t];
}

inline int test(int x, int val = L)
{
	REP(i, 0, n) adj[i].clear();
	REP(i, 0, m)
	{
		int tmp = -1;
		if (ed[i].w) tmp = ed[i].w;
		else if (i < x) tmp = 1;
		else if (i == x) tmp = val;
		if (~tmp) adj[ed[i].x].pb(mp(ed[i].y, tmp)), adj[ed[i].y].pb(mp(ed[i].x, tmp));
	}
	int ret = check();
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
	int cnt = 0;
	REP(i, 0, m) scanf("%d%d%d", &ed[i].x, &ed[i].y, &ed[i].w), cnt += !ed[i].w;
	if (!cnt)
	{
		if (test(0) != L) puts("NO");
		else
		{
			puts("YES");
			REP(i, 0, m) printf("%d %d %d\n", ed[i].x, ed[i].y, ed[i].w);
		}
		return 0;
	}
	if (test(0) < L) puts("NO");
	else
	{
		int lo = 0, hi = m;
		while (lo < hi)
		{
			int mid = (lo + hi + 1) >> 1;
			if (test(mid) > L) lo = mid;
			else hi = mid - 1;
		}
		if (lo == m) 
		{
			puts("NO");
			return 0;
		}
		int p = lo;
		lo = 1, hi = L;
		while (lo < hi)
		{
			int mid = (lo + hi + 1) >> 1;
			if (test(p, mid) <= L) lo = mid;
			else hi = mid - 1;
		}
		puts("YES");
		REP(i, 0, m)
		{
			printf("%d %d ", ed[i].x, ed[i].y);
			if (ed[i].w) printf("%d", ed[i].w);
			else if (i < p) printf("%d", 1);
			else if (i == p) printf("%d", lo);
			else printf("%d", L);
			printf("\n");
		}
	}
	return 0;
}