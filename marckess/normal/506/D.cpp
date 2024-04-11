#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;

struct DS {
	set<int> st;
	int p[MX], rk[MX];

	void init () {
		for (int i = 0; i < MX; i++) {
			p[i] = i;
			rk[i] = 0;
		}
	}

	void reset () {
		for (int x : st) {
			p[x] = x;
			rk[x] = 0;
		}
		st.clear();
	}

	int parent (int u) {
		return u == p[u] ? u : p[u] = parent(p[u]);
	}

	bool same (int u, int v) {
		return parent(u) == parent(v);
	}

	void joint (int u, int v) {
		st.insert(u), st.insert(v);
		u = parent(u), v = parent(v);

		if (rk[u] > rk[v]) {
			p[v] = u;
		} else {
			p[u] = v;
			if (rk[u] == rk[v])
				rk[v]++;
		}
	}
}ds;

int n, m, a[MX], b[MX], c[MX], u[MX], v[MX], res[MX], ant[MX];
vi que[MX];
set<int> gr[MX], ed[MX];
ll q;
map<ll, int> mp;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
	
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	cin >> a[i] >> b[i] >> c[i];

    	gr[a[i]].insert(c[i]);
    	gr[b[i]].insert(c[i]);
    	ed[c[i]].insert(i);
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
    	cin >> u[i] >> v[i];
    	if (gr[u[i]].size() > gr[v[i]].size())
    		swap(u[i], v[i]);

    	ll h = u[i] * q + v[i];
    	if (mp.find(h) == mp.end()) {
    		que[u[i]].push_back(i);
    		ant[i] = -1;
    		mp[h] = i;
    	} else {
    		ant[i] = mp[h];
    	}
    }

    ds.init();
    for (int i = 1; i <= m; i++) {
    	ds.reset();

    	for (int x : ed[i])
    		ds.joint(a[x], b[x]);

    	for (int x : ds.st)
    		for (int y : que[x])
    			if (ds.same(u[y], v[y]))
    				res[y]++;
    }

    for (int i = 0; i < q; i++) {
    	if (ant[i] != -1)
    		res[i] = res[ant[i]];
    	cout << res[i] << endl;
    }

    return 0;
}