#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
	if (a > b) a = b;
}
template<class T, class U>
void ckmax(T &a, U b)
{
	if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) ((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define MAXN 500013
#define MAGIC 241
#define INF 998244353

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

ll expo(ll a, ll e)
{
	if (e == 0) return 1;
	ll res = expo(a * a % INF, e >> 1);
	if (e & 1)
	{
		res *= a; res %= INF;
	}
	return res;
}

int N, Q, T;
ll iN;
vi edge[MAXN];
int parent[MAXN], st[MAXN], ft[MAXN], depth[MAXN], subtree[MAXN], ancestor[20][MAXN];
ll upd[MAXN], dp[MAXN];
ll stor[MAXN];
vpl upds;
vi ord;

void dfs(int u, int p)
{
	st[u] = ft[u] = T;
	subtree[u] = 1;
	T++;
	for (int v : edge[u])
	{
		if (v == p) continue;
		parent[v] = u;
		depth[v] = depth[u] + 1;
		dfs(v, u);
		ft[u] = ft[v];
		subtree[u] += subtree[v];
	}
	ord.PB(u);
}
int kth(int u, int k)
{
	FORD(i, 18, 0)
	{
		if (k & (1 << i))
		{
			u = ancestor[i][u];
		}
	}
	return u;
}
bool insubt(int u, int v)
{
	if (u == N) return true;
	return (st[u] <= st[v] && st[v] <= ft[u]);
}
ll get(ll u, ll v)
{
	if (u == v) return 0;
	//get contribution of u to v.
	if (insubt(u, v))
	{
		int w = kth(v, depth[v] - depth[u] - 1);
		return subtree[w];
	}
	return N - subtree[u];
}
void rebuild()
{
	for (auto p : upds)
	{
		upd[p.fi] += p.se;
	}
	FOR(i, 0, N)
	{
		if (upd[i] == 0) continue;
		upd[i] %= INF;
		stor[0] += subtree[i] * upd[i];
		stor[0] %= INF;
		stor[i] += (N - subtree[i]) * upd[i];
		stor[i] %= INF;
		for (int v : edge[i])
		{
			if (v == parent[i]) continue;
			stor[v] -= subtree[v] * upd[i];
			stor[v] %= INF;
		}
	}
	FORD(i, N, 0)
	{
		int u = ord[i];
		for (int v : edge[u])
		{
			if (v == parent[u]) continue;
			stor[v] += stor[u];
			if (stor[v] >= INF) stor[v] -= INF;
		}
	}
	FOR(i, 0, N)
	{
		// cerr << stor[i] << ' ';
		dp[i] += stor[i];
		dp[i] %= INF;
		if (dp[i] < 0) dp[i] += INF;
		upd[i] = 0;
		stor[i] = 0;
	}
	// cerr << endl;
	upds.clear();
	return;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	cerr << fixed << setprecision(4);
	cin >> N >> Q;
	FOR(i, 0, N - 1)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		edge[u].PB(v);
		edge[v].PB(u);
	}
	iN = expo(N, INF - 2);
	dfs(0, N);
	FOR(i, 0, 20)
	{
		ancestor[i][N] = N;
	}
	FOR(i, 0, N)
	{
		ancestor[0][i] = parent[i];
	}
	FOR(i, 1, 20)
	{
		FOR(j, 0, N)
		{
			ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
		}
	}
	FOR(i, 0, Q)
	{
		int qid, u; cin >> qid >> u; u--;
		if (i % MAGIC == 0)
		{
			//rebuild.
			rebuild();
		}
		if (qid == 2)
		{
			ll ans = dp[u];
			// cerr << dp[u] << endl;
			for (pll p : upds)
			{
				ans += (N - get(p.fi, u)) * p.se;
				ans %= INF;
			}
			cout << ans << '\n';
			//solve for u.
		}
		if (qid == 1)
		{
			ll v; cin >> v;
			v *= iN; v %= INF;
			upds.PB({u, v});
		}
	}
	return 0;
}