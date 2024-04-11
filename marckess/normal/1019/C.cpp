#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, m, u, v;
vi adj[MX], res;
bitset<MX> exi, us, alc;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		cin >> u >> v;
		adj[u].pb(v);
	}

	exi.set();
	for (int u = 1; u <= n; u++) {
		if (exi[u]) {
			us[u] = 1;
			exi[u] = 0;
			for (int v : adj[u])
				exi[v] = 0;
		}
	}

	for (int u = n; u; u--) {
		if (us[u] && !alc[u]) {
			res.pb(u);
			for (int v : adj[u])
				alc[v] = 1;
		}
	}

	cout << res.size() << endl;
	for (int u : res) cout << u << " ";
	cout << endl;

	return 0;
}