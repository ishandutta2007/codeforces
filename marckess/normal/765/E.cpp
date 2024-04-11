#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, u, v, d[MX], p[MX], acu[MX], sz[MX];
vi adj[MX];
bitset<MX> ex, vis;
set<int> st[MX];
queue<int> q;

int md = 0;
int mx () {
	while (md > 0 && !acu[md]) md--;
	return md;
}

int div2 (int n) {
	while (n % 2 == 0) n /= 2;
	return n;
}

void dec (int u, int k) {
	acu[d[u]]--;
	d[u] -= k;
	acu[d[u]]++;
}

void eli (int u) {
	while (d[u]) {
		dec(u, d[u]);
		ex[u] = 0;
		u = p[u];
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1; i <= n; i++) {
		d[i] = adj[i].size();
		acu[d[i]]++;
		md = max(md, d[i]);

		if (d[i] == 1) {
			q.push(i);
			p[i] = i;
			vis[i] = 1;
			sz[i] = 1;
		}

		ex[i] = 1;
	}

	if (mx() <= 2) {
		cout << div2(n-1) << endl;
		return 0;
	}

	while (q.size() && mx() > 2) {
		int u = q.front(), v = -1;
		q.pop();

		for (int w : adj[u]) if (!vis[w]) v = w;
		if (v == -1) continue;

		if (d[v] > 2) {
			if (st[v].count(sz[u])) {
				eli(u);
				dec(v, 1);
			} else {
				st[v].insert(sz[u]);
				p[v] = u;
			}
		}

		if (d[v] <= 2) {
			q.push(v);
			if (!p[v]) p[v] = u;
			vis[v] = 1;
			sz[v] = sz[u] + 1;
		}
	}

	if (mx() <= 2) cout << div2(ex.count()-1) << endl;
	else cout << -1 << endl;

	return 0;
}