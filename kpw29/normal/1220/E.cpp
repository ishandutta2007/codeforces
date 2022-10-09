#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 200100;
int n, m;
vector <int> v[maxn];
ll att[maxn];
int st, TIME = 0, PRE[maxn], LOW[maxn];
bool oc[maxn];
ll dist[maxn];
bool odw[maxn];

void dfs(int x, int p)
{
	odw[x] = 1;
	PRE[x] = ++TIME;
	LOW[x] = PRE[x];
	for (auto u : v[x])
	{
		if (odw[u])
		{
			if (u != p) LOW[x] = min(LOW[x], PRE[u]);
		}
		else
		{
			dfs(u, x);
			LOW[x] = min(LOW[x], LOW[u]);
		}
	}
	
	if (x != st && LOW[x] != PRE[x])
	{
		oc[x] = oc[p] = 1;
	}
}

void dep(int x)
{
	odw[x] = 1;
	for (auto u : v[x])
		if (!odw[u])
		{
			dist[u] = dist[x] + att[u];
			oc[u] |= oc[x];
			dep(u);
		}
}
int deg[maxn];
bool rem[maxn];

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, n) cin >> att[i];
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
		deg[a]++; deg[b]++;
	}
	cin >> st;
	
	dfs(st, -1);
	queue <int> q;
	FOR(i, 1, n)
		if (deg[i] == 1 && i != st) q.push(i);
	
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		rem[x] = 1;
		for (auto u : v[x])
		{
			deg[u]--;
			if (deg[u] == 1 && u != st) q.push(u);
		}
	}
	
	/*FOR(i, 1, n) cout << PRE[i] << ' ';
	cout << endl;
	FOR(i, 1, n) cout << LOW[i] << ' ';
	cout << endl;
	
	FOR(i, 1, n) cout << oc[i] << ' ';*/
	ll score = 0;
	FOR(i, 1, n)
		if (!rem[i]) {
			score += att[i];
			att[i] = 0;
		}
	
	fill(odw, odw+n+4, false);
	
	dist[st] = att[st];
	dep(st);
	
	ll wyn = 0;
	FOR(i, 1, n) wyn = max(wyn, score + dist[i]);
	cout << wyn;
}