#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, int rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				trav(e, adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			assert(a[i][j] >= 2);
		}
	}
	vector<vector<int> > need(n, vector<int>(m, 0));
	vector<int> dx = {1, 0, -1, 0};
	vector<int> dy = {0, 1, 0, -1};
	string dirs = "DRUL";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int foundless = 0;
			int foundeq = 0;
			for(int d = 0; d < 4; d++){
				int ni = i + dx[d];
				int nj = j + dy[d];
				if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
				if(a[ni][nj] < a[i][j]) foundless = 1;
				if(a[ni][nj] == a[i][j]) foundeq = 1;
			}
			if(!foundless){
				if(!foundeq){
					cout << "NO" << '\n';
					return;
				} else {
					need[i][j] = 1;
				}
			}
		}
	}
	Dinic flow(n*m+4);
	int lc = 0, rc = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if((i + j) & 1){
				rc++;
				flow.addEdge(i*m+j, n*m+1, 1);
				if(!need[i][j]){
					flow.addEdge(n*m+2, i*m+j, 1);
				}
			} else {
				lc++;
				flow.addEdge(n*m, i*m+j, 1);
				if(!need[i][j]){
					flow.addEdge(i*m+j, n*m+3, 1);
				}
				for(int d = 0; d < 4; d++){
					int ni = i + dx[d];
					int nj = j + dy[d];
					if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
					if(a[ni][nj] == a[i][j]){
						flow.addEdge(i*m+j, ni*m+nj, 1);
					}
				}
			}
		}
	}
	flow.addEdge(n*m, n*m+2, rc);
	flow.addEdge(n*m+3, n*m+1, lc);
	flow.addEdge(n*m+2, n*m+3, rc+lc);
	int ans = flow.calc(n*m, n*m+1);
	if(ans != n*m){
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	vector<vector<int> > score(n, vector<int>(m, 0));
	vector<vector<char> > pd(n, vector<char>(m, 'a'));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(auto e : flow.adj[i*m+j]){
				if(e.to < n*m){
					int fl = e.flow();
					assert(fl == 0 || fl == 1);
					if(fl == 1){
						for(int d = 0; d < 4; d++){
							int ni = i + dx[d];
							int nj = j + dy[d];
							if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
							if(ni * m + nj == e.to){
								pd[i][j] = dirs[d];
								pd[ni][nj] = dirs[(d + 2) % 4];
								score[i][j] = 1;
								score[ni][nj] = a[i][j] - 1;
							}
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(score[i][j] > 0) continue;
			for(int d = 0; d < 4; d++){
				int ni = i + dx[d];
				int nj = j + dy[d];
				if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
				if(a[ni][nj] < a[i][j]){
					score[i][j] = a[i][j] - a[ni][nj];
					pd[i][j] = dirs[d];
				}
			}
			assert(score[i][j] > 0);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << score[i][j] << ' ';
		}
		cout << '\n';
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << pd[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}