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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef vector<ll> vl;

const int MX = 200005;
int n, h[MX];
ll mem[MX][2], t[MX];
vi adj[MX];

ll dp (int u, int p, int f) {
	if (f == 0 && h[u] < h[p]) return 1e12;
	if (f == 1 && h[u] > h[p]) return 1e12;

	ll &res = mem[u][f], sum = 0;
	if (res != -1) return res;

	int x = f && u, y = !f && u;
	vl c;

	for (int v : adj[u])
		if (v != p) {
			sum += dp(v, u, 0);
			x++;
			c.pb(dp(v, u, 1) - dp(v, u, 0));
		}

	res = sum + max(x, y) * t[u];

	sort(all(c));

	forn (i, c.size()) {
		x--, y++;
		sum += c[i];
		res = min(res, sum + max(x, y) * t[u]);
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	forn (i, n) cin >> t[i];
	forn (i, n) cin >> h[i];

	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0, 0) << endl;

	return 0;
}