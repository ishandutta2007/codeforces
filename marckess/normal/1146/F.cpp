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

const int MX = 200005, mod = 998244353;
int n, p[MX];
ll dp[MX][2];
vi adj[MX];

ll dfs (int u, int f) {
	ll &res = dp[u][f];
	if (res != -1) return res;
	if (adj[u].empty()) return res = 1;
	ll cn[3] = {0};
	cn[0] = 1;
	for (int v : adj[u]) {
		ll x = dfs(v, 0);
		ll y = dfs(v, 1);
		cn[2] = (cn[2] * (x + y) % mod + cn[1] * y) % mod;
		cn[1] = (cn[1] * x + cn[0] * y) % mod;
		cn[0] = cn[0] * x % mod;
	}
	return res = f ? (cn[2] + cn[1]) % mod : (cn[0] + cn[2]) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	cout << dfs(1, 0) << endl;

	return 0;
}