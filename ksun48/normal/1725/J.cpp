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
	int N;
	cin >> N;
	vector<vector<pair<int, ll> > > edges(N);
	ll base_cost = 0;
	for(int i = 0; i < N-1; i++){
		int u, v;
		cin >> u >> v;
		ll W;
		cin >> W;
		u--; v--;
		edges[u].push_back({v, W});
		edges[v].push_back({u, W});
		base_cost += W;
	}
	if(N == 1){
		cout << 0 << '\n';
		return 0;
	}
	vector<ll> up_len(N, 0);
	vector<pair<ll, ll> > dp_down(N);
	vector<pair<ll, ll> > dp_up(N);
	ll max_save = 0;
	y_combinator(
		[&](auto self, int v, int p) -> void {
			for(auto [w, L] : edges[v]){
				if(w == p) continue;
				up_len[w] = L;
				self(w, v);
			}
			ll m1 = 0, m2 = 0;
			ll best = 0;
			for(auto [w, L] : edges[v]){
				if(w == p) continue;
				auto [wbest, wm] = dp_down[w];
				best = max(best, wbest);
				m2 = max(m2, wm + L);
				if(m2 > m1) swap(m2, m1);
			}
			best = max(best, m1 + m2);
			dp_down[v] = {best, m1};
		}
	)(0, -1);
	dp_up[0] = {0, 0};
	y_combinator(
		[&](auto self, int v, int p) -> void {
			ll m1 = 0, m2 = 0, m3 = 0, m4 = 0;
			ll best1 = 0, best2 = 0;
			best1 = dp_up[v].first;
			m1 = dp_up[v].second + up_len[v];
			for(auto [w, L] : edges[v]){
				if(w == p) continue;
				m4 = max(m4, dp_down[w].second + L);
				best2 = max(best2, dp_down[w].first);
				if(m4 > m3) swap(m4, m3);
				if(m3 > m2) swap(m3, m2);
				if(m2 > m1) swap(m2, m1);
				if(best2 > best1) swap(best2, best1);
			}
			for(auto [w, L] : edges[v]){
				if(w == p) continue;
				ll best = (best1 == dp_down[w].first) ? best2 : best1;
				ll m = m1;
				if(dp_down[w].second + L == m1){
					best = max(best, m2 + m3);
					m = m2;
				} else if(dp_down[w].second + L == m2){
					best = max(best, m1 + m3);
				} else {
					best = max(best, m1 + m2);
				}
				dp_up[w] = {best, m};
				self(w, v);
			}
			max_save = max(max_save, m1 + m2 + m3 + m4);
		}
	)(0, -1);
	for(int i = 0; i < N; i++){
		max_save = max(max_save, up_len[i] * 2 + dp_down[i].first + dp_up[i].first);
	}
	cout << (2 * base_cost - max_save) << '\n';
}