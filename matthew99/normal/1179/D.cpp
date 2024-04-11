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
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 500100;

int n;
vector<int> adj[maxn + 5];
LL f[maxn + 5];

LL ans;

int sz[maxn + 5];

void dfs(int x, int fa = -1)
{
	sz[x] = 1;
	LL sum = 0;
	for (auto y : adj[x]) if (y != fa)
	{
		dfs(y, x);
		sz[x] += sz[y];
		sum += (LL)sz[y] * sz[y];
	}
	f[x] = (LL)sz[x] * sz[x];

	vector<int> all;
	for (auto y : adj[x]) if (y != fa)
	{
		chkmin(f[x], f[y] + LL(sz[x] - sz[y]) * LL(sz[x] - sz[y]));
		all.pb(y);
	}
	sort(ALL(all), [&](int u, int v) { return sz[u] < sz[v]; });
	static pair<int, LL> stk[maxn + 5];
	int top = 0;
	stk[top++] = mp(-2 * n, (LL)n * n); 
	for (auto u : all)
	{
		while (top >= 2 && (LL)stk[top - 1].x * sz[u] + stk[top - 1].y > (LL)stk[top - 2].x * sz[u] + stk[top - 2].y) --top; 
		chkmin(ans, (LL)stk[top - 1].x * sz[u] + stk[top - 1].y + (LL)sz[u] * sz[u] + f[u]);
		pair<int, LL> tmp = mp(-2 * (n - sz[u]), (LL)(n - sz[u]) * (n - sz[u]) + f[u]);
		while (top >= 2 && (LL)(tmp.x - stk[top - 2].x) * (stk[top - 1].y - stk[top - 2].y) >= (LL)(tmp.y - stk[top - 2].y) * (stk[top - 1].x - stk[top - 2].x)) --top;
		stk[top++] = tmp;
	}
	//c + (k - x) * (k - x)
	//c + k * k - 2 * k * x + x * x
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
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	ans = (LL)n * n;
	dfs(0);
//	debug("%lld\n", ans);
	ans = (LL)n * n * 2 - ans;
	ans = (ans - n) >> 1;
	cout << ans << endl;
	return 0;
}