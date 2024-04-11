#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define x first
#define y second
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
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int T, n, m, k, b, c, g, Q, DL;
#define maxn 100100
vector <PII> v[maxn];
int a[maxn], r[maxn], wyn;
bool odw[maxn], mark[maxn];
ll d[maxn];
multiset <ll> s;

void dfs(int x) {
	odw[x] = 1;
	s.insert(d[x]);
	ll value = *s.begin();
	if (value < d[x] - a[x]) mark[x] = 1;
	r[x] = 1;
	for (auto u : v[x])
	if (!odw[u.e1]) {
		d[u.e1] = d[x] + u.e2;
		dfs(u.e1);
		r[x] += r[u.e1];
	}
	
	assert(!s.empty());
	s.erase(s.find(d[x]));
}

void find(int x){ 
	odw[x] = 1;
	if (mark[x]) {
		wyn += r[x];
		return;
	}
	
	for (auto u : v[x])
	  if (!odw[u.e1]) find(u.e1);
}

int main() {
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 2, n) {
		cin >> b >> c;
		v[i].pb({b, c});
		v[b].pb({i, c});
	}
	dfs(1);
	FOR(i, 1, n) odw[i] = 0;
	find(1);
	cout << wyn;
}