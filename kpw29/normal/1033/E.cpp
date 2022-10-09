#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
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
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1020000;
int n, color[610];

int mac[610][610];
int que = 0;

int ask(vector <int> &v) {
	if ((int)v.size() <= 1) return 0;
	++que;
	assert(que <= 20000);
	cout << "? " << v.size() << endl;
	for (auto u : v) cout << u << ' ';
	cout << endl;
	int odp = 0;
	cin >> odp;
	/*for (auto u : v)
		for (auto sec: v)
			if (mac[u][sec] + mac[sec][u]) ++odp;*/
			
	assert(odp != -1);
	return odp;
}

int find_edge(int x, vector <int> &v) { //na pewno jest jakas w tym zbiorze
	int sz = v.size(); 
	if (sz == 1) return v[0];
	sz /= 2;
	vector <int> v1, v2;
	for (int i=0; i<sz; ++i) v1.pb(v[i]);
	for (int i=sz; i<(int)v.size(); ++i) v2.pb(v[i]);
	
	int help = ask(v1);
	v1.pb(x);
	int nowe = ask(v1);
	v1.pop_back();
	if (help == nowe) return find_edge(x, v2);
	return find_edge(x, v1);
}

int search(int x) {
	vector <int> tmp;
	for (int i=1; i<=n; ++i)
		if (color[i] == 2) tmp.pb(i);
	if (tmp.empty()) return 0;
	int help = ask(tmp);
	tmp.pb(x);
	int nowe = ask(tmp);
	tmp.pop_back();
	if (help == nowe) return 0;
	return find_edge(x, tmp);
}
int par[610], d[610];

void dfs(int x) {
	while (1)
	{
		int nowy = search(x);
		if (nowy == 0) return;
		color[nowy] = (1 ^ color[x]);
		d[nowy] = d[x] + 1;
		par[nowy] = x;
		dfs(nowy);
	}
}

void cycle(int x, int y) {
	vector <int> upx, upy;
	assert(x != y);
	while (d[x] > d[y]) {
		upx.pb(x);
		x = par[x];
	}
	while (d[x] < d[y]) {
		upy.pb(y);
		y = par[y];
	}
	
	while (x != y) {
		upy.pb(y);
		y = par[y];
		upx.pb(x);
		x = par[x];
	}
	
	if (x == y) upx.pb(x);
	cout << "N\n";
	cout << (int)upx.size() + upy.size() << "\n";
	for (auto u : upx) cout << u << ' ';
	for (int i=upy.size()-1; i>=0; --i) cout << upy[i] << ' ';
	cout << endl;
	exit(0);
}

void obij(vector <int> v) {
	int whole = ask(v);
	for (auto u : v) {
		vector <int> help;
		for (auto tmp : v)
			if (u != tmp) help.pb(tmp);
		
		if (whole != ask(help)) {
			int new_vertex = find_edge(u, help);
			cycle(new_vertex, u);
		}	
	}
}
int m;
int main()
{
	cin >> n;
	//cin >> n >> m;
	/*FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		mac[a][b] = mac[b][a] = 1;
	}*/
	
	FOR(i, 1, n) color[i] = 2;
	FOR(i, 1, n)
		if (color[i] == 2) {
			color[i] = 0;
			dfs(i);
		}
	
	vector <int> jed, dwa;
	FOR(i, 1, n) {
		if (color[i] == 0) jed.pb(i);
		if (color[i] == 1) dwa.pb(i);
		assert(color[i] != 2);
	}
	
	int p1 = ask(jed), p2 = ask(dwa);
	if (p1 == 0 && p2 == 0) {
		cout << "Y\n";
		cout << jed.size() << endl;
		for (auto u : jed) cout << u << ' ';
		cout << endl;
		cout << dwa.size() << endl;
		for (auto u : dwa) cout << u << ' ';
		cout << endl;
		exit(0);
	}
	
	if (p1) obij(jed);
	else obij(dwa);
}