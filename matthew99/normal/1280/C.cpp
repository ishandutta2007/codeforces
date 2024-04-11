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

const int maxn = 200100;

int n;
vector<pair<int, int> > adj[maxn + 5];

LL ans0, ans1;

int w[maxn + 5];
LL dis[maxn + 5];

int sz[maxn + 5];

void dfs(int x, int f = -1)
{
	sz[x] = 1;
	int cnt = 0;
	for (auto y : adj[x])
		if (y.x != f)
		{
			w[y.x] = y.y;
			dis[y.x] = dis[x] + y.y;
			dfs(y.x, x);
			if (sz[y.x] & 1) ++cnt;
			sz[x] += sz[y.x];
		}
	if (~f) ans1 += (LL)min(n - sz[x], sz[x]) * w[x];
	//0  1  2  3  4
	//1 -1 -1 -3  -3
	ans0 += LL(1 - ((cnt + 1) / 2) * 2) * dis[x];
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n), n <<= 1;
		REP(i, 0, n) adj[i].clear();
		REP(i, 0, n - 1)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z), --x, --y;
			adj[x].pb(mp(y, z));
			adj[y].pb(mp(x, z));
		}
		ans0 = ans1 = 0;
		dis[0] = 0;
		dfs(0);
		printf("%lld %lld\n", ans0, ans1);
	}
	return 0;
}