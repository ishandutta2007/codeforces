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

const int maxn = 2010;

inline int query(int x, int y, int z)
{
	printf("%d %d %d\n", x + 1, y + 1, z + 1);
	fflush(stdout);
	static char s[5];
	scanf("%s", s);
	if (s[0] == 'X') return 0;
	if (s[0] == 'Y') return 1;
	return 2;
}

int n, n_leaf;
int p[maxn + 5];

vector<int> adj[maxn + 5];

int sz[maxn + 5], Max[maxn + 5];

bool vis[maxn + 5];

vector<int> dfs_seq;

void dfs_pre(int x, int f = -1)
{
	dfs_seq.pb(x);
	sz[x] = 1;
	Max[x] = 0;
	for (auto y : adj[x]) if (y != f && !vis[y]) dfs_pre(y, x), sz[x] += sz[y], chkmax(Max[x], sz[y]);
}

int now_leaf;

int Min = oo;

void formal_dfs(int x, int f = -1)
{
	chkmin(Min, x);
	for (auto y : adj[x]) if (y != f) formal_dfs(y, x);
}

inline void work(int rt)
{
	dfs_seq.clear();
	dfs_pre(rt);
	int x = -1;
	for (auto u : dfs_seq)
	{
		chkmax(Max[u], sz[rt] - sz[u]);
		if (!~x || Max[u] < Max[x]) x = u;
	}
	vector<int> chd, leaf;
	for (auto u : adj[x]) if (u != p[x])
	{
		Min = oo;
		formal_dfs(u, x);
		chd.pb(u);
		leaf.pb(Min);
	}
	if (SZ(chd) == 0)
	{
		p[n] = p[x];
		p[x] = p[now_leaf] = n++;
	}
	else
	{
		int tmp = query(leaf[0], now_leaf, leaf[1]);
		vis[x] = 1;
		if (tmp == 2)
		{
			if (x != rt) work(rt);
			else
			{
				p[n] = p[x];
				p[x] = p[now_leaf] = n++;
			}
			return;
		}
		else if (vis[chd[tmp]])
		{
			p[n] = p[chd[tmp]];
			p[chd[tmp]] = p[now_leaf] = n++;
		}
		else work(chd[tmp]);
	}
}

int rt;

int main()
{
	scanf("%d", &n_leaf);
	memset(p, -1, sizeof p);
	n = n_leaf;
	rt = 0;
	REP(i, 1, n_leaf)
	{
		now_leaf = i;
		memset(vis, 0, sizeof vis);
		REP(j, 0, n) adj[j].clear();
		REP(j, 0, n) if (~p[j]) adj[p[j]].pb(j), adj[j].pb(p[j]);
		while (~p[rt]) rt = p[rt];
		work(rt);
	}
	printf("-1\n");
	REP(i, 0, n) printf("%d ", p[i] + (p[i] != -1));
	fflush(stdout);
	return 0;
}