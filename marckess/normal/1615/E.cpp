// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;

struct ST {
	ii mx[4 * MX];
	int lz[4 * MX];
	
	void build (int i, int j, int pos) {
		mx[pos] = {0, i};
		lz[pos] = 0;
		
		if (i < j) {
			int m = (i + j) / 2;
			build(i, m, pos * 2);
			build(m + 1, j, pos * 2 + 1);
		}
	}
	
	void push (int i, int j, int pos) {
		if (i < j) {
			lz[pos * 2] += lz[pos];
			lz[pos * 2 + 1] += lz[pos];
		}
		
		mx[pos].fi += lz[pos];
		lz[pos] = 0;
	}
	
	void update (int i, int j, int pos, int a, int b, ll k) {
		if (lz[pos]) push(i, j, pos);
		
		if (b < i || j < a) return;
		
		if (a <= i && j <= b) {
			lz[pos] = k;
			push(i, j, pos);
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, b, k);
		update(m + 1, j, pos * 2 + 1, a, b, k);
		
		mx[pos] = max(mx[pos * 2], mx[pos * 2 + 1]);
	}
	
	ii query (int i, int j, int pos, int a, int b) {
		if (lz[pos]) push(i, j, pos);
		
		if (b < i || j < a) return {-1e9, -1e9};
		
		if (a <= i && j <= b) return mx[pos];
		
		int m = (i + j) / 2;
		ii x = query(i, m, pos * 2, a, b);
		ii y = query(m + 1, j, pos * 2 + 1, a, b);
		
		return max(x, y);
	}
}st;

int n, k, p[MX], ini[MX], fin[MX], f[MX], cn, ex[MX];
vi adj[MX];

void dfs (int u) {
	ini[u] = ++cn;
	f[cn] = u;
	
	for (int v : adj[u])
		if (v != p[u]) {
			p[v] = u;
			dfs(v);
		}
	
	fin[u] = cn;
	st.update(1, n, 1, ini[u], fin[u], 1);
}

ll g (ll w, ll t, ll R) {
	ll l = 0, r = t;
	
	while (abs(r - l) > 5) {
		ll b1 = l + (r - l + 1) / 3;
		ll b2 = l + 2 * (r - l + 1) / 3;
		
		ll x1 = (w + (t - b1)) * (R - b1);
		ll x2 = (w + (t - b2)) * (R - b2);
		
		if (x1 == x2) {
			l = b1, r = b2;
		} else if (x1 < x2) {
			r = b2;
		} else {
			l = b1;
		}
	} 
	
	ll res = (w + (t - l)) * (R - l);
	for (int b = l; b <= r; b++)
		res = min(res, (w + (t - b)) * (R - b));
	return res;
}

void main_() {
	cin >> n >> k;
	
	st.build(1, n, 1);
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	p[1] = -1;
	dfs(1);
	
	ll res = g(0, n, 0), w = 0;
	
	for (int r = 1; r <= k; r++) {
		int u, d;
		tie(d, u) = st.mx[1];
		u = f[u];
		
		w += d - 1;
		res = max(res, g(w, n - w - r, r));
		
		while (u != -1 && !ex[u]) {
			ex[u] = 1;
			st.update(1, n, 1, ini[u], fin[u], -1);
			u = p[u];
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}