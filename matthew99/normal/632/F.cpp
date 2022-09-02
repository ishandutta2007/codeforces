#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int maxn = 2500;

int n;
int f[maxn + 5][maxn + 5];

int now[maxn + 5];

bool vis[maxn + 5];

vector<pair<int, int> > adj[maxn + 5];
int Max[maxn + 5];

void dfs(int x, int f = -1)
{
	for (auto y : adj[x])
	{
		if (y.x == f) continue;
		Max[y.x] = max(Max[x], y.y);
		dfs(y.x, x);
	}
}

bool check()
{
	memset(vis, 0, sizeof vis);
	REP(i, 0, n) REP(j, 0, n) if (f[i][j] != f[j][i]) return 0;
	REP(i, 0, n) if (f[i][i]) return 0;
	memset(now, oo, sizeof now);
	vis[0] = 1;
	REP(i, 0, n) chkmin(now[i], f[0][i]);
	REP(i, 0, n - 1)
	{
		int Minp = -1;
		REP(j, 0, n) if (!vis[j] && (!~Minp || now[Minp] > now[j])) Minp = j;
		assert(~Minp);
		REP(j, 0, n) 
			if (vis[j] && f[Minp][j] == now[Minp]) { adj[Minp].pb(mp(j, now[Minp])), adj[j].pb(mp(Minp, now[Minp])); break; }
		vis[Minp] = 1;
		REP(j, 0, n) if (!vis[j]) chkmin(now[j], f[Minp][j]);
	}
	REP(i, 0, n)
	{
		Max[i] = 0;
		dfs(i);
		REP(j, 0, n) if (Max[j] != f[i][j]) return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) REP(j, 0, n) scanf("%d", f[i] + j);
	if (!check()) printf("NOT MAGIC\n");
	else printf("MAGIC\n");
	return 0;
}