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

int T;

int n;
vector<int> adj[maxn + 5];

bool isbud[maxn + 5];

int ans;

void dfs(int x, int f = -1)
{
	int cnt = 0;
	for (auto y : adj[x])
		if (y != f)
		{
			dfs(y, x);
			if (!isbud[y]) isbud[x] = 1, ++cnt;
		}
	ans += max(0, cnt - 1);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		REP(i, 0, n) adj[i].clear(), isbud[i] = 0;
		REP(i, 0, n - 1)
		{
			int u, v;
			scanf("%d%d", &u, &v), --u, --v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		ans = 1;
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}