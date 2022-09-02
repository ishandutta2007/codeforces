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

const int maxn = 100100;

int n, m;
vector<int> adj[maxn + 5];

bool ok = 0;

int ans[maxn + 5];

bool vis[maxn + 5];

int fa[maxn + 5];

vector<int> seq;

int dep[maxn + 5];

void dfs(int x, int f = -1)
{
	if (ok) return;
	seq.pb(x);
	fa[x] = f;
	vis[x] = 1;
	for (auto y : adj[x]) if (y != f)
	{
		if (vis[y])
		{
			int u = x;
			while (u != y)
			{
				ans[u] = 1;
				u = fa[u];
			}
			ans[y] = 1;
			ok = 1;
			return;
		}
		else dep[y] = dep[x] + 1, dfs(y, x);
		if (ok) return;
	}
}

bool in_chain[maxn + 5];

inline void work(int rt)
{
	seq.clear();
	dep[rt] = 0;
	dfs(rt);
	if (ok) return;
	int cnt = 0;
	for (auto u : seq) if (SZ(adj[u]) == 1) ++cnt;
	if (cnt > 3)
	{
		ok = 1;
		for (auto u : seq) 
			if (SZ(adj[u]) > 1) ans[u] = 2;
			else ans[u] = 1;
		return;
	}
	else if (cnt == 3)
	{
		sort(ALL(seq), [&](int x, int y) { return dep[x] > dep[y]; });
		vector<vector<int> > chains;
		for (auto u : seq) if (!in_chain[u])
		{
			vector<int> chain;
			int tmp = u;
			while (~tmp)
			{
				in_chain[tmp] = 1;
				chain.pb(tmp);
				tmp = fa[tmp];
			}
			reverse(ALL(chain));
			chains.pb(chain);
		}
		sort(ALL(chains), [&](const vector<int> &a, const vector<int> &b) { return SZ(a) < SZ(b); });
		LL sz0 = SZ(chains[0]);
		LL sz1 = SZ(chains[1]);
		LL sz2 = SZ(chains[2]);
		if ((sz0 * sz1 + sz1 * sz2 + sz0 * sz2) > sz0 * sz1 * sz2) return;
		ok = 1;
		if (sz0 >= 3)
		{
			chains[0].resize(3);
			chains[1].resize(3);
			chains[2].resize(3);
			sz0 = sz1 = sz2 = 3;
		}
		else if (sz1 >= 4)
		{
			chains[1].resize(4);
			chains[2].resize(4);
			sz1 = sz2 = 4;
		}
		else
		{
			assert(sz2 >= 6);
			chains[2].resize(6);
			sz2 = 6;
		}
		int tmp = sz0 * sz1 * sz2;
		ans[rt] = tmp;
		for (auto u : chains)
		{
			int x = tmp * (SZ(u) - 1) / SZ(u);
			REP(i, 0, SZ(u)) ans[u[i]] = i * x - (i - 1) * tmp;
		}
		return;
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(in_chain, 0, sizeof in_chain);
		ok = 0;
		scanf("%d%d", &n, &m);
		REP(i, 0, n) adj[i].clear();
		REP(i, 0, m)
		{
			int u, v;
			scanf("%d%d", &u, &v), --u, --v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		memset(vis, 0, sizeof(vis[0]) * n);
		memset(ans, 0, sizeof(ans[0]) * n);
		static int pos[maxn + 5];
		REP(i, 0, n) pos[i] = i;
		sort(pos, pos + n, [&](int x, int y) { return SZ(adj[x]) > SZ(adj[y]); });
		REP(i, 0, n) if (!vis[pos[i]])
		{
			work(pos[i]); 
			if (ok) break;
		}
		if (ok)
		{
			puts("YES");
			REP(i, 0, n) printf("%d ", ans[i]);
			printf("\n");
			int sum = 0;
			REP(i, 0, n)
			{
				for (auto j : adj[i]) if (j < i)
				{
					sum += ans[i] * ans[j];
				}
				sum -= ans[i] * ans[i];
			}
//			assert(sum >= 0);
		}
		else puts("NO");
	}
	return 0;
}