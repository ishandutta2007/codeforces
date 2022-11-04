#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, c[MX][4], col[MX];
ll mem[MX][4][4];
vi adj[MX];

ll dfs (int u, int p, int a, int b) {
	ll &res = mem[u][a][b];
	if (res != -1) return res;

	int to = -1;
	for (int v : adj[u])
		if (v != p)
			to = v;

	res = 1e18;
	for (int i = 1; i <= 3; i++)
		if (i != a && i != b) {
			if (to != -1)
				res = min(res, dfs(to, u, b, i) + c[u][i]);
			else
				res = min(res, 1ll * c[u][i]);
		}

	return res;
}

void rec (int u, int p, int a, int b) {
	int to = -1;
	for (int v : adj[u])
		if (v != p)
			to = v;

	ll &res = mem[u][a][b];
	for (int i = 1; i <= 3; i++)
		if (i != a && i != b) {
			if (to != -1) {
				if (dfs(to, u, b, i) + c[u][i] == res) {
					col[u] = i;
					rec(to, u, b, i);
				}
			} else {
				if (c[u][i] == res) {
					col[u] = i;
				}
			}
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n) cin >> c[i+1][1];
	forn (i, n) cin >> c[i+1][2];
	forn (i, n) cin >> c[i+1][3];

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1; i <= n; i++)
		if (adj[i].size() >= 3) {
			cout << -1 << endl;
			return 0;
		}

	memset(mem, -1, sizeof(mem));
	for (int i = 1; i <= n; i++)
		if (adj[i].size() == 1) {
			cout << dfs(i, i, 0, 0) << endl;
			rec(i, i, 0, 0);
			for (int i = 1; i <= n; i++)
				cout << col[i] << " ";
			cout << endl;
			return 0;
		}

	return 0;
}