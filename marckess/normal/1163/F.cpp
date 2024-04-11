#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 200005;
int n, m, q, u[MX], v[MX], w[MX], f[MX], ini[MX], fin[MX], o[MX], ex[MX];
ll ds[MX], dt[MX], dst;
vii adj[MX], as[MX], at[MX];

void dij (int s, ll dis[], vii a[]) {
	forn (i, MX) dis[i] = 1e18;
	dis[s] = 0;
	
	priority_queue<ii, vii, greater<ii>> pq;
	pq.emplace(0, s);
	
	while (pq.size()) {
		int u = pq.top().se;
		ll d = pq.top().fi;
		pq.pop();
		
		if (dis[u] < d) continue;
		
		for (ii &v : adj[u]) {
			ll p = d + w[v.se];
			
			if (dis[v.fi] > p) {
				dis[v.fi] = p;
				pq.emplace(p, v.fi);
			}
		}
	}
	
	for (int u = 1; u <= n; u++)
		for (ii &v : adj[u])
			if (dis[u] + w[v.se] == dis[v.fi])
				a[u].pb(v);
}

void go (ll dis[], vii adj[], int ini[], int sgn) {
	iota(o, o + n, 1);
	sort(o, o + n, [&] (int i, int j) {
		return dis[i] < dis[j];
	});
	
	forn (i, MX)
		if (f[i] == -1)
			ini[i] = sgn * 1e9;
	
	forn (_, n) {
		int u = o[_];
		
		for (ii &v : adj[u])
			if (f[v.fi] == -1)
				ini[v.fi] = sgn * min(sgn * ini[v.fi], sgn * ini[u]);
	}
}

ll mn[MX];
vector<ll> st[MX], en[MX];
multiset<ll> mst;

void insert (int a, int b, ll w) {
	if (a >= b) return;
	st[a].pb(w);
	en[b].pb(w);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		adj[u[i]].emplace_back(v[i], i);
		adj[v[i]].emplace_back(u[i], i);
	}
	
	dij(1, ds, as);
	dij(n, dt, at);
	dst = ds[n];
	
	memset(f, -1, sizeof(f));
	memset(ex, -1, sizeof(ex));
	
	for (int u = 1, i = 0;; i++) {
		f[u] = ini[u] = fin[u] = i;
		
		if (u == n) break;
		
		for (ii &v : adj[u])
			if (ds[u] + w[v.se] + dt[v.fi] == dst) {
				u = v.fi;
				ex[v.se] = i;
				break;
			}
	}
	
	go(ds, as, ini, 1);
	go(dt, at, fin, -1);
	
	for (int i = 1; i <= m; i++)
		if (ex[i] == -1) {
			insert(ini[u[i]], fin[v[i]], ds[u[i]] + w[i] + dt[v[i]]);
			insert(ini[v[i]], fin[u[i]], ds[v[i]] + w[i] + dt[u[i]]);
		}
	
	mst.insert(1e18);
	forn (i, MX) {
		for (ll k : st[i])
			mst.insert(k);
			
		for (ll k : en[i])
			mst.erase(mst.find(k));
			
		mn[i] = *mst.begin();
	}
	
	while (q--) {
		int t, x;
		cin >> t >> x;
		
		if (ex[t] == -1) {
			cout << min({
				dst,
				ds[u[t]] + x + dt[v[t]],
				ds[v[t]] + x + dt[u[t]]
			}) << endl;
		} else {
			cout << min({
				mn[ex[t]],
				ds[u[t]] + x + dt[v[t]],
				ds[v[t]] + x + dt[u[t]]
			}) << endl;
		}
	}
	
	return 0;
}