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

const int maxN = 1000100;

int N;
vector<int> adj[maxN + 5], radj[maxN + 5];

inline void add_con(int x, int y) { adj[x].pb(y), adj[y ^ 1].pb(x ^ 1); }

bool picked[maxN + 5];

int dfs_seq[maxN + 5];
int dfs_tot = 0;

int cnts;
int belong[maxN + 5];

bool vis[maxN + 5];

void dfs0(int x)
{
	vis[x] = 1;
	for (auto y : adj[x]) if (!vis[y]) dfs0(y);
	dfs_seq[dfs_tot++] = x;
}

void dfs1(int x)
{
	belong[x] = cnts;
	for (auto y : radj[x]) if (!~belong[y]) dfs1(y);
}

inline bool work()
{
	REP(i, 0, N) radj[i].clear();
	REP(i, 0, N) for (auto j : adj[i]) radj[j].pb(i);
	memset(vis, 0, sizeof(vis[0]) * N);
	dfs_tot = 0;
	REP(i, 0, N) if (!vis[i]) dfs0(i);
	memset(belong, -1, sizeof(belong[0]) * N);
	cnts = 0;
	for (int i = dfs_tot - 1; i >= 0; --i)
	{
		if (!~belong[dfs_seq[i]]) dfs1(dfs_seq[i]), ++cnts;
	}
	REP(i, 0, N)
	{
		if (belong[i] == belong[i ^ 1]) return 0;
		picked[i] = belong[i] > belong[i ^ 1];
	}
	return 1;
}

const int maxn = 100100;

int n, m;
vector<int> s[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	N = m << 1;
	REP(i, 0, n)
	{
		int l;
		scanf("%d", &l);
		REP(j, 0, l)
		{
			int x;
			scanf("%d", &x);
			--x;
			s[i].pb(x);
		}
	}
	REP(i, 0, n - 1)
	{
		bool flag = 0;
		REP(j, 0, min(SZ(s[i]), SZ(s[i + 1])))
		{
			if (s[i][j] != s[i + 1][j])
			{
				if (s[i][j] > s[i + 1][j])
				{
					add_con(s[i][j] << 1, s[i][j] << 1 | 1);
					add_con(s[i + 1][j] << 1 | 1, s[i + 1][j] << 1);
				}
				else
				{
					add_con(s[i + 1][j] << 1 | 1, s[i][j] << 1 | 1);
				}
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			if (SZ(s[i]) > SZ(s[i + 1]))
			{
				puts("No");
				return 0;
			}
		}
	}
	if (!work()) puts("No");
	else
	{
		puts("Yes");
		vector<int> ans;
		REP(i, 0, m) if (picked[i << 1 | 1]) ans.pb(i);
		printf("%d\n", SZ(ans));
		for (auto u : ans) printf("%d ", u + 1);
		printf("\n");
	}
	return 0;
}