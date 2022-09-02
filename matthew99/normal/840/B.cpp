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

const int maxn = 300100;

int n, m;
vector<pair<int, int> > adj[maxn + 5];

bool vis[maxn + 5];

int need[maxn + 5];

vector<int> ans;

void dfs(int x)
{
	vis[x] = 1;
	for (auto y : adj[x])
	{
		if (vis[y.x]) continue;
		dfs(y.x);
		if (need[y.x]) ans.pb(y.y), need[x] ^= 1;
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	int find = -1;
	REP(i, 0, n) 
	{
		scanf("%d", need + i);
		if (need[i] == -1) find = i, need[i] = 0;
	}
	bool tmp = 0;
	REP(i, 0, n) if (need[i]) tmp ^= 1;
	if (tmp)
	{
		if (!~find)
		{
			puts("-1");
			return 0;
		}
		need[find] = 1;
	}
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(mp(v, i));
		adj[v].pb(mp(u, i));
	}
	memset(vis, 0, sizeof vis);
	dfs(0);
	printf("%d\n", SZ(ans));
	for (auto u : ans) printf("%d\n", u + 1);
	return 0;
	}