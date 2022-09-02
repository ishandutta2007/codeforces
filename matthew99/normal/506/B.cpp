#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

const int maxn = 1e5, max0 = 1e5;

int n, m;

int a, b;

int st[maxn + 5];

struct edge
{
	int id, nxt;

	edge() { }
	edge(const int &_id, const int &_nxt): id(_id), nxt(_nxt) { }
};

edge e[max0 + 5];
int en = 0;

int deg[maxn + 5] = {0};

void add_edge(const int &x, const int &y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int dfn[maxn + 5], low[maxn + 5];
int stk[maxn + 5], top = 0;
bool vis[maxn + 5];
int fa[maxn + 5];
int dn = 0;
bool leave[maxn + 5];

int N = 0;
int belong[maxn + 5];
bool be[maxn + 5];
int ans = 0;

void dfs(const int &x)
{
	int u = x;
	bool flag = 0;
	static int cur[max0 + 5];
	fa[x] = -1;
	while (u != -1)
	{
		if (!flag)
		{
			vis[u] = 1;
			dfn[u] = dn++;
			low[u] = dfn[u];
			stk[top++] = u;
			cur[u] = st[u];
		}
		flag = 1;
		for (int &i = cur[u]; i != -1; i = e[i].nxt)
		{
			const int &v = e[i].id;
			if (!vis[v])
			{
				fa[v] = u;
				u = v;
				flag = 0;
				i = e[i].nxt;
				break;
			}
			else if (!leave[v]) low[u] = min(low[u], dfn[v]);
		}
		if (flag)
		{
			leave[u] = 1;
			if (low[u] == dfn[u])
			{
				int cnt = 0;
				do
				{
					--top;
					belong[stk[top]] = N;
					++cnt;
				}while (stk[top] != u);
				if (cnt > 1) be[N] = 1;
				++N;
			}
			int v = u;
			u = fa[u];
			if (u != -1) low[u] = min(low[u], low[v]);
		}
	}
}

vector<int> E[maxn + 5];

bool cal[maxn + 5];

void work(const int &x, const int &col)
{
	if (vis[x]) return;
	if (!cal[col] && be[belong[x]])
	{
		++ans;
		cal[col] = 1;
	}
	vis[x] = 1;
	REP(i, 0, SZ(E[x])) work(E[x][i], col);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st);
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
	{
		static int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		if (u == v) continue;
		add_edge(u, v);
		E[u].pb(v);
		E[v].pb(u);
	}
	ans = n;
	memset(dfn, -1, sizeof dfn);
	memset(belong, -1, sizeof belong);
	REP(i, 0, n)
		if (dfn[i] == -1) dfs(i);
	memset(vis, 0, sizeof vis);
	int col = 0;
	REP(i, 0, n)
		if (!vis[i]) work(i, col++), --ans;
	printf("%d\n", ans);
	return 0;
}