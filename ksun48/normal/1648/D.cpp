#include <bits/stdc++.h>
using namespace std;

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

using ll = int64_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<vector<ll> > grid(3, vector<ll>(n));
	for(int i = 0; i < 3; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];
	ll base = 0;
	for(ll x : grid[1]) base += x;
	vector<ll> in_score(n+1), out_score(n+1);
	in_score[0] = grid[0][0];
	for(int i = 1; i < n; i++){
		in_score[i] = in_score[i-1] + grid[0][i] - grid[1][i-1];
	}
	const ll MAX = ll(1e16);
	in_score[n] = -MAX;
	out_score[n] = grid[2][n-1];
	for(int i = n-1; i > 0; i--){
		out_score[i] = out_score[i+1] + grid[2][i-1] - grid[1][i];
	}
	out_score[0] = -MAX;
	for(ll& x : in_score) x = -x;
	for(ll& x : out_score) x = -x;
	vector<tuple<int, int, ll> > s_edges;
	for(int i = 0; i < q; i++){
		int l, r;
		ll k;
		cin >> l >> r >> k;
		l--;
		s_edges.push_back({l, r, k});
	}
	ll ans = 1e18;
	y_combinator(
		[&](auto self, int L, int R, ll total, vector<tuple<int, int, ll> > e) -> void {
			if(L == R) return;
			int M = (L + R) / 2;
			vector<vector<pair<int, ll> > > edges(R-L+1);
			for(int i = L+1; i <= R; i++){
				edges[i-L].push_back({i-L-1, 0});
			}
			for(auto [l, r, k] : e){
				l = max(l, L);
				r = min(r, R);
				edges[l-L].push_back({r-L, k});
			}
			edges[0].push_back({R-L, total});
			int N = R-L+1;
			vector<int> vis(N, 0);
			priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<>> pq;
			vector<ll> dist(R-L+1, MAX);
			for(int i = L; i <= M; i++){
				dist[i-L] = in_score[i];
			}
			for(int i = L; i <= M; i++) pq.push({dist[i-L], i-L});
			while(!pq.empty()){
				int v = pq.top().second;
				pq.pop();
				if(vis[v]) continue;
				for(auto [w, c] : edges[v]){
					if(dist[v] + c < dist[w]){
						dist[w] = dist[v] + c;
						pq.push({dist[w], w});
					}
				}
			}

			for(int i = M+1; i <= R; i++){
				ans = min(ans, dist[i-L] + out_score[i]);
			}
			for(auto [nL, nR] : vector<pair<int,int>>{{L, M}, {M+1, R}}){
				vector<tuple<int, int, ll> > ne;
				ll ntotal = total;
				for(auto [l, r, k] : e){
					if(r <= nL || l >= nR) continue;
					if(l <= nL && r >= nR){
						ntotal = min(ntotal, k);
					} else {
						ne.push_back({l, r, k});
					}
				}
				self(nL, nR, ntotal, ne);
			}
		}
	)(0, n, 1e16, s_edges);
	cout << (base - ans) << '\n';
}