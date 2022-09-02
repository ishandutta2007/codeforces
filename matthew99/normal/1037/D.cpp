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

const int maxn = 200100;

int n;
vector<int> adj[maxn + 5];
vector<int> chd[maxn + 5];
int a[maxn + 5];
int pos[maxn + 5];

void dfs(int x, int f = -1)
{
	chd[x].clear();
	for (auto y : adj[x])
		if (y != f)
		{
			chd[x].pb(y);
			dfs(y, x);
		}
	sort(ALL(chd[x]), [&](int u, int v) { return pos[u] < pos[v]; });
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	REP(i, 0, n) scanf("%d", a + i), --a[i], pos[a[i]] = i;
	dfs(0);
	vector<int> q;
	q.pb(0);
	REP(i, 0, n) for (auto y : chd[q[i]]) q.pb(y);
	REP(i, 0, n) if (q[i] != a[i]) puts("No"), exit(0);
	puts("Yes");
	return 0;
}