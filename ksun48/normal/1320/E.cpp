#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;

	RMQ(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < sz(V)) on *= 2, depth++;
		jmp.assign(depth, V);
		rep(i,0,depth-1) rep(j,0,N)
			jmp[i+1][j] = min(jmp[i][j],
			jmp[i][min(N - 1, j + (1 << i))]);
	}

	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

typedef vector<pii> vpi;
typedef vector<vpi> graph;

struct LCA {
	vi time;
	vector<ll> dist;
	RMQ<pii> rmq;

	LCA(graph& C) : time(sz(C), -99), dist(sz(C)), rmq(dfs(C)) {}

	vpi dfs(graph& C) {
		vector<tuple<int, int, int, ll>> q(1);
		vpi ret;
		int T = 0, v, p, d; ll di;
		while (!q.empty()) {
			tie(v, p, d, di) = q.back();
			q.pop_back();
			if (d) ret.emplace_back(d, p);
			time[v] = T++;
			dist[v] = di;
			trav(e, C[v]) if (e.first != p)
				q.emplace_back(e.first, v, d+1, di + e.second);
		}
		return ret;
	}

	int query(int a, int b) {
		if (a == b) return a;
		a = time[a], b = time[b];
		return rmq.query(min(a, b), max(a, b)).second;
	}
	ll distance(int a, int b) {
		int lca = query(a, b);
		return dist[a] + dist[b] - 2 * dist[lca];
	}
};

vpi compressTree(LCA& lca, const vi& subset) {
	static vi rev; rev.resize(sz(lca.dist));
	vi li = subset, &T = lca.time;
	auto cmp = [&](int a, int b) { return T[a] < T[b]; };
	sort(all(li), cmp);
	int m = sz(li)-1;
	rep(i,0,m) {
		int a = li[i], b = li[i+1];
		li.push_back(lca.query(a, b));
	}
	sort(all(li), cmp);
	li.erase(unique(all(li)), li.end());
	rep(i,0,sz(li)) rev[li[i]] = i;
	vpi ret = {pii(0, li[0])};
	rep(i,0,sz(li)-1) {
		int a = li[i], b = li[i+1];
		ret.emplace_back(rev[lca.query(a, b)], b);
	}
	return ret;
}

const int MAXN = 1e6;
int which_v[MAXN];
int which_c[MAXN];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	graph g(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back({v, 1});
		g[v].push_back({u, 1});
	}
	LCA lca(g);
	int Q;
	cin >> Q;
	for(int _ = 0; _ < Q; _++){
		int k, m;
		cin >> k >> m;
		vector<int> vst(k);
		vector<int> speed(k);
		for(int i = 0; i < k; i++){
			cin >> vst[i] >> speed[i];
			vst[i]--;
		}
		vector<int> city(m);
		for(int i = 0; i < m; i++){
			cin >> city[i];
			city[i]--;
		}

		vector<int> subset(k+m);
		for(int i = 0; i < k; i++){
			which_v[vst[i]] = i;
			subset[i] = vst[i];
		}
		for(int i = 0; i < m; i++){
			which_c[city[i]] = i;
			subset[i+k] = city[i];
		};

		vector<pair<int,int> > ct = compressTree(lca, subset);
		int z = (int)ct.size();
		vector<vector<int> > cte(z);
		for(int i = 0; i < z; i++){
			if(ct[i].first != -1){
				cte[ct[i].first].push_back(i);
				cte[i].push_back(ct[i].first);
			}
		}

		vector<int> infect(z, -1);
		priority_queue<pair<ll, int> > pq; // time, id, v
		const ll B = 1e7;
		for(int i = 0; i < z; i++){
			int r = which_v[ct[i].second];
			if(r < 0 || r >= k || vst[r] != ct[i].second) continue;
			pq.push({-(B * 0 + r), i});
		}
		while(!pq.empty()){
			pair<ll, int> x = pq.top();
			pq.pop();
			int v = x.second;
			if(infect[v] != -1) continue;
			int id = (-x.first) % B;
			infect[v] = id;
			for(int w : cte[v]){
				int time = 1 + (lca.distance(vst[id], ct[w].second) - 1) / speed[id];
				pq.push({-(B * time + id), w});
			}
		}
		vector<int> ans(m, -1);
		for(int i = 0; i < z; i++){
			int r = which_c[ct[i].second];
			if(r < 0 || r >= m || city[r] != ct[i].second) continue;
			ans[r] = infect[i];
		}
		for(int i = 0; i < m; i++){
			cout << ans[i] + 1 << ' ';
		}
		cout << '\n';
	}
}