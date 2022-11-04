// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n;
ii mem[MX][2];
vi adj[MX];

ii operator + (ii a, ii b) {
	return {a.fi + b.fi, a.se + b.se};
}

ii dp (int u, int f, int p) {
	ii &res = mem[u][f];
	if (res.fi != -1) return res;
	
	ii no(0, -1), si(1, -adj[u].size());
	
	for (int v : adj[u]) {
		if (v == p) continue;
		
		no = no + dp(v, 0, u);
		si = si + dp(v, 1, u);
	}
	
	if (f) return res = no;
	return res = max(si, no);
}

int w[MX];
void rec (int u, int f, int p) {
	ii no(0, -1), si(1, -adj[u].size());
	
	for (int v : adj[u]) {
		if (v == p) continue;
		
		no = no + dp(v, 0, u);
		si = si + dp(v, 1, u);
	}
	
	if (f || no > si) {
		w[u] = 1;
		
		for (int v : adj[u]) {
			if (v == p) continue;
			rec(v, 0, u);
		}
	} else {
		w[u] = adj[u].size();
		
		for (int v : adj[u]) {
			if (v == p) continue;
			rec(v, 1, u);
		}
	}
}

void main_() {
	forn (i, MX)
		mem[i][0] = mem[i][1] = {-1, -1};
		
	cin >> n;
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	ii res = dp(1, 0, 0);
	if (n == 2) res.fi = 2;
	
	cout << res.fi << " " << -res.se << endl;
	
	rec(1, 0, 0);
	forr (i, 1, n)
		cout << w[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}