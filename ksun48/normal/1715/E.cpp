#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<pair<int, ll> > > edges(N);
	for(int i = 0; i < M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges[u].push_back({v, w});
		edges[v].push_back({u, w});
	}

	const ll INF = ll(1e18);
	vector<ll> dist(N, INF);
	dist[0] = 0;
	for(int its = 0; its <= K; its++){
		{
			priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
			for(int i = 0; i < N; i++){
				pq.push({dist[i], i});
			}
			vector<int> vis(N, 0);
			while(!pq.empty()){
				int v = pq.top().second;
				pq.pop();
				if(vis[v]) continue;
				for(auto [u, c] : edges[v]){
					if(dist[v] + c < dist[u]){
						dist[u] = dist[v] + c;
						pq.push({dist[u], u});
					}
				}
			}
		}
		if(its < K){
			LineContainer lc;
			for(int i = 0; i < N; i++){
				lc.add(2 * i, - ll(i) * ll(i) - dist[i]);
			}
			for(int i = 0; i < N; i++){
				dist[i] = -lc.query(i) + ll(i) * ll(i);
			}
		}
	}
	for(int i = 0; i < N; i++){
		cout << dist[i] << " \n"[i == N-1];
	}
}