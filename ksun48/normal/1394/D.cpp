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

using ll = long long;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> cost(n);
	vector<int> h(n);
	for(ll& x : cost) cin >> x;
	for(int& x : h) cin >> x;
	vector<vector<int> > edges(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += cost[i] * ((ll)edges[i].size());
	}

	vector<int> in(n), out(n), either(n);
	vector<int> what(n, 0);
	pair<ll, ll> g = 
	y_combinator(
		[&](auto self, int v, int p) -> pair<ll, ll> {
			ll tot = 0;
			vector<ll> diffs;
			for(int w : edges[v]){
				if(w == p) continue;
				pair<ll,ll> z = self(w, v);
				diffs.push_back(z.second - z.first);
				tot += z.first;
			}
			sort(diffs.rbegin(), diffs.rend());
			pair<ll, ll> res = {0, 0};
			for(int j = 0; j < 2; j++){
				ll ctot = tot;
				ll best = -1e9;
				for(int i = 0; i <= (int)diffs.size(); i++){
					if(i > 0) ctot += diffs[i-1];
					int nin = (int)diffs.size() - i + (p >= 0 && j == 1);
					int nout = i + (p >= 0 && j == 0);
					best = max(best, ctot + min(nin, nout) * cost[v]);
				}
				if(p >= 0 && j == 0 && h[v] > h[p]) best = -1e9;
				if(p >= 0 && j == 1 && h[v] < h[p]) best = -1e9;
				if(j == 0) res.first = best;
				if(j == 1) res.second = best;
			}
			return res;
		}
	)(0, -1);
	ans -= g.first;
	cout << ans << '\n';
}