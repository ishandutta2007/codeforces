#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REYNA(i, a, b) for (int i=(a); i<(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int mod = 1e9+7;
const int maxn = 2e5 + 100;
int n, m, k, a;
vector <int> g[maxn];
int d[maxn][2];
int par[maxn][2];
int out[maxn];

void bfs(int start, int type)
{
	queue <PII> q;
	q.push(mp(start, type));
	while (!q.empty())
	{
		PII x = q.front();
		q.pop();
		for (auto u : g[x.e1])
			if (d[u][x.e2 ^ 1] == inf)
			{
				d[u][x.e2 ^ 1] = d[x.e1][x.e2] + 1;
				par[u][x.e2 ^ 1] = x.e1;
				q.push(mp(u, x.e2 ^ 1));
			}
	}

}

int A[maxn], B[maxn], DL = 0;
vector <int> top;
int where[maxn];
bool odw[maxn];

void dfs(int x)
{
	odw[x] = 1;
	for (auto u : g[x])
		if (!odw[u]) dfs(u);
	where[x] = top.size();
	top.pb(x);
}

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, n)
	{
		cin >> k;
		FOR(j, 1, k)
		{
			cin >> a;
			g[i].pb(a);
			out[i] = 1;
			A[++DL] = i; B[DL] = a;
		}
	}
	assert(DL == m);
	int sta;
	cin >> sta;
	FOR(i, 1, n)
		FOR(j, 0, 1) d[i][j] = inf;
	
	d[sta][0] = 0;
	par[sta][0] = -1;
	bfs(sta, 0);
	FOR(i, 1, n)
		if (out[i] == 0 && d[i][1] != inf)
		{
			cout << "Win\n";
			vector <int> res;
			int way = 1, x = i;
			while (par[x][way] != -1)
			{
				res.pb(x);
				x = par[x][way];
				way ^= 1;
			}
			res.pb(sta);
			reverse(res.begin(), res.end());
			for (auto u : res) cout << u << ' ';
			exit(0);
		}
	
	//can we not lose
	dfs(sta);
	for (int i=1; i<=m; ++i)
	{
		int a = A[i], b = B[i];
		if (!odw[a] || !odw[b]) continue;
		if (where[a] <= where[b]) OUT("Draw");
	}
	
	cout << "Lose";
}