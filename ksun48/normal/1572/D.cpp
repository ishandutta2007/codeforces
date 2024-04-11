#include <bits/stdc++.h>
using namespace std;

#include<bits/extc++.h>

using ll = int64_t;
const ll M = ll(1e10);
template <typename flow_t = int, typename cost_t = long long>
struct MCMF_SSPA {
	int N;
	std::vector<std::vector<int>> adj;
	struct edge_t {
		int dest;
		flow_t cap;
		cost_t cost;
	};
	std::vector<edge_t> edges;

	std::vector<char> seen;
	std::vector<cost_t> pi;
	std::vector<int> prv;

	explicit MCMF_SSPA(int N_) : N(N_), adj(N), pi(N, 0), prv(N) {}

	void addEdge(int from, int to, flow_t cap, cost_t cost) {
		assert(cap >= 0);
		assert(cost >= 0); // TODO: Remove this restriction
		int e = int(edges.size());
		edges.emplace_back(edge_t{to, cap, cost});
		edges.emplace_back(edge_t{from, 0, -cost});
		adj[from].push_back(e);
		adj[to].push_back(e+1);
	}

	const cost_t INF_COST = std::numeric_limits<cost_t>::max() / 4;
	const flow_t INF_FLOW = std::numeric_limits<flow_t>::max() / 4;
	std::vector<cost_t> dist;
	__gnu_pbds::priority_queue<std::pair<cost_t, int>> q;
	std::vector<typename decltype(q)::point_iterator> its;
	void path(int s) {
		dist.assign(N, INF_COST);
		dist[s] = 0;

		its.assign(N, q.end());
		its[s] = q.push({0, s});

		while (!q.empty()) {
			int i = q.top().second; q.pop();
			cost_t d = dist[i];
			for (int e : adj[i]) {
				if (edges[e].cap) {
					int j = edges[e].dest;
					cost_t nd = d + edges[e].cost;
					if (nd < dist[j]) {
						dist[j] = nd;
						prv[j] = e;
						if (its[j] == q.end()) {
							its[j] = q.push({-(dist[j] - pi[j]), j});
						} else {
							q.modify(its[j], {-(dist[j] - pi[j]), j});
						}
					}
				}
			}
		}

		swap(pi, dist);
	}

	ll maxflow(int s, int t) {
		assert(s != t);
		flow_t totFlow = 0; cost_t totCost = 0;
		ll ans = 0;
		while (path(s), pi[t] < INF_COST) {
			ans = max(ans, totFlow * M - totCost);
			flow_t curFlow = std::numeric_limits<flow_t>::max();
			for (int cur = t; cur != s; ) {
				int e = prv[cur];
				int nxt = edges[e^1].dest;
				curFlow = std::min(curFlow, edges[e].cap);
				cur = nxt;
			}
			totFlow += curFlow;
			totCost += pi[t] * curFlow;
			for (int cur = t; cur != s; ) {
				int e = prv[cur];
				int nxt = edges[e^1].dest;
				edges[e].cap -= curFlow;
				edges[e^1].cap += curFlow;
				cur = nxt;
			}
			ans = max(ans, totFlow * M - totCost);
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int N = 1 << n;
	k = min(k, N/2);
	vector<int> a(N);
	for(int& x : a) cin >> x;
	vector<pair<int,int> > e;
	for(int j = 0; j < n; j++){
		for(int i = 0; i < N; i++){
			if(i & (1 << j)){
				e.push_back({i ^ (1 << j), i});
			}
		}
	}
	sort(e.begin(), e.end(), [&](pair<int,int> x, pair<int,int> y){
		return a[x.first] + a[x.second] > a[y.first] + a[y.second];
	});
	vector<int> used(N, 0);
	int nu = 0;
	vector<pair<int,int> > edges_care;
	for(pair<int,int> z : e){
		if(__builtin_popcount(z.first) & 1) swap(z.first, z.second);
		edges_care.push_back(z);
		if(used[z.first] || used[z.second]) continue;
		used[z.first] = used[z.second] = 1;
		nu += 1;
		if(nu >= 2 * k) break;
	}
	vector<int> l, r;
	for(auto [x, y] : edges_care){
		l.push_back(x);
		r.push_back(y);
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	l.resize(unique(l.begin(), l.end()) - l.begin());
	r.resize(unique(r.begin(), r.end()) - r.begin());
	for(auto& [x, y] : edges_care){
		x = lower_bound(l.begin(), l.end(), x) - l.begin();
		y = lower_bound(r.begin(), r.end(), y) - r.begin();
	}
	int ls = (int)l.size();
	int rs = (int)r.size();
	MCMF_SSPA<ll, ll> f(ls + rs + 3);
	for(int i = 0; i < n; i++){
		for(auto [x, y] : edges_care){
			f.addEdge(x, y + ls, 1, M - a[l[x]] - a[r[y]]);
		}
	}
	for(int i = 0; i < ls; i++){
		f.addEdge(ls + rs + 2, i, 1, 0);
	}
	for(int i = 0; i < rs; i++){
		f.addEdge(i + ls, ls + rs + 1, 1, 0);
	}
	f.addEdge(ls + rs, ls + rs + 2, k, 0);
	ll ans = f.maxflow(ls + rs, ls + rs + 1);
	cout << ans << '\n';
}