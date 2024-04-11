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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, q, x, y, t, z, mn = -1, up[MX], last = 0;
vi adj[MX];

void dfs (int u, int p) {
	for (int v : adj[u])
		if (v != p) {
			up[v] = min(up[u], v);
			dfs(v, u);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	while (q--) {
		cin >> t >> z;
		x = (z + last) % n + 1;

		if (t == 1) {
			if (mn == -1) {
				mn = up[x] = x;
				dfs(x, x);
			}
			mn = min(mn, up[x]);
		} else {
			last = min(mn, up[x]);
			cout << last << endl;
		}
	}

	return 0;
}