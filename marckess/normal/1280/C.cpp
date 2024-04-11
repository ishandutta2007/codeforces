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

const int MX = 200005;
int k, a[MX], sz[MX];
ll res;
vii adj[MX];

int dp (int u, int p) {
	int f = 1;

	for (ii v : adj[u])
		if (v.fi != p) {
			if (dp(v.fi, u)) {
				res += v.se;
				f ^= 1;
			}
		}

	return f;
}

ll dfs (int u, int p) {
	ll res = 0;
	sz[u] = 1;

	for (ii &v : adj[u])
		if (v.fi != p) {
			res += dfs(v.fi, u) + 1ll * v.se * min(sz[v.fi], 2 * k - sz[v.fi]);
			sz[u] += sz[v.fi];
		}

	return res;
}

void solve () {
	cin >> k;

	for (int i = 1; i <= 2 * k; i++) {
		//mem[i][0] = mem[i][1] = -1;
		adj[i].clear();
	}

	for (int i = 1; i < 2 * k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	res = 0;
	dp(1, 1);
	cout << res << " " << dfs(1, 1) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}