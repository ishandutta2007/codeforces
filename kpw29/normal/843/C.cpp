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
const int mod = 1000000;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 500100;
vector <int> v[maxn];
vector <int> centroids;
vector <PPI> wynik;
int n;
int r[maxn], maks[maxn];
bool centroid[maxn];

void przelacz(int root, int skad, int dokad) {
	wynik.pb(mp(mp(root, skad), dokad));
}

void dfs(int x, int p) {
	r[x] = 1;
	for (auto u : v[x])
		if (u != p) {
			dfs(u, x);
			r[x] += r[u];
			maks[x] = max(maks[x], r[u]);
		}
}
vector <int> met;
int d[maxn], ojciec[maxn];

void find(int x, int par) {
	met.pb(x);
	ojciec[x] = par;
	for (auto u : v[x])
		if (u != par) {
			d[u] = d[x] + 1;
			find(u, x);
		}
}

int LAST;
void fuckRightInTheCentroid(int x, int veryBig) {
	met.clear();
	d[x] = 0;
	find(x, veryBig);
	LAST = x;
	for (auto u : met)
		if (d[u] > 1)
		{
			przelacz(veryBig, LAST, u);
			przelacz(u, ojciec[u], x);
			LAST = u;
		}
	
	if (LAST != x) przelacz(veryBig, LAST, x);
}

void fuckTree(int x) {
	for (auto u : v[x])
		if (!centroid[u]) fuckRightInTheCentroid(u, x);
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 2, n) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	int pol = (n / 2);
	dfs(1, 1);
	FOR(i, 1, n)
	{
		maks[i] = max(maks[i], n - r[i]);
		if (maks[i] <= pol) centroids.pb(i);
	}
	
	for (auto u : centroids) centroid[u] = 1;
	
	for (auto u : centroids) fuckTree(u);
	
	cout << (int)wynik.size() << "\n";
	for (auto u : wynik) cout << u.e1.e1 << ' ' << u.e1.e2 << ' ' << u.e2 << "\n";
}