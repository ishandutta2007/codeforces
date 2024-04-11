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

const int MX = 200005, mod = 998244353;
int n;
ll dp[MX][3];
vi adj[MX];

void dfs (int u, int p) {
	for (int v : adj[u])
		if (v != p)
			dfs(v, u);

	dp[u][1] = 1;
	for (int v : adj[u])
		if (v != p)
			(dp[u][1] *= dp[v][0]) %= mod;
	dp[u][2] = dp[u][1];

	vi c;
	vl izq, der;
	for (int v : adj[u])
		if (v != p)
			izq.pb(dp[v][0]), der.pb(dp[v][1]), c.pb(v);

	int ind = 0;
	for (int v : adj[u]) {
		if (v == p) break;
		ind++;
	}

	for (int i = 1; i < izq.size(); i++)
		(izq[i] *= izq[i-1]) %= mod;

	for (int i = int(der.size()) - 2; i >= 0; i--)
		(der[i] *= der[i+1]) %= mod;

	for (int i = 0; i < c.size(); i++) {
		ll p = dp[c[i]][2];
		if (i) (p *= izq[i-1]) %= mod;
		if (i + 1 < der.size()) (p *= der[i+1]) %= mod;
		
		dp[u][1] += p;
		if (i < ind) dp[u][0] += p;
		else dp[u][2] += p;
	}

	{
		ll p = 1;
		if (ind) (p *= izq[ind-1]) %= mod;
		if (ind < der.size()) (p *= der[ind]) %= mod;
		dp[u][0] += p;
	}

	dp[u][0] %= mod;
	dp[u][1] %= mod;
	dp[u][2] %= mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(1, 1);
	cout << dp[1][1] << endl;

	return 0;
}