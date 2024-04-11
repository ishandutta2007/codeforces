//bad_solution
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
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 300100

int pre[maxn], post[maxn], a, b;
bool odw[maxn];
vector <int> v[maxn];

int skok[maxn][20], TIME = 0, n, m;

void dfs(int x) {
	pre[x] = ++TIME;
	odw[x] = 1;
	for (auto u : v[x])
	  if (!odw[u]) {
		  skok[u][0] = x;
		  dfs(u);
	  }
	post[x] = ++TIME;
}
inline bool parent(int x, int y) {
	return (pre[x] <= pre[y] && post[x] >= post[y]);
}

int getLCA(int x, int y) {
	if (parent(x, y)) return x;
	if (parent(y, x)) return y;
	for (int j=19; j>=0; --j)
	  if (!parent(skok[x][j], y)) x = skok[x][j];
	return skok[x][0];
}

PPI zap[maxn];
ll dodajdoseta[maxn];

vector <int> pocz[maxn], kon[maxn];
ll sum[maxn], cost[maxn], add[maxn];
vector <int> sons[maxn];
set <PLI> s[300100];
int where[maxn];

void merge(int x, int y) {
	int g1 = where[x], g2 = where[y];
	if (s[g1].size() > s[g2].size()) swap(g1, g2), swap(x, y);
	//przepisujemy x do y
	
	for (auto u : s[g1]) s[g2].insert(mp(u.e1 + add[g1] - add[g2], u.e2));
	s[g1].clear();
	where[x] = g2;
}

void count(int x) {
	odw[x] = 1;
	for (auto u : v[x])
	  if (!odw[u]) {
		  count(u);
		  sons[x].pb(u);
		  sum[x] += cost[u];
	  }
	for (auto u : pocz[x]) {
		PLI temp = mp(zap[u].e2 + sum[x], u);
		s[x].insert(temp);
	}
	
	if (x == 1) return;
	
	for (auto u : sons[x]) {
		add[where[u]] += sum[x] - cost[u];
		merge(u, x);
	}
	
	//removal time
	int szukaj = where[x];
	while (!s[szukaj].empty()) {
		PLI fir = *s[szukaj].begin();
		if (pre[x] <= pre[zap[fir.e2].e1.e2]) s[szukaj].erase(s[szukaj].begin());
		else break;
	}
	
	if (s[szukaj].empty()) OUT(-1);
	cost[x] = (*s[szukaj].begin()).e1 + add[where[x]];
	
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<n; ++i) {
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);	
	}
	dfs(1);
	skok[1][0] = 1;
	for (int j=1; j<20; ++j)
	  for (int i=1; i<=n; ++i) skok[i][j] = skok[skok[i][j-1]][j-1];
	
	for (int i=1; i<=m; ++i) {
		scanf("%d%d%d", &zap[i].e1.e1, &zap[i].e1.e2, &zap[i].e2);
		int u = getLCA(zap[i].e1.e1, zap[i].e1.e2);
		pocz[zap[i].e1.e1].pb(i);
		zap[i].e1.e2 = u;
	}
	
	for (int i=1; i<=n; ++i) where[i] = i;
	
	/*for (int i=1; i<=n; ++i) {
		cout << "i: " << i << endl;
		for (auto u : pocz[i]) cout << u << ' ';
		cout << endl;
		for (auto u : kon[i]) cout << u << ' ';
		cout << endl;

	}*/
	
	fill(odw, odw + n + 10, false);
	count(1);
	cout << sum[1];
	
}