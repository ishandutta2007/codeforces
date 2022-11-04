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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, res;
ll x, y;
vi adj[MX];

int dfs (int u, int p = -1) {
	int f = 0;
	for (int v : adj[u])
		if (v != p)
			f += dfs(v, u);
	res += min(f, 2);
	return f < 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x >> y;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	if (x > y) {
		if (n == 2) {
			cout << x << endl;
			return 0;
		}

		for (int i = 1; i <= n; i++)
			if (adj[i].size() == n - 1) {
				cout << y * (n - 2) + x << endl;
				return 0;
			}

		cout << y * (n - 1) << endl;
		return 0;
	}

	dfs(1);
	cout << y * (n - 1) - y * res + x * res << endl;

	return 0;
}