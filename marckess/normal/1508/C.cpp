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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, p[MX], rk[MX], acu;
vvi ed;
set<int> adj[MX];

void init () {
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		rk[i] = 0;
	}
}

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

bool join (int a, int b) {
	a = parent(a), b = parent(b);
	
	if (a == b) return 0;
	
	if (rk[a] < rk[b]) swap(a, b);
	if (rk[a] == rk[b]) rk[a]++;
	
	p[b] = a;
	return 1;
}

void all0 () {
	set<int> st;
	for (int i = 1; i <= n; i++)
		st.insert(i);
	init();
	
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (st.count(i)) {
			st.erase(i);
			q.push(i);
			
			while (q.size()) {
				int u = q.front();
				q.pop();
				
				vi vn;
				for (int v : st)
					if (!adj[u].count(v)) {
						join(u, v);
						vn.pb(v);
					}
				
				for (int v : vn) {
					st.erase(v);
					q.push(v);
				}
			}
		}
	
	ll res = 0;
	for (vi &e : ed)
		if (join(e[1], e[2]))
			res += e[0];
	cout << res << endl;
}

void someAcu() {
	vii st;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (!adj[i].count(j))
				st.emplace_back(i, j);
	
	init();
	vvi si;
	for (vi &e : ed)
		if (join(e[1], e[2]))
			si.pb(e);

	ll res = 1e18;
	for (auto &e : st) {
		init();
		
		for (auto &f : st)
			if (e != f)
				join(f.fi, f.se);
		
		ll p = 0;
		for (auto &f : si)
			if (f[0] <= acu)
				if (join(f[1], f[2]))
					p += f[0];
		
		if (join(e.fi, e.se))
			p += acu;
		
		for (auto &f : si)
			if (f[0] >= acu)
				if (join(f[1], f[2]))
					p += f[0];
		
		res = min(res, p);
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		
		adj[u].insert(v);
		adj[v].insert(u);
		ed.pb({w, u, v});
		
		acu ^= w;
	}
	
	sort(all(ed));
	
	if (1ll * n * (n - 1) / 2 - m >= n) all0();
	else someAcu();
	
	return 0;
}