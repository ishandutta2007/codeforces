#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;

#define maxn 100100
ll n, m, k, a, b, c;
vector <int> v[maxn];
int col[maxn];
int CAND = 0;
bool odw[maxn];

void dfs(int x) {
	odw[x] = 1;
	for (auto u : v[x])
	if (!odw[u])
	{
		dfs(u);
		if (col[x] != col[u] && CAND == 0) CAND = x;
	}
}
bool ODP = 1;
void sprawdz(int x, int color) {
	if (odw[x]) return;
	odw[x] = 1;
	for (auto u : v[x])
		if (!odw[u]) sprawdz(u, color);
	if (col[x] != color) ODP = 0;
}

bool check(int x) {
	odw[x] = 1;
	bool wyn = 1;
	for (int i=0; i<(int)v[x].size(); ++i)
	{
		int syn = v[x][i];
		ODP = 1;
		sprawdz(syn, col[syn]);
		wyn &= ODP;
	}
	return wyn;
}
int main()
{
	boost;
	cin >> n;
	if (n == 2)
	{
		cout << "YES\n";
		cout << 1;
		exit(0);
	}
	FOR(i, 2, n){
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	FOR(i, 1, n) cin >> col[i];
	int sth = 1;
	while (sth <= n && v[sth].size() <= 1) sth++;
	if (sth == n + 1) OUT("NO");
	dfs(sth);
	
	fill(odw, odw+n+5, false);
	
	if (CAND == 0)
	{
		cout << "YES\n";
		cout << sth;
		exit(0);
	}
	else
	{
		if (check(CAND))
		{
			cout << "YES\n";
			cout << CAND;
		}
		else cout << "NO";
	}
}