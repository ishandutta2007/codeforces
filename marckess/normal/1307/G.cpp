#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 55;

struct Edge {
	int to, f, u, c;
	Edge *rev;

	Edge (int to, int u, int c) : to(to), f(0), u(u), c(c) {}
};

int n, m, q, mx;
ll dis[MX], res[MX];
vector<Edge*> adj[MX], from(MX);

void add (int u, int v, int w) {
	Edge *uv = new Edge(v, 1, w);
	Edge *vu = new Edge(u, 0, -w);

	uv->rev = vu;
	vu->rev = uv;

	adj[u].pb(uv);
	adj[v].pb(vu); 
}

void dijkstra (int s) {
	priority_queue<ii, vii, greater<ii>> pq;
	memset(dis, -1, sizeof(dis));
	
	dis[s] = 0;
	pq.emplace(0, s);

	while (pq.size()) {
		int u = pq.top().se;
		ll d = pq.top().fi;
		pq.pop();

		if (d > dis[u]) continue;

		for (Edge *e : adj[u])
			if (e->f < e->u) {
				int v = e->to;
				ll w = d + e->c;

				if (dis[v] == -1 || dis[v] > w) {
					dis[v] = w;
					from[v] = e->rev;
					pq.emplace(w, v);
				}
			}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(8);

	cin >> n >> m;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}

	while (1) {
		dijkstra(1);

		if (dis[n] == -1) break;
		
		mx++;
		res[mx] = dis[n] + res[mx - 1];

		int v = n;
		while (v != 1) {
			Edge *e = from[v];
			
			e->f--;
			e->rev->f++;

			v = e->to;
		}
	}

	cin >> q;
	while (q--) {
		ld mn = 1e18;
		int x;
		cin >> x;

		for (int i = 1; i <= mx; i++)
			mn = min(mn, ld(res[i] + x) / i);
		cout << mn << endl;
	}

	return 0;
}