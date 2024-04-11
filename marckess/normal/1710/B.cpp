#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, x[MX], p[MX], res[MX];
map<int, vi> r, pin, pde;
set<int> pos;
map<int, ll> a;

struct ST {
	ll mx[3 * 4 * MX];
	
	void build (int i, int j, int pos, vi &a) {
		if (i == j) {
			mx[pos] = a[i];
			return;
		}
		
		int m = (i + j) / 2;
		build(i, m, pos * 2, a);
		build(m + 1, j, pos * 2 + 1, a);
		
		mx[pos] = max(mx[pos * 2], mx[pos * 2 + 1]);
	}
	
	ll query (int i, int j, int pos, int a, int b) {
		if (a > b) return -1e18;
		
		if (b < i || j < a) return -1e18;
		
		if (a <= i && j <= b) return mx[pos];
		
		int m = (i + j) / 2;
		auto x = query(i, m, pos * 2, a, b);
		auto y = query(m + 1, j, pos * 2 + 1, a, b);
		
		return max(x, y);
	}
}izq, der, ori;

void main_() {
	cin >> n >> m;
	
	pos.clear();
	r.clear();
	pin.clear();
	pde.clear();
	a.clear();
	
	forn (i, n) {
		cin >> x[i] >> p[i];
		
		pos.insert(x[i] - p[i]);
		pos.insert(x[i]);
		pos.insert(x[i] + p[i]);
		
		pin[x[i] - p[i]].pb(i);
		r[x[i]].pb(i);
		pde[x[i] + p[i]].pb(i);
		
		res[i] = 1;
	}
	
	ll cnin = 0, cnde = 0;
	ll acu = 0, ant = -1e18;
	
	for (int i : pos) {
		acu += (i - ant) * cnin;
		acu -= (i - ant) * cnde;
		ant = i;
		
		a[i] = acu;
		
		cnin += pin[i].size();
		cnin -= r[i].size();
		
		cnde += r[i].size(); 
		cnde -= pde[i].size();
	}
	
	vi vizq(1), vder(1), vori(1), c;
	for (const auto &it : a) {
		vizq.pb(it.se - it.fi);
		vori.pb(it.se);
		vder.pb(it.se + it.fi);
		c.pb(it.fi);
	}
	
	int sz = a.size();
	izq.build(1, sz, 1, vizq);
	ori.build(1, sz, 1, vori);
	der.build(1, sz, 1, vder);
	
	forn (i, n) {
		int l = upper_bound(all(c), x[i] - p[i]) - c.begin();
		int j = upper_bound(all(c), x[i]) - c.begin();
		int r = upper_bound(all(c), x[i] + p[i]) - c.begin();
		
		if (l > 1) res[i] &= ori.query(1, sz, 1, 1, l - 1) <= m;
		res[i] &= izq.query(1, sz, 1, l, j) + x[i] - p[i] <= m;
		res[i] &= der.query(1, sz, 1, j, r) - x[i] - p[i] <= m;
		if (r < sz) res[i] &= ori.query(1, sz, 1, r + 1, sz) <= m;
	}
	
	forn (i, n) {
		cout << res[i];
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}