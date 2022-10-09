#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
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
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
#define maxn 200100
bool odw[maxn];
vector <PII> v[maxn];
int col[maxn];
int SKL[maxn], n, a, b;
int d[maxn];
void dijkstra(int start) {
	set <PII> q;
	FOR(i, 1, n) d[i] = inf;
	d[start] = 0;
	q.insert({0, start});
	while (!q.empty()) {
		int x = (*(q.begin())).e2;
		q.erase(q.begin());
		for (auto u : v[x])
		if (d[x] + u.e2 < d[u.e1]) {
			q.erase({d[u.e1], u.e1});
			d[u.e1] = d[x] + u.e2;
			q.insert({d[u.e1], u.e1});
		}
	}
}

int main() {
	boost; cin.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> col[i];
	FOR(i, 2, n) {
		cin >> a >> b;
		int type = 0;
		if (col[a] == col[b]) type = 0;
		else type = 1;
		v[a].pb({b, type});
		v[b].pb({a, type});
	}
	dijkstra(1);
	int mx = 0;
	FOR(i, 1, n) mx = max(mx, d[i]);
	int st = 0;
	FOR(i, 1, n)
	  if (d[i] == mx) st = i;
	
	dijkstra(st);
	mx = 0;
	FOR(i, 1, n) mx = max(mx, d[i]);
	++mx;
	mx /= 2;
	cout << mx;
}