#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef vector <int> vi;
typedef unsigned int ui;
const int inf = 2e9+9091203;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int BASE=10000;
int n, m, b,a, c, k, deg;
#define maxn 1500100
int t[maxn];
map <PII, bool> block;
bool odw[maxn];
int SCC, VAL = 0;

set <int> zostalo;

void dfs(int x) {
	if (x == 1) return;
	odw[x] = 1;
	zostalo.erase(x);
	if (!block[{x, 1}]) VAL = 1;
	vector <int> nev;
	nev.clear();
	for (auto u : zostalo) {
		if (!block[{x, u}]) nev.pb(u);
	}
	for (auto u : nev) zostalo.erase(u);
	for (auto u : nev) {
		if (!odw[u]) dfs(u);
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &deg);
	int kraw = n-1;
	for (int i=1; i<=m; ++i)
	{
		scanf("%d%d", &a, &b);
		block[{a,b}] = block[{b,a}] = 1;
		if (a == 1 || b == 1) kraw--;
	}
	for (int i=2; i<=n; ++i) zostalo.insert(i);
	for (int i=2; i<=n; ++i)
	  if (!odw[i]) {
		  ++SCC;
		  VAL = 0;
		  dfs(i);
		  if (!VAL) OUT("impossible");
	  }
	  
	int MINDEG = SCC, MAXDEG = kraw;
	///cout << MINDEG << ' ' << deg << ' ' << MAXDEG << endl;
	if (deg >= MINDEG && deg <= MAXDEG) OUT("possible");
	OUT("impossible");
	
}