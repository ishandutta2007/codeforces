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

const int maxn = 200100;

int n, m;
vector<int> adj[maxn + 5];

int res[maxn + 5];

int vis[maxn + 5];

struct data
{
	int x, y, z;

	data() { }
	data(int _x, int _y, int _z): x(_x), y(_y), z(_z) { }
};

vector<data> ans;

void dfs(int x)
{
	vis[x] = 1;
	vector<int> all;
	for (auto y : adj[x]) 
	{
		if (!vis[y]) 
		{
			dfs(y);
			if (~res[y])
			{
				ans.pb(data(x, y, res[y]));
			}
			else all.pb(y);
		}
		else if (vis[y] == 2)
		{
			all.pb(y);
		}
	}
	for (int i = 0; i + 1 < SZ(all); i += 2)
	{
		ans.pb(data(all[i], x, all[i + 1]));
	}
	if (SZ(all) & 1) res[x] = all.back();
	vis[x] = 2;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v), adj[v].pb(u);
	}
	memset(res, -1, sizeof res);
	memset(vis, 0, sizeof vis);
	REP(i, 0, n) if (!vis[i]) dfs(i);
	printf("%d\n", SZ(ans));
	for (auto u : ans) printf("%d %d %d\n", u.x + 1, u.y + 1, u.z + 1);
	return 0;
}