#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vii> vvii;

int n, m, x, y, w, s, cn, num;
vvii adj;
vi dn, dl, scc;
bitset<1000005> vis; 
stack<int> st;

void tarjan (int u) {
	dl[u] = dn[u] = ++cn;
	st.push(u);
	vis[u] = 1;

	for (ii &v : adj[u]) {
		if (!dn[v.fi])
			tarjan(v.fi);
		if (vis[v.fi])
			dl[u] = min(dl[u], dl[v.fi]);
	}

	if (dl[u] == dn[u]) {
		while (1) {
			int v = st.top();
			st.pop();
			vis[v] = 0;
			scc[v] = num;	
			if (u == v)
				break;
		}
		num++;
	}
}

vvii dag;
void obtDag () {
	vector<ll> suma(num+2), tri(1), acu(1);

	for (ll i = 1, x = 1; x <= 1e9; i++, x = i * (i+1) / 2) {
		tri.push_back(x);
		acu.push_back(acu[i-1] + x);
	}

	for (int u = 1; u <= n; u++) {
		if (scc[u] == -1)
			continue;

		for (ii &v : adj[u]) {
			if (scc[u] != scc[v.fi]) {
				dag[2*scc[u]+1].emplace_back(2*scc[v.fi], v.se);
			} else {
				ll x = upper_bound(tri.begin(), tri.end(), v.se) - tri.begin();
				suma[scc[u]] += x * v.se - acu[x-1];
			}
		}
	}

	for (int i = 0; i < num; i++) {
		dag[i*2].emplace_back(i*2+1, suma[i]);
	}
}

vector<ll> mx;
void dfs (int u) {
	mx[u] = 0;
	for (ii &v : dag[u]) {
		if (mx[v.fi] == -1)
			dfs(v.fi);
		mx[u] = max(mx[u], mx[v.fi] + v.se);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	adj = vvii(n+1);
	while (m--) {
		cin >> x >> y >> w;
		adj[x].emplace_back(y, w);
	}
	cin >> s;

	dn = vi(n+1), dl = vi(n+1), scc = vi(n+1, -1);
	cn = num = 0;
	tarjan (s);

	dag = vvii(2*num+5);
	obtDag();

	mx = vector<ll>(dag.size(), -1);
	dfs(2*scc[s]);
	cout << mx[2*scc[s]] << endl;

	return 0;
}