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

const int maxn = 100100;

int n;
int a[maxn + 5];

vector<int> id[maxn + 5];

int fa[maxn + 5];

int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

vector<int> adj[maxn + 5];

int col[maxn + 5];

bool dfs(int x, int c)
{
	if (~col[x])
	{
		if (col[x] != c) return 0;
		return 1;
	}
	else col[x] = c;
	for (auto y : adj[x]) if (!dfs(y, c ^ 1)) return 0;
	return 1;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, m)
	{
		int x;
		scanf("%d", &x);
		REP(j, 0, x)
		{
			int y;
			scanf("%d", &y), --y;
			id[y].pb(i);
		}
	}
	REP(i, 0, m) fa[i] = i;
	REP(i, 0, n) if (a[i]) fa[get(id[i][0])] = get(id[i][1]);
	REP(i, 0, n) if (!a[i])
	{
		int u = get(id[i][0]);
		int v = get(id[i][1]);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(col, -1, sizeof col);
	REP(i, 0, m) if (fa[i] == i && !~col[i] && !dfs(i, 0)) { puts("NO"); return 0; }
	puts("YES");
	return 0;
}