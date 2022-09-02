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

const int maxn = 100100;

int n, m, h;
int t[maxn + 5];

vector<int> adj[maxn + 5];

int tot = 0;

bool in[maxn + 5];

int N;
int belong[maxn + 5];

int dfn[maxn + 5], low[maxn + 5];

int stk[maxn + 5];

void dfs(int x)
{
	int tmp = tot;
	stk[dfn[x] = low[x] = tot++] = x;
	in[x] = 1;
	for (auto y : adj[x])
	{
		if (!~dfn[y]) dfs(y), chkmin(low[x], low[y]);
		else if (in[y]) chkmin(low[x], dfn[y]);
	}
	if (dfn[x] == low[x])
	{
		while (tot != tmp)
		{
			--tot;
			in[stk[tot]] = 0;
			belong[stk[tot]] = N;
		}
		++N;
	}
}

int cnt[maxn + 5];
bool ok[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &h);
	REP(i, 0, n) scanf("%d", t + i);
	REP(i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		if ((t[x] + 1) % h == t[y])
		{
			adj[x].pb(y);
		}
		if ((t[y] + 1) % h == t[x])
		{
			adj[y].pb(x);
		}
	}
	memset(dfn, -1, sizeof dfn);
	tot = 0;
	N = 0;
	REP(i, 0, n) if (!~dfn[i]) dfs(i);

	memset(ok, 1, sizeof ok);
	memset(cnt, 0, sizeof cnt);
	REP(i, 0, n) 
	{
		++cnt[belong[i]];
		for (auto j : adj[i]) if (belong[j] != belong[i]) ok[belong[i]] = 0;
	}
	int Min = -1;
	REP(i, 0, N) if (ok[i])
	{
		if (!~Min || cnt[i] < cnt[Min]) Min = i;
	}
	printf("%d\n", cnt[Min]);
	REP(i, 0, n) if (belong[i] == Min) printf("%d ", i + 1);
	printf("\n");
	return 0;
}