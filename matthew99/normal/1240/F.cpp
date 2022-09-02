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

const int maxn = 110, maxm = 1110, maxk = 1010;

int n, m, K;

int en = 0;
int col[maxm + 5];

vector<pair<int, int> > adj[maxn + 5];
vector<pair<int, int> > cur[maxn + 5];

inline void add_edge(int x, int y)
{
	adj[x].pb(mp(y, en));
	adj[y].pb(mp(x, en));
	++en;
}

int cnt, col0, col1;
bool vis[maxm + 5];

void dfs(int x)
{
	while (!cur[x].empty())
	{
		auto u = cur[x].back();
		cur[x].pop_back();
		if (!vis[u.y])
		{
			vis[u.y] = 1;
			dfs(u.x);
			col[u.y] = cnt ? col0 : col1;
			cnt ^= 1;
		}
	}
}

void work(int _col0, int _col1)
{
	memset(vis, 0, sizeof vis);
	col0 = _col0;
	col1 = _col1;
	REP(i, 0, n)
	{
		cur[i].clear();
		for (auto j : adj[i])
			if (col[j.y] == col0 || col[j.y] == col1)
				cur[i].pb(j);
	}
	int tmp = en;
	REP(i, 0, n) if (SZ(cur[i]) & 1)
	{
		cur[i].pb(mp(n, tmp));
		cur[n].pb(mp(i, tmp));
		++tmp;
	}
	cnt = 0;
	for (int i = n; i >= 0; --i) if (!cur[i].empty()) dfs(i);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &K);
	REP(i, 0, n) scanf("%*d");
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		add_edge(u, v);
	}
	memset(col, 0, sizeof col);
	REP(i, 0, n)
	{
		while (1)
		{
			static int num[maxk + 5];
			memset(num, 0, sizeof num);
			for (auto j : adj[i]) ++num[col[j.y]];
			int Min = 0, Max = 0;
			REP(j, 1, K)
			{
				if (num[j] > num[Max]) Max = j;
				if (num[j] < num[Min]) Min = j;
			}
			if (num[Max] - num[Min] > 2) work(Min, Max);
			else break;
		}
	}
	REP(i, 0, m) printf("%d\n", col[i] + 1);
	return 0;
}