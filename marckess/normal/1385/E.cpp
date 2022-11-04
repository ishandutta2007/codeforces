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
int n, m, in[MX], ex[MX];
vi adj[MX], dir[MX];
vii res;

void solve () {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		dir[i].clear();
		in[i] = 0;
		ex[i] = 0;
	}
	res.clear();

	forn (i, m) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t) {
			res.emplace_back(u, v);
			dir[u].pb(v);
			in[v]++;
		} else {
			adj[u].pb(v);
			adj[v].pb(u);
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!in[i])
			q.push(i);

	while (q.size()) {
		int u = q.front();
		q.pop();
		ex[u] = 1;
		
		for (int v : adj[u])
			if (!ex[v])
				res.emplace_back(u, v);

		for (int v : dir[u]) {
			in[v]--;
			if (!in[v]) q.push(v);
		}
	}

	for (int i = 1; i <= n; i++)
		if (!ex[i]) {
			cout << "NO" << endl;
			return;
		}

	cout << "YES" << endl;
	for (ii &p : res)
		cout << p.fi << " " << p.se << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}