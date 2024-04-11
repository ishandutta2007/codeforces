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

const int MX = 100005;
int n, mod, u, v, w, sz[MX], pos[MX], neg[MX];
ll res = 0;
vii adj[MX];
bitset<MX> ex;
map<int, int> mp;

ll euler (ll a, ll b, ll& s, ll& t){
	ll q, r0 = a, r1 = b, ri, s0 = 1, s1 = 0, si, t0 = 0, t1 = 1, ti;
	while (r1) {
		q = r0 / r1;
		ri = r0 % r1, r0 = r1, r1 = ri;
		si = s0 - s1 * q, s0 = s1, s1 = si;
		ti = t0 - t1 * q, t0 = t1, t1 = ti;
	} 
	s = s0, t = t0;
	return r0;
}

void pre (int u, int p) {
	sz[u] = 1;
	for (ii &v : adj[u])
		if (v.fi != p) {
			pre(v.fi, u);
			sz[u] += sz[v.fi];
		}
}

void update (int u, int p, int s, int k, int lvl) {
	if (k == 1) mp[s]++;
	else mp[s]--;

	for (ii &v : adj[u])
		if (ex[v.fi] && v.fi != p)
			update(v.fi, u, (s + 1ll * v.se * pos[lvl]) % mod, k, lvl + 1);
}

void go (int u, int p, int s, int lvl) {
	int tar = -1ll * s * neg[lvl] % mod;
	if (tar < 0) tar += mod;

	if (mp.count(tar))
		res += mp[tar];

	for (ii &v : adj[u])
		if (ex[v.fi] && v.fi != p)
			go(v.fi, u, (10ll * s + v.se) % mod, lvl + 1);
}

void dec (int u) {
	int tam = 1, ind;

	for (ii &v : adj[u])
		if (ex[v.fi])
			tam += sz[v.fi];

	while (1) {
		ind = -1;

		for (ii &v : adj[u])
			if (ex[v.fi] && 2 * sz[v.fi] > tam)
				ind = v.fi;
		
		if (ind == -1) break;
		sz[u] = tam - sz[ind];
		u = ind;
	}

	mp.clear();
	for (ii &v : adj[u])
		if (ex[v.fi])
			update(v.fi, u, v.se % mod, 1, 1);
	res += mp[0];

	mp[0]++;
	for (ii &v : adj[u])
		if (ex[v.fi]) {
			update(v.fi, u, v.se % mod, -1, 1);
			go(v.fi, u, v.se, 1);
			update(v.fi, u, v.se % mod, 1, 1);
		}

	ex[u] = 0;

	for (ii &v : adj[u])
		if (ex[v.fi])
			dec(v.fi);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> mod;
	for (int i = 1; i < n; i++) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	pos[0] = neg[0] = 1;
	for (int i = 1; i < MX; i++) {
		pos[i] = pos[i-1] * 10ll % mod;

		ll s, t;
		euler(pos[i], mod, s, t);
		s %= mod;
		if (s < 0) s += mod;

		neg[i] = s;
		assert(mod == 1 || 1ll * pos[i] * neg[i] % mod == 1);
	}

	ex.set();
	pre(0, -1);
	dec(0); 

	cout << res << endl;

	return 0;
}