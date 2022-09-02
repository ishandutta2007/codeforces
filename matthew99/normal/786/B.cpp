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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 100100, max0 = 17;

const int maxN = 4000000;

int n, qn, S;

int N;
int down[max0][maxn + 5], up[max0][maxn + 5];

int Log[maxn + 5];

vector<pair<int, int> > adj[maxN + 5];

LL dis[maxN + 5];
bool vis[maxN + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &qn, &S), --S;
	REP(i, 1, n + 1)
	{
		Log[i] = -1;
		int u = i;
		while (u) u >>= 1, ++Log[i];
	}
	N = n;
	REP(i, 0, max0) REP(j, 0, n) down[i][j] = N++, up[i][j] = N++;
	REP(i, 0, n) adj[down[0][i]].pb(mp(i, 0)), adj[i].pb(mp(up[0][i], 0));
	REP(i, 1, max0)
	{
		REP(j, 0, n) if (j + (1 << (i - 1)) < n)
		{
			int p = j + (1 << (i - 1));
			adj[down[i][j]].pb(mp(down[i - 1][j], 0));
			adj[down[i][j]].pb(mp(down[i - 1][p], 0));
			adj[up[i - 1][j]].pb(mp(up[i][j], 0));
			adj[up[i - 1][p]].pb(mp(up[i][j], 0));
		}
	}
	REP(i, 0, qn)
	{
		int ty, u, v, l, r, w;
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%d%d%d", &u, &v, &w), --u, --v;
			adj[u].pb(mp(v, w));
		}
		else
		{
			scanf("%d%d%d%d", &u, &l, &r, &w), --u, --l;
			int tmp = Log[r - l];
			if (ty == 2)
			{
				adj[u].pb(mp(down[tmp][l], w));
				adj[u].pb(mp(down[tmp][r - (1 << tmp)], w));
			}
			else if (ty == 3)
			{
				adj[up[tmp][l]].pb(mp(u, w));
				adj[up[tmp][r - (1 << tmp)]].pb(mp(u, w));
			}
		}
	}
	priority_queue<pair<LL, int>, vector<pair<LL, int> >, greater<pair<LL, int> > > q;
	memset(dis, OO, sizeof dis);
	q.push(mp(0LL, S));
	dis[S] = 0;
	while (!q.empty())
	{
		int x = q.top().y; q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (auto y : adj[x]) if (chkmin(dis[y.x], dis[x] + y.y)) q.push(mp(dis[y.x], y.x));
	}
	REP(i, 0, n) 
		if (dis[i] >= OO) printf("-1 ");
		else printf("%" LLFORMAT "d ", dis[i]);
	printf("\n");
	return 0;
}