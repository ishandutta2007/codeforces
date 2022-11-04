#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define eb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
 
const int MX = 200005, SQ = 185;
 
bool leq (ld a, ld b, ld c, ld d) {
	return a / b <= c / d;
}
 
struct CHT {
	ll m[2*SQ+5], y[2*SQ+5];
	int s, i;
 
	CHT () : s(0), i(0) {}
 
	void insert (ll a, ll b) {
		if (s > 0 && a == m[s - 1] && b <= y[s - 1]) return;
		while (s > 0 && a == m[s - 1] && b > y[s - 1]) s--;
		while (s >= 2) {
			if (leq(y[s - 1] - b, a - m[s - 1], y[s - 2] - y[s - 1], m[s - 1] - m[s - 2]))
				s--;
			else break;
		}
		m[s] = a, y[s] = b;
		s++;
	}
 
	ll query (ll x) {
		while (i + 1 < s && m[i + 1] * x + y[i + 1] >= m[i] * x + y[i]) i++;
		return m[i] * x + y[i];
	}
};
 
struct Block {
	int l, r, sz;
	ll off;
	vl m, y;
	vi q;
	CHT h;
 
	Block (int l, int r) : l(l), r(r), sz(r - l + 1), m(r - l + 1), y(r - l + 1), q(2 * (r - l + 1)), off(0) {
		iota(all(q), 0);
	}
 
	void sort_block () {
		sort(all(q), [&] (int i, int j) {
			return ((i & 1) ? -m[i / 2] : m[i / 2]) < ((j & 1) ? -m[j / 2] : m[j / 2]);
		});
	}
 
	void build() {
		for (int i = 0; i < sz; i++)
			y[i] += off * m[i];
		off = 0;
		h.s = h.i = 0;
 
		for (int i = 0; i < 2 * sz; i++) {
			int u = q[i];
			if (u & 1) h.insert(-m[u / 2], -y[u / 2]);
			else h.insert(m[u / 2], y[u / 2]);
		}
	}
 
	void update (int i, int j, ll k) {
		if (j < l || r < i) return;
		if (i <= l && r <= j) off += k;
		else {
			for (int t = 0; t < sz; t++)
				if (i <= l + t && l + t <= j)
					y[t] += k * m[t];
			build();
		}
	}
 
	ll query (int i, int j) {
		if (j < l || r < i) return 0;
		if (i <= l && r <= j) return h.query(off);
	
		ll mx = 0;
		for (int t = 0; t < sz; t++)
			if (i <= l + t && l + t <= j)
				mx = max(mx, abs(y[t] + off * m[t]));
		return mx;
	}
};
 
int n, q, u, v, p[MX], a[MX], b[MX], cn, ini[MX], fin[MX];
ll sa = 0, sb = 0, m[MX], y[MX];
vi adj[MX];
vector<Block> blo;
 
void dfs (int u) {
	ini[u] = ++cn, sa += a[u], sb += b[u];
	m[ini[u]] = abs(sb), y[ini[u]] = sa * abs(sb);
	for (int v : adj[u])
		dfs(v);
	fin[u] = cn;
	sa -= a[u], sb -= b[u];
}
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> q;
 
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].eb(i);
	}
 
	forn(i, n) cin >> a[i+1];
	forn(i, n) cin >> b[i+1];
	dfs(1);
 
	for (int i = 0; i * SQ <= n + 1; i++) {
		int l = max(1, i * SQ);
		int r = min((i + 1) * SQ - 1, n);
		blo.eb(l, r);
		for (int k = l; k <= r; k++) 
			blo[i].m[k - l] = m[k], blo[i].y[k - l] = y[k];
		blo[i].sort_block();
		blo[i].build();
	}
 
	while (q--) {
		int op, x, k;
		cin >> op >> x;
		if (op == 1) {
			cin >> k;
			for (auto &b : blo)
				b.update(ini[x], fin[x], k);
		} else {
			ll res = 0;
			for (auto &b : blo)
				res = max(res, b.query(ini[x], fin[x]));
			cout << res << endl;
		}
	}
 
	return 0;
}