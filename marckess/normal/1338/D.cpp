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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, mem[MX][2], res;
vi adj[MX];

int dp (int u, int f, int p) {
	int &res = mem[u][f];
	if (res != -1) return res;

	int x = 0;

	for (int v : adj[u])
		if (v != p)
			x = max(x, dp(v, 0, u));

	res = x + max(0, (int)adj[u].size() - 2);

	x = 0;
	if (!f) {
		for (int v : adj[u])
			if (v != p)
				x = max(x, dp(v, 1, u));

		res = max(res, x + 1);
	}

	return res;
}

void dfs (int u, int p = -1) {
	int x = 0, y = 0;

	for (int v : adj[u])
		if (v != p) {
			int p = dp(v, 0, u);

			if (x < p) {
				y = x;
				x = p;
			} else if (y < p) {
				y = p;
			}
		}

	res = max(res, x + y + max(0, (int)adj[u].size() - 2));

	x = 0, y = 0;

	for (int v : adj[u])
		if (v != p) {
			int p = dp(v, 1, u);

			if (x < p) {
				y = x;
				x = p;
			} else if (y < p) {
				y = p;
			}
		}

	res = max(res, x + y + 1);

	for (int v : adj[u])
		if (v != p)
			dfs(v, u);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);
	cout << res << endl;

	return 0;
}