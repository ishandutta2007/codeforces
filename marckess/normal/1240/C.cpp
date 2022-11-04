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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 500005;
int n, k;
ll mem[MX][2];
vii adj[MX];

ll dp (int u, int f, int p = -1) {
	ll &res = mem[u][f];
	if (res != -1)
		return res;
	res = 0;

	vl c;
	for (ii &v : adj[u])
		if (v.fi != p) {
			ll x = dp(v.fi, 0, u);
			ll y = dp(v.fi, 1, u) + v.se;

			res += x;
			c.pb(y - x);
		}

	sort(all(c), greater<ll>());

	ll acu = res;
	for (int i = 0; i < min(k - f, (int)c.size()); i++) {
		acu += c[i];
		res = max(res, acu);
	}

	return res;
}

void solve () {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		mem[i][0] = mem[i][1] = -1;
		adj[i].clear();
	}

	for (int i = 1; i < n; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
	}

	cout << dp(1, 0) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}