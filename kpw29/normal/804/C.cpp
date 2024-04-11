#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector <int> vi;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, m, k, c, a, b;
ll A = 0, B = 0;
#define maxn 1000100
vector <int> v[maxn];
vector <int> co[maxn];
int ile[maxn], color[maxn], CLR;
int szukaj[maxn];
bool odw[maxn];

void dfs(int x)
{
	odw[x] = 1;
	vector <int> nowe;
	nowe.clear();
	for (auto u : co[x])
	{
		if (color[u] == 0) nowe.pb(u);
		else szukaj[color[u]] = x;
	}
	
	int wsk = 0;
	szukaj[0] = x;
	for (auto u : nowe)
	{
		while (szukaj[wsk] == x) ++wsk;
		color[u] = wsk;
		szukaj[wsk] = x;
	}
	
	for (auto u : v[x])
	{
		if (!odw[u]) 
		{
			dfs(u);
		}
	}
	
}
int main()
{
	boost;
	cin >> n >> m;
	int gg = 0;
	FOR(i, 1, n)
	{
		cin >> ile[i];
		gg = max(ile[i], gg);
		FOR(j, 1, ile[i]) 
		{
			cin >> a;
			co[i].pb(a);
		}
	}
	
	FOR(i, 1, n-1)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1);
	FOR(i, 1, m) color[i] = max(color[i], 1);
	if (gg <= 1)
	{
		cout << 1 << endl;
		FOR(i, 1, m) cout << 1 << ' ';
		exit(0);
	}
	
	int M = 0;
	FOR(i, 1, m) M = max(color[i], M);
	cout << M << endl;
	FOR(i, 1, m) cout << color[i] << ' ';
}