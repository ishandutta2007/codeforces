#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 500005;
int n, m, Q, u[MX], v[MX], w[MX], q[MX], p[MX], rk[MX], res[MX];
map<int, vi> mp[MX];
vi pos[MX];
stack<ii> sp, srk;

int parent (int a) {
	return a == p[a] ? a : parent(p[a]);
}

bool join (int u, int v) {
	u = parent(u), v = parent(v);
	if (u == v) return 0;

	if (rk[u] < rk[v]) swap(u, v);

	sp.emplace(v, p[v]);
	p[v] = u;

	if (rk[u] == rk[v]) {
		srk.emplace(u, rk[u]);
		rk[u]++;
	}

	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn(i, m) cin >> u[i] >> v[i] >> w[i];
	iota(q, q+m, 0);
	sort(q, q+m, [&] (int i, int j) {
		return w[i] < w[j];
	});

	cin >> Q;
	forn (i, Q) {
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			x--;

			mp[i][w[x]].pb(x);
			pos[w[x]].pb(i);
		}
		res[i] = 1;
	}

	iota(p, p+MX, 0);

	int ptr = 0;
	forn (i, MX) {
		sort(all(pos[i]));
		pos[i].erase(unique(all(pos[i])), pos[i].end());

		for (int j : pos[i]) {
			for (int e : mp[j][i])
				res[j] &= join(u[e], v[e]);

			while (sp.size()) {
				p[sp.top().fi] = sp.top().se;
				sp.pop();
			}

			while (srk.size()) {
				rk[srk.top().fi] = srk.top().se;
				srk.pop();
			}
		}

		while (ptr < m && w[q[ptr]] == i) {
			join(u[q[ptr]], v[q[ptr]]);
			ptr++;
		}

		while (sp.size()) sp.pop();
		while (srk.size()) srk.pop();
	}

	forn(i, Q) {
		if (res[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}