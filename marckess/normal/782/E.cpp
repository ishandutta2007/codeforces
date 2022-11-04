#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, k, u, v, cn;
vi adj[MX], r;
bitset<MX> bs;

void dfs (int u) {
	bs[u] = 1;

	for (int v : adj[u]) {
		if (bs[v]) continue;

		r.pb(v);
		dfs(v);
		r.pb(u);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	while (m--) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	r.pb(1);
	dfs(1);

	int lim = (2 * n + k - 1) / k;

	for (int i = 0; i < r.size(); i++) {
		if (i % lim == 0) {
			if (i) cout << endl;
			cout << min(lim, (int)r.size() - i);
			k--;
		}
		cout << " " << r[i];
	}
	cout << endl;

	while (k--)
		cout << "1 1" << endl;

	return 0;
}