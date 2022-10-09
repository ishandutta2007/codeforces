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
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const ll INF = 1e18;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int maxn = 1000100;
int n, m, k;
int tab[maxn];
int s;

vector <ll> best[maxn];
ll d[maxn];
vector <int> v[maxn];
ll dp[maxn];

void bfs(int col)
{
	queue <int> q;
	
	FOR(i, 1, n)
		if (tab[i] == col)
		{
			q.push(i);
			d[i] = 0;
		}
		else d[i] = INF;
		
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto u : v[x])
			if (d[u] == INF)
			{
				d[u] = d[x] + 1;
				q.push(u);
			}
	}
	FOR(i, 1, n) best[i].pb(d[i]);
}

int main()
{
	boost;
	cin >> n >> m >> k >> s;
	FOR(i, 1, n) cin >> tab[i];
	FOR(i, 1, m)
	{
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	FOR(i, 1, k) bfs(i);
	FOR(i, 1, n)
	{
		sort(best[i].begin(), best[i].end());
		ll res = 0;
		for (int j=0; j<s; ++j) res += best[i][j];
		cout << res << ' ';
	}
}