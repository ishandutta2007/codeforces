#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, mod = 998244353, LG = 20;
int n, m, dis[LG][MX];
ii dist[2][MX];
ll res;
vi adj[MX], rev[MX];

void bfs (int in) {
	dis[in][1] = 0;
	queue<int> qu, qj;
	qu.push(1);
	qj.push(in);
	
	while (qu.size()) {
		int u = qu.front(); qu.pop();
		int j = qj.front(); qj.pop();
		
		vi &a = (in - j) % 2 == 0 ? adj[u] : rev[u];
		vi &b = (in - j) % 2 == 0 ? rev[u] : adj[u];
		
		for (int v : a)
			if (dis[j][v] == -1) {
				dis[j][v] = dis[j][u] + 1;
				qu.push(v);
				qj.push(j);
			}
		
		if (j) {
			for (int v : b)
				if (dis[j - 1][v] == -1) {
					dis[j - 1][v] = dis[j][u] + 1;
					qu.push(v);
					qj.push(j - 1);
				}
		}
	}
}

typedef pair<ii, int> iii;

void dij () {
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.emplace(ii(0, 0), 1);
	dist[0][1] = {0, 0};
	
	while (pq.size()) {
		int j = pq.top().fi.fi;
		int w = pq.top().fi.se;
		int u = pq.top().se;
		pq.pop();
		
		if (dist[j & 1][u] < ii(j, w)) continue;
		
		vi &a = (j & 1) == 0 ? adj[u] : rev[u];
		vi &b = (j & 1) == 0 ? rev[u] : adj[u];
		
		ii vec(j, w + 1);
		for (int v : a)
			if (dist[j & 1][v].fi == -1 || dist[j & 1][v] > vec) {
				dist[j & 1][v] = vec;
				pq.emplace(vec, v);
			}
		
		vec = ii(j + 1, w + 1);
		for (int v : b)
			if (dist[1 - (j & 1)][v].fi == -1 || dist[1 - (j & 1)][v] > vec) {
				dist[1 - (j & 1)][v] = vec;
				pq.emplace(vec, v);
			}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		rev[v].pb(u);
	}
	
	res = 1e9;
	
	forn (j, LG) {
		memset(dis, -1, sizeof(dis));
		bfs(j);
		if (dis[0][n] != -1)
			res = min(res, dis[0][n] + (1ll << j) - 1);
	}
	
	if (res == int(1e9)) {
		for (int i = 1; i <= n; i++) {
			dist[0][i] = {-1, -1};
			dist[1][i] = {-1, -1};
		}
			
		dij();
		
		ii d = dist[0][n];
		if (d.fi == -1 || (dist[1][n].fi != -1 && dist[1][n] < d))
			d = dist[1][n];
		
		ll p = 1;
		for (int i = 1; i <= d.fi; i++)
			(p *= 2) %= mod;
		p--;
		
		res = (p + d.se + mod) % mod;
	}
	
	cout << res << endl;
	
	return 0;
}