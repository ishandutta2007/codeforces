#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define OUT(x) { cout << x; return 0; }
#define PRINT(x, y) {printf("%d %d\n", x, y); return;} 
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
const int maxn = 1000100;
int T, n, m, k, a, b, c;

bool odw[maxn];
vector <int> v[maxn];
int fajne[maxn];
ll sub[maxn];
ll wyn = 0;

void dfs(int x) {
	odw[x] = 1;
	sub[x] = fajne[x];
	for (auto u : v[x])
	  if (!odw[u]) {
		  dfs(u);
		  sub[x] += sub[u];
		  wyn += min(sub[u], k - sub[u]);
	  }
}
int main() {
	scanf("%d%d", &n, &k);
	k *= 2;
	FOR(i, 1, k) {
		scanf("%d", &a);
		fajne[a]++;
	}
	
	FOR(i, 2, n) {
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1);
	cout << wyn;
}