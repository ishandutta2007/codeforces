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

const int MX = 100005;

struct flowGraph{
	struct Edge {
		int to, flow, cap;
		Edge *res;
	
		Edge (int to, int flow, int cap) : to(to), flow(flow), cap(cap), res(NULL) {}
	
		void add (int flow) {
			this->flow += flow;
			this->res->flow -= flow;
		}
	};
	
	int inf = numeric_limits<int>::max(), V;
	vector<vector<Edge*>> adj;
	vi dist, pos;
	
	flowGraph(int V): V(V), adj(V), dist(V), pos(V){}
	
	void add (int u, int v, int cap) {
		auto *uv = new Edge(v, 0, cap);
		auto *vu = new Edge(u, 0, 0);
		
		uv->res = vu;
		vu->res = uv;
		
		adj[u].pb(uv);
		adj[v].pb(vu);
	}

	int dfs (int u, int t, int flow) {
		if (u == t) return flow;
		
		for (int &i = pos[u]; i < adj[u].size(); i++) {
			auto *v = adj[u][i];
			
			if (v->cap > v->flow && dist[u] + 1 == dist[v->to]) {
				int fv = dfs (v->to, t, min(flow, v->cap - v->flow));
				
				if (fv) {
					v->add(fv);
					return fv;
				}
			}
		}
		
		return 0;
	}
	
	int dinic (int s, int t) {
		int maxFlow = 0;
		dist[t] = 0;
		
		while (dist[t] != -1) {
			fill(dist.begin(), dist.end(), -1);
			queue<int> Q;
			Q.push(s);
			dist[s] = 0;
			
			while (!Q.empty()) {
				int u = Q.front(); Q.pop();
				
				for (auto *v : adj[u]) {
					if (dist[v->to] == -1 && v->flow != v->cap) {
						dist[v->to] = dist[u] + 1;
						Q.push(v->to);
					}
				}
			}
			
			if (dist[t] != -1) {
				int f;
				fill(pos.begin(), pos.end(), 0);
				
				while(f = dfs(s, t, inf))
					maxFlow += f;
			}
		}
		
		return maxFlow;
	}
};

int n, m, in[MX], out[MX];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
char dir[] = {'D', 'U', 'R', 'L'};
vvi a;
flowGraph *g;

inline int num (int i, int j) {
	return i * m + j;
}

void solve () {
	cin >> n >> m;
	
	a = vvi(n, vi(m));
	
	forn (i, n) forn (j, m) cin >> a[i][j];
	
	int s = n * m, t = s + 1, ss = t + 1, tt = ss + 1, sd = 0;
	
	g = new flowGraph(tt + 1);
	forn (i, tt) in[i] = out[i] = 0;
	
	forn (i, n) forn (j, m) {
		int f = 0;
		
		#define vc(comp, op) forn (l, 4) { \
			int x = i + mx[l]; \
			int y = j + my[l]; \
			if (0 <= x && x < n && 0 <= y && y < m && a[i][j] comp a[x][y]) { \
				op \
			} \
		} \
		
		vc(>, f = 1; )
		
		if (!f) {
			vc(==,
				int u = num(i, j);
				int v = num(x, y);
				if (i % 2 != j % 2) swap(u, v);
				g->add(u, v, 1);
			)
		}
		
		if (i % 2 == j % 2) {
			if (f) g->add(s, num(i, j), 1);
			else out[s]++, in[num(i, j)]++;
		} else {
			if (f) g->add(num(i, j), t, 1);
			else out[num(i, j)]++, in[t]++;
		}
	}
	
	forn (i, tt) {
		sd += in[i];
		if (in[i]) g->add(ss, i, in[i]);
		if (out[i]) g->add(i, tt, out[i]);
	}
	
	g->add(t, s, g->inf);
	
	if (g->dinic(ss, tt) == sd) {
		cout << "YES" << endl;
		
		forn (i, n) {
			forn (j, m) {
				int f = 0;
				
				for (auto *e : g->adj[num(i, j)])
					if (e->to < n * m && e->flow) {
						if (i % 2 == j % 2) cout << a[i][j] - 1;
						else cout << 1;
						f = 1;
					}
				
				if (!f) vc(>, cout << a[i][j] - a[x][y]; break; )
				
				cout << " ";
			}
			
			cout << endl;
		}
		
		forn (i, n) {
			forn (j, m) {	
				int f = 0;
				
				for (auto *e : g->adj[num(i, j)])
					if (e->to < n * m && e->flow) {
						int u = num(i, j);
						int v = e->to;
						
						if (u - m == v) cout << 'U';
						else if (u + m == v) cout << 'D';
						else if (u + 1 == v) cout << 'R';
						else cout << 'L';
						f = 1;
					}
				
				if (!f) vc(>, cout << dir[l]; break; )
				
				cout << " ";
			}
			
			cout << endl;
		}
	} else {
		cout << "NO" << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 	
	int t;
	cin >> t;
	while (t--)
		solve(); 	

	return 0;
}