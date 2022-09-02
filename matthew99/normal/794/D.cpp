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
vector<int> adj[maxn + 5];

bool vis[maxn + 5];
int dis[maxn + 5];

void BFS(int S)
{
	queue<int> q;
	memset(vis, 0, sizeof vis);
	q.push(S);
	vis[S] = 1;
	dis[S] = 0;
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		for (auto y : adj[x]) if (!vis[y]) vis[y] = 1, dis[y] = dis[x] + 1, q.push(y);
	}
}

int cnt[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	if (m == (LL)n * (n - 1) >> 1)
	{
		puts("YES");
		REP(i, 0, n) printf("1 ");
		printf("\n");
		return 0;
	}
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v), adj[v].pb(u);
	}
	BFS(0);
	int Max = *max_element(dis, dis + n);
	int from = -1;
	if (Max == 1)
	{
		REP(i, 0, n) if (SZ(adj[i]) != SZ(adj[0])) { from = i; break; }
		assert(~from);
	}
	else
	{
		from = max_element(dis, dis + n) - dis;
	}
	BFS(from);
	REP(i, 0, n) if (dis[i] == 1 && SZ(adj[i]) == SZ(adj[from])) dis[i] = 0;
	REP(i, 0, n) ++cnt[dis[i]];
	LL should = 0;
	REP(i, 0, n) should += (LL)cnt[i] * (cnt[i] - 1) >> 1;
	REP(i, 1, n) should += (LL)cnt[i] * cnt[i - 1];
	if (should != m) { puts("NO"); return 0; }
	REP(i, 0, n)
	{
		for (auto j : adj[i])
		{
			if (abs(dis[j] - dis[i]) > 1)
			{ 
				puts("NO"); 
				return 0; 
			}
		}
	}
	puts("YES");
	REP(i, 0, n) printf("%d ", dis[i] + 1);
	printf("\n");
	return 0;
}