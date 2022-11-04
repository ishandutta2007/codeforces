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

const int MX = 100005;
int n, m, q, p[MX], in[MX], res[MX];
vii adj[MX];
ii o[MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

void solve (int j) {
	iota(p, p + MX, 0);
	memset(in, 0, sizeof(in));
	
	forr (u, 1, n)
		for (ii &v : adj[u])
			if (v.se & (1 << j))
				join(u, v.fi);
	
	forr (u, 1, n)
		for (ii &v : adj[u])
			if (~v.se & 1)
				in[parent(u)] = 1;
	
	forn (i, q) {
		int u = o[i].fi, v = o[i].se;
		
		if (parent(u) == parent(v))
			res[i] = 0;
		
		if (j && in[parent(u)])
			res[i] = min(res[i], 1);
	}
}

void main_() {
	cin >> n >> m;
	forn (i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	
	cin >> q;
	forn (i, q) {
		cin >> o[i].fi >> o[i].se;
		res[i] = 2;
	}
	
	forn (j, 31)
		solve(j);
	
	forn (i, q)
		cout << res[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}