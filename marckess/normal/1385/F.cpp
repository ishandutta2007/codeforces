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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, k, res;
set<int> adj[MX], h[MX], pos;

void solve () {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		h[i].clear();
	}

	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	for (int i = 1; i <= n; i++)
		if (adj[i].size() == 1)
			h[*adj[i].begin()].insert(i);

	for (int i = 1; i <= n; i++)
		if (h[i].size() >= k)
			pos.insert(i);

	res = 0;
	while (pos.size()) {
		int u = *pos.begin();
		pos.erase(pos.begin());

		if (h[u].size() < k) continue;
		res++;

		vi e;
		for (int v : h[u]) {
			e.pb(v);
			if (e.size() == k) break;
		}

		for (int v : e) {
			h[u].erase(v);
			h[v].erase(u);
			adj[u].erase(v);
			adj[v].erase(u);
		}

		if (adj[u].size() == 1) {
			int v = *adj[u].begin();
			h[v].insert(u);
			if (h[v].size() >= k)
				pos.insert(v);
		}

		if (h[u].size() >= k)
			pos.insert(u);
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}