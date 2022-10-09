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
int n, m, k, c, zap;
#define maxn 100100
int COMP;
vector <int> skladowe[maxn], v[maxn], pref[maxn];
vector <ll> prefWazone[maxn];
int skl[maxn], longer[maxn];
int d[maxn][2], diam[maxn];
bool odw[maxn];

void dfs(int x)
{
	odw[x] = 1;
	skl[x] = COMP;
	skladowe[COMP].pb(x);
	for (auto u : v[x])
	if (!odw[u]) dfs(u);
}

void licz(int x, int kt)
{
	odw[x] = 1;
	for (auto u : v[x])
	if (!odw[u])
	{
		d[u][kt] = d[x][kt] + 1;
		licz(u, kt);
	}
}

map <PII, ll> M;

inline ll pytaj(int a, int b)
{
	//a jest zawsze mniejsze
	ll diameter = max(diam[a], diam[b]), ret = 0;
	//second = 1 + longer[stha] + longer[sthb]
	for (auto u : skladowe[a])
	{
		ll C = longer[u] + 1, szukane = diameter - C + 1; //chcemy, aby x bylo przynajmniej tyle
		if (szukane < 0) szukane = 0;
		int ileTakich = 0;
		if (szukane < (int)pref[b].size()) 
		{
			ileTakich = pref[b][szukane];
			ret += C * pref[b][szukane];
			ret += prefWazone[b][szukane];
		}
		ret += diameter * (skladowe[b].size() - ileTakich);
	}
	return ret;
}

inline double solve(int a, int b)
{
	if (skladowe[a].size() > skladowe[b].size()) swap(a, b);
	if (M[{a, b}] == NULL) M[{a, b}] = pytaj(a, b);
	ll ile = (ll)skladowe[a].size() * (ll)skladowe[b].size();
	return (double)M[{a, b}] / (double)ile;
}

int main()
{
	scanf("%d%d%d", &n, &m, &zap);
	FOR(i, 1, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	
	FOR(i, 1, n)
		if (!odw[i]) 
		{
			++COMP;
			dfs(i);
			for (auto u : skladowe[COMP]) odw[u] = 0;
			d[i][0] = 0;
			licz(i, 0);
			PII nowy = {-1, -1};
			for (auto u : skladowe[COMP])
			{
				odw[u] = 0;
				if (d[u][0] > nowy.e1) nowy = mp(d[u][0], u);
			}
			
			d[nowy.e2][0] = 0;
			licz(nowy.e2, 0);
			nowy = {-1, -1};
			for (auto u : skladowe[COMP])
			{
				odw[u] = 0;
				if (d[u][0] > nowy.e1) nowy = mp(d[u][0], u);
			}
			
			diam[COMP] = nowy.e1;
			d[nowy.e2][1] = 0;
			licz(nowy.e2, 1);
			pref[COMP].resize(skladowe[COMP].size() + 1);
			prefWazone[COMP].resize(skladowe[COMP].size() + 1);
			int sz = (int)skladowe[COMP].size();
			FOR(j, 0, sz) pref[COMP][j] = 0;
			for (auto u : skladowe[COMP]) 
			{
				longer[u] = max(d[u][0], d[u][1]);
				pref[COMP][longer[u]]++;
			}
			
			for (ll j=sz-1; j>=0; --j) prefWazone[COMP][j] = prefWazone[COMP][j + 1] + j * pref[COMP][j];
			for (int j=sz-1; j>=0; --j) pref[COMP][j] += pref[COMP][j+1];
			
		}
	
	
	FOR(i, 1, zap)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (skl[a] == skl[b])  puts("-1");
		else printf("%.10lf\n", solve(min(skl[a], skl[b]), max(skl[a], skl[b])));
	}
	
}