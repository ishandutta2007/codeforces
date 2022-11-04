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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 205;
int n, m, dis[MX];
vi to[MX], rev[MX], adj[MX];

int dij (int ini) {
	memset(dis, -1, sizeof(dis));
	dis[ini] = 0;
	
	priority_queue<ii, vii, greater<ii>> pq;
	pq.emplace(0, ini);
	
	while (pq.size()) {
		int u = pq.top().se;
		int d = pq.top().fi;
		pq.pop();
		
		if (d == -1) return -1;
		
		if (dis[u] < d) continue;
		
		for (int v : to[u]) {
			int w = dis[u] + 1;
			if (dis[v] == -1 || dis[v] > w) {
				dis[v] = w;
				pq.emplace(w, v);
			}
		}
		
		for (int v : rev[u]) {
			int w = dis[u] - 1;
			if (dis[v] == -1 || dis[v] > w) {
				dis[v] = w;
				pq.emplace(w, v);
			}
		}
		
		for (int v : adj[u]) {
			int w = dis[u] + 1;
			if (dis[v] == -1 || dis[v] > w) {
				dis[v] = w;
				pq.emplace(w, v);
			}
		}
	}
	
	int mx = 0;
	for (int u = 1; u <= n; u++) {
		mx = max(mx, dis[u]);
		
		for (int v : to[u])
			if (dis[v] != dis[u] + 1)
				return -1;
		
		for (int v : adj[u])
			if (abs(dis[v] - dis[u]) != 1)
				return -1;
	}
	
	return mx;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	forn (i, m) {
		int u, v, b;
		cin >> u >> v >> b;
		if (b) {
			to[u].pb(v);
			rev[v].pb(u);
		} else {
			adj[u].pb(v);
			adj[v].pb(u);
		}
	}
	
	int mx = -1, ind = -1;
	for (int i = 1; i <= n; i++) {
		int d = dij(i);
		if (d > mx) {
			mx = d;
			ind = i;
		}
	}
	
	if (ind == -1) {
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	cout << mx << endl;
	dij(ind);
	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
	cout << endl;
		
	return 0;
}