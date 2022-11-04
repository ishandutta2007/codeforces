#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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
int n, res;
vi adj[MX];

void reset () {
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
}

int dfs (int u, int p) {
	vi a;
	
	for (int v : adj[u])
		if (v != p)
			a.pb(dfs(v, u) + 1);
	
	sort(all(a));
	
	if (u == 1) {
		if (adj[u].size() == 1)
			res = max(res, a[0]);
		else
			res = max({
				res,
				a.back(),
				*(a.end() - 2) + 1
			});
	} else if (a.size()) {
		res = max(res, a.back() + 1);
		return a[0];
	}
	
	return 0;
}

void solve () {
	cin >> n;
	reset();
	
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	res = 0;
	dfs(1, 1);
	
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