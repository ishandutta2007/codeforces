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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, mx;
vi adj[MX];
vii res;

void dfs (int u, int p, int t, int up) {
	res.emplace_back(u, t);

	for (int v : adj[u])
		if (v != p) {
			if (t == mx) {
				t = mx - int(adj[u].size());
				res.emplace_back(u, t);
			}

			t++;
			dfs(v, u, t, t);
			res.emplace_back(u, t);
		}

	if (u == p) return;

	if (t >= up)
		res.emplace_back(u, up - 1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n - 1) {
		int a, b;

		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);

		mx = max(mx, (int)adj[a].size());
		mx = max(mx, (int)adj[b].size());
	}

	dfs(1, 1, 0, 0);

	cout << res.size() << endl;
	for (ii &r : res)
		cout << r.fi << " " << r.se << endl;

	return 0;
}