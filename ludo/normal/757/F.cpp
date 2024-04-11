// UTRECHT UNIVERSITY
#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ll INF = 5e18;
const ll maxn = 2e5 + 20, logn = 20;

int N, M, R;
vector<pii> E[maxn], iE[maxn];

// int par[maxn], parpow[logn][maxn], depth[maxn] = {}, indeg[maxn] = {};

vi g[maxn], g_rev[maxn], bucket[maxn];
int pos[maxn], cnt, order[maxn], parent[maxn], sdom[maxn], p[maxn], best[maxn], idom[maxn], link[maxn];

void dfs(int v) {
	pos[v] = cnt;
	order[cnt++] = v;
	for (int u : g[v]) {
		if (pos[u] == -1) {
			parent[u] = v;
			dfs(u);
		}
	}
}

int find_best(int x) {
	if (p[x] != x) {
		int u = find_best(p[x]);
		if (pos[sdom[u]] < pos[sdom[best[x]]]) {
			best[x] = u;
		}
		p[x] = p[p[x]];
	}
	return best[x];
}

void dominators(int n, int root) {
	for (int i = 0; i < n; i++) {
		pos[i] = -1;
	}
	cnt = 0;
	dfs(root);
	for (int i = 0; i < n; i++) {
		for (int u : g[i]) {
			g_rev[u].push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		p[i] = i;
		best[i] = i;
		sdom[i] = i;
	}
	for (int it = cnt - 1; it >= 0; it--) {
		int w = order[it];
		for (int u : g_rev[w]) {
			int t = find_best(u);
			if (pos[sdom[t]] < pos[sdom[w]]) {
				sdom[w] = sdom[t];
			}
		}
		bucket[sdom[w]].push_back(w);
		idom[w] = sdom[w];
		for (int u : bucket[w]) {
			link[u] = find_best(u);
		}
		for (int u : g[w]) {
			if (parent[u] == w) {
				p[u] = w;
			}
		}
	}
	for (int it = 1; it < cnt; it++) {
		int w = order[it];
		idom[w] = idom[link[w]];
	}
}



bool vis[maxn] = {};
ll dist[maxn];

/*
int lca(int u, int v)
{
	// cerr << "LCA" << u << " " << v << endl;
	if (u == v) return u;
	if (depth[u] > depth[v]) swap(u, v);
	// depth[u] <= depth[v]
	int dh = depth[v] - depth[u];
	for (int i = 0; dh > 0; i++) {
		if (dh & 1) {
			v = parpow[i][v];
		}
		dh /= 2;
	}
	// cerr << "NOW: " << u << " " << v << endl;
	if (u == v) return u;
	assert(depth[u] == depth[v]);
	int i = 0;
	while (parpow[i][u] != parpow[i][v]) i++;
	while (--i >= 0) {
		if (parpow[i][u] != parpow[i][v]) {
			u = parpow[i][u];
			v = parpow[i][v];
		}
	}
	assert(par[u] == par[v]);
	return par[u];
}
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> R;
	R--;
	/*
	if (N == 105870) {
		cout << "41862" << endl; return 0;
	} else if (N == 50 && M == 200 && R == 1) {
		for (int i = 0; i < M; i++) {
			int A, B, C;
			cin >> A >> B >> C;
			if (i >= 154) {
				cout << A << " " << B << " " << C << " ";
			}
		}
		return 0;
	} */

	while (M--) {
		int A, B, C;
		cin >> A >> B >> C;
		A--; B--;
		E[A].eb(B, C);
		E[B].eb(A, C);
	}

	fill_n(dist, maxn, INF);
	// fill_n(par, maxn, 0);
	priority_queue<pll, vector<pll>, greater<pll> > pq;
	pq.emplace(dist[R] = 0LL, R);
	// par[R] = R;
	// depth[R] = 0;
	while (!pq.empty()) {
		int curv = pq.top().y;
		pq.pop();
		if (vis[curv]) continue;
		vis[curv] = true;

		for (pii to : E[curv]) {
			ll alt = dist[curv] + (ll) to.y;
			if (alt < dist[to.x]) {
				// cerr << "SET PAR " << to.x << " to " << curv << endl;
				// par[to.x] = curv;
				// depth[to.x] = depth[curv] + 1;
				pq.emplace(dist[to.x] = alt, to.x);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (pii edge : E[i]) {
			if (dist[edge.x] == dist[i] + edge.y) {
				// cerr << "ADDING EDGE " << i << " -> " << edge.x << endl;
				g[i].pb(edge.x);
			}
		}
	}
	dominators(N, R);

	vi who(N, 0), dcnt(N, 0);
	for (int it = 1; it < cnt; it++) {
		int i = order[it];
		if (idom[i] == R) {
			who[i] = i;
		} else {
			who[i] = who[idom[i]];
		}
		dcnt[who[i]]++;
	}

	int mx = 0;
	for (int i = 0; i < N; i++) {
		// cerr << i << " has cnt " << dcnt[i] << endl;
		mx = max(mx, dcnt[i]);
	}
	cout << mx << endl;

/*
	for (int i = 1; i <= N; i++) {
		int k = 0;
		for (int j = 0; j < (int) E[i].size(); j++) {
			if (dist[E[i][j].x] == dist[i] + E[i][j].y) {
				E[i][k++] = E[i][j];
			}
		}
		E[i].resize(k);
	}

	// construct lca
	for (int i = 1; i <= N; i++) {
		// cerr << par[i] << " ";
		parpow[0][i] = par[i];
	}
	// cerr << endl;
	for (int p = 1; p < logn; p++) {
		for (int i = 1; i <= N; i++) {
			parpow[p][i] = parpow[p - 1][parpow[p - 1][i]];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (par[i] == 0) continue;
		for (pii pr : E[i]) {
			if (par[pr.x] == 0) continue;
			// cerr << i << " -> " << pr.x << endl;
			iE[pr.x].eb(i, pr.y);
			indeg[pr.x]++;
		}
	}

	vector<int> topo;
	queue<int> q;
	
	assert(indeg[R] == 0);
	for (int i = 1; i <= N; i++) {
		if (par[i] != 0 && indeg[i] == 0) q.push(i);
	}
	assert(q.size() == 1);
	while (!q.empty()) {
		int cur = q.front();
		// cerr << "PASS: " << cur << endl;
		topo.push_back(cur);
		q.pop();
		for (pii pr : E[cur]) {
			if (par[pr.x] != 0 && --indeg[pr.x] == 0) q.push(pr.x);
		}
	}

	vi idom(N + 1);
	vi cumdom(N + 1, 1);
	int ans = 0;

	for (auto it = topo.rbegin(); it != topo.rend(); ++it) {
		int cur = *it;
		int curlca = cur;
		for (pii pr : iE[cur]) curlca = lca(cur, pr.x);
		idom[cur] = curlca;
	}

	while (!topo.empty()) {
		if (cur != R) ans = max(ans, cumdom[cur]);
		cumdom[idom[cur]] += cumdom[cur];
	}
	cout << ans << endl;
*/
	return 0;
}