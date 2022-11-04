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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
const ll inf = 1e18;
int n, p[MX], f;
ll a[MX];
vi adj[MX];

ll dfs (int u, ll m) {
	if (!adj[u].size()) {
		if (a[u] > m) f = 0;
		return m - a[u];
	}
	
	ll x = 0;
	for (int v : adj[u]) {
		x += dfs(v, m);
		if (x > inf)
		x = inf;
	}
	
	if (x < a[u]) f = 0;
	return x - a[u];
}

void solve () {
	cin >> n;
	
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	ll i = 0, j = 1e15, rep = 52;
	
	while (rep--) {
		ll m = (i + j) / 2;
		f = 1;
		dfs(1, m);
		if (f) j = m;
		else i = m;
	}
	
	cout << j << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}