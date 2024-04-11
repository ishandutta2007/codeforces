#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, ex[MX];
vi adj[MX], inv[MX], res;

void solve () {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		inv[i].clear();
		ex[i] = 1;
	}
	res.clear();

	forn (i, m) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		inv[b].pb(a);
	}

	for (int u = 1; u <= n; u++) {
		if (!ex[u]) continue;
		
		int f = 0;
		for (int v : inv[u])
			f |= ex[v];

		if (f) {
			for (int v : adj[u])
				if (ex[v]) {
					res.pb(v);
					ex[v] = 0;
				}
		}
	}

	cout << res.size() << endl;
	for (int r : res)
		cout << r << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}