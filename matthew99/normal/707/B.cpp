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

const int maxn = 100000, maxm = 100000;

vector<pair<int, int> > adj[maxn + 5];

int dis[maxn + 5];
bool in[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, K;
	scanf("%d%d%d", &n, &m, &K);
	REP(i, 0, m)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w), --u, --v;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	memset(dis, oo, sizeof dis);
	REP(i, 0, K)
	{
		int x;
		scanf("%d", &x), --x;
		in[x] = 1;
		for (auto y : adj[x]) chkmin(dis[y.x], y.y);
	}
	int ans = oo;
	REP(i, 0, n) if (!in[i]) chkmin(ans, dis[i]);
	if (ans >= oo) puts("-1");
	else printf("%d\n", ans);
	return 0;
}