#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 600005;
int n, cn, vis[MX];
ll a[MX], b[MX], c[MX], d[MX];
vi adj[MX];
vii res;
map<ii, int> mp;

int num (ll a, ll b, ll c, ll d) {
	ll x = a * d;
	ll y = b * c;
	ll g = __gcd(x, y);
	
	x /= g;
	y /= g;
	
	if (!mp.count(ii(x, y)))
		mp[ii(x, y)] = cn++;
	
	return mp[ii(x, y)];
}

void add (int u, int v) {
	adj[u].pb(v);
	adj[v].pb(u);
}

int dfs (int u) {
	vis[u] = 1;
	
 	if (u < n) {
		int ind = -1;
		
		for (int v : adj[u])
			if (!vis[v]) {
				int d = dfs(v);
				if (d != -1)
					ind = d;
			}
		
		if (ind == -1)
			return u;
		
		res.pb({u, ind});
		return -1;
	}
	
	vi w;
	
	for (int v : adj[u])
		if (!vis[v]) {
			int d = dfs(v);
			if (d != -1)
				w.pb(d);
		}
	
	for (int i = 0; i + 1 < (int)w.size(); i += 2)
		res.pb({w[i], w[i + 1]});
	
	if (w.size() & 1)
		return w.back();
	
	return -1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	cn = n;
	
	forn (i, n) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		add(i, num(a[i] + b[i], b[i], c[i], d[i]));
		add(i, num(a[i], b[i], c[i] + d[i], d[i]));
	}
	
	forn (i, n)
		if (!vis[i])
			dfs(i);
	
	cout << res.size() << endl;
	for (ii &r : res)
		cout << r.fi + 1 << " " << r.se + 1 << endl;
	
	return 0;
}