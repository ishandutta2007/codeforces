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

const int maxn = 500100;

int n;
vector<int> adj[maxn + 5];

LL ans = 0;

int fa[maxn + 5];

int sz[maxn + 5];

int lk[maxn + 5];

int dfs_seq[maxn + 5];
int dfs_tot;

void dfs0(int x, int f = -1)
{
	dfs_seq[dfs_tot++] = x;
	fa[x] = f;
	sz[x] = 1;
	for (auto y : adj[x]) if (y != f)
	{
		dfs0(y, x);
		if (!~lk[y])
		{
			if (!~lk[x])
			{
				lk[lk[x] = y] = x;
			}
		}
		sz[x] += sz[y];
	}
}

bool visv[maxn + 5], visu[maxn + 5];

int upu[maxn + 5], downu[maxn + 5], upv[maxn + 5], downv[maxn + 5];

int up[maxn + 5], down[maxn + 5];

bool hasu[maxn + 5], hasv[maxn + 5];

void dfs1(int x, bool *vis)
{
	if (vis[x]) return;
	vis[x] = 1;
	for (auto y : adj[x])
	{
		assert(~lk[y]);
		dfs1(lk[y], vis);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	if (n & 1)
	{
		printf("0\n");
		return 0;
	}
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v); 
		adj[v].pb(u);
	}
	memset(lk, -1, sizeof lk);
	dfs0(0);
	vector<int> no_match;
	REP(i, 0, n) if (!~lk[i]) no_match.pb(i);
	if (SZ(no_match) == 0)
	{
		for (int i = n - 1; i >= 0; --i)
		{
			int x = dfs_seq[i];
			if (lk[x] == fa[x])
			{
				down[x] = 1;
				for (auto y : adj[x]) if (y != fa[x])
				{
					down[x] += down[lk[y]];
				}
			}
		}
		REP(i, 0, n)
		{
			int x = dfs_seq[i];
			if (lk[x] != fa[x])
			{
				int sum = 1;
				if (~fa[x])
				{
					if (lk[fa[x]] == fa[fa[x]])
					{
						sum += up[fa[x]];
					}
					else sum += down[lk[fa[x]]];
				}
				for (auto y : adj[x]) if (y != fa[x] && y != lk[x])
				{
					sum += down[lk[y]];
				}
				up[lk[x]] = sum;
			}
		}
		REP(i, 0, n) if (~fa[i])
		{
			if (lk[i] == fa[i])
			{
				ans += (LL)down[i] * up[i];
			}
			else ans += (LL)sz[i] * (n - sz[i]);
		}
		cout << ans << endl;
	}
	else if (SZ(no_match) == 2)
	{
		int u = no_match[0], v = no_match[1];
		int tmpu = u;
		while (~tmpu)
		{
			hasu[tmpu] = 1;
			tmpu = fa[tmpu];
		}
		int tmpv = v;
		while (~tmpv)
		{
			hasv[tmpv] = 1;
			tmpv = fa[tmpv];
		}
		dfs1(u, visu);
		dfs1(v, visv);
		for (int i = n - 1; i >= 0; --i)
		{
			int x = dfs_seq[i];
			down[x] = visu[x] ^ visv[x];
			downu[x] = visu[x];
			downv[x] = visv[x];
			for (auto y : adj[x]) if (y != fa[x])
			{
				down[x] += down[y];
				downu[x] += downu[y];
				downv[x] += downv[y];
			}
		}
		REP(i, 0, n)
		{
			up[i] = down[0] - down[i];
			upu[i] = downu[0] - downu[i];
			upv[i] = downv[0] - downv[i];
		}
		REP(i, 1, n) 
		{
			if (lk[i] == fa[i])
			{
				if (visu[fa[i]] && visv[fa[i]])
				{
					ans += (LL)upu[i] * down[i];
				}
				else if (visu[fa[i]])
				{
					ans += (LL)upu[i] * downv[i];
				}
				else if (visv[fa[i]])
				{
					ans += (LL)upv[i] * downu[i];
				}
				if (visu[i] && visv[i])
				{
					ans += (LL)downu[i] * up[i];
				}
				else if (visu[i])
				{
					ans += (LL)downu[i] * upv[i];
				}
				else if (visv[i])
				{
					ans += (LL)downv[i] * upu[i];
				}
			}
			else
			{
				if (hasu[i] && !hasv[i])
				{
					ans += (LL)downu[i] * upv[i];
				}
				else if (hasv[i] && !hasu[i])
				{
					ans += (LL)downv[i] * upu[i];
				}
			}
		}
		cout << ans << endl;
	}
	else
	{
		printf("0\n");
	}
	return 0;
}