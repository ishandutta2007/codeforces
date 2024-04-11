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
#define INF 1000000007
#define MAXN 2000013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, M, T = 1;
vpi edge[MAXN];
int dist[MAXN];
priority_queue<pii, vector<pii>, greater<pii> > pq;
int dp[MAXN], ans[MAXN];
int ancestor[25][MAXN];
int ch[MAXN][11];
ll val[MAXN], depth[MAXN], cpr[MAXN];
ll pw[MAXN];
int nd[MAXN];

int getlen(int x)
{
	if (x <= 9) return 1;
	if (x <= 99) return 2;
	if (x <= 999) return 3;
	if (x <= 9999) return 4;
	if (x <= 99999) return 5;
	if (x <= 999999) return 6;
	return 7;
}
vi geth(int x)
{
	vi res;
	while(x != 0)
	{
		res.PB(x % 10); x /= 10;
	}
	reverse(ALL(res));
	return res;
}
bool cmp(int a, int b)
{
	return dist[a] < dist[b];
}
int lca(int u, int v)
{
	// first guy that u goes to
	//we're only gonna call this for guys at same depth anyway
	FORD(i, 25, 0)
	{
		if (ancestor[i][u] != ancestor[i][v])
		{
			u = ancestor[i][u];
			v = ancestor[i][v];
		}
	}
	return u;
}
bool cmp1(int u, int v)
{
	//is u better than v?
	int lu = lca(u, v), lv = lca(v, u);
	return val[lu] < val[lv];
}
int ins(int u, int v)
{
	vi cur = geth(v);
	for (int d : cur)
	{
		if (!ch[u][d])
		{
			ch[u][d] = T;
			val[T] = d;
			ancestor[0][T] = u;
			depth[T] = depth[u] + 1;
			FOR(i, 1, 25)
			{
				ancestor[i][T] = ancestor[i - 1][ancestor[i - 1][T]];
			}
			cpr[T] = (cpr[u] * 10 + d) % INF;
			// cerr << u << " -> " << T << ' ' << d << ' ' << cpr[T] << endl;
			T++;
		}
		u = ch[u][d];
	}
	return u;
}
void proc(int u)
{
	for (pii p : edge[u])
	{
		int len = getlen(p.fi), v = p.se;
		if (dist[u] != dist[v] + len) continue;
		nd[v] = ins(dp[v], p.fi);
		//try the trie.
	}
	dp[u] = -1;
	for (pii p : edge[u])
	{
		int len = getlen(p.fi), v = p.se;
		if (dist[u] != dist[v] + len) continue;
		if (dp[u] == -1 || cmp1(nd[v], dp[u]))
		{
			// cerr << v << " -> " << u << ' ' << nd[v] << ' ' << dp[u] << ' ' << cpr[nd[v]] << ' ' << cpr[dp[u]] << endl;
			dp[u] = nd[v];
		}
	}
	return;
}


int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	FOR(i, 0, M)
	{
		int u, v; cin >> u >> v; u--; v--;
		edge[u].PB({i + 1, v});
		edge[v].PB({i + 1, u});
	}
	pw[0] = 1;
	FOR(i, 1, N + 10)
	{
		pw[i] = pw[i - 1] * 10 % INF;
	}
	FOR(i, 0, N) dist[i] = INF;
	FOR(i, 0, 25)
	{
		ancestor[i][MAXN - 1] = MAXN - 1;
		ancestor[i][0] = MAXN - 1;
	}
	dist[0] = 0;
	pq.push({0, 0});
	while(!pq.empty())
	{
		int u = pq.top().se, d = pq.top().fi; pq.pop();
		if (d != dist[u]) continue;
		if (u != 0)
		{
			proc(u);
		}
		for (pii p : edge[u])
		{
			int len = getlen(p.fi), v = p.se;
			if (dist[v] > len + d)
			{
				dist[v] = len + d;
				pq.push({dist[v], v});
			}
		}
	}
	FOR(i, 1, N)
	{
		cout << cpr[dp[i]] << '\n';
	}
	//build a trie.

}