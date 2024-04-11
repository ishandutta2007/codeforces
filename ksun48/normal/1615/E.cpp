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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<vector<int> > edges(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<pair<int,int> > gain(n);
	y_combinator(
		[&](auto self, int v, int p) -> pair<int,int> {
			gain[v] = {0, v};
			for(int w : edges[v]){
				if(w == p) continue;
				auto [a, b] = self(w, v);
				gain[v] = max(gain[v], {a+1, b});
			}
			return gain[v];
		}
	)(0, -1);
	vector<int> used(n, 0);
	sort(gain.rbegin(), gain.rend());

	using ll = int64_t;
	ll ans = -1e18;
	int tot = 0;
	int taken = 0;
	for(auto [s, v] : gain){
		if(used[v]) continue;
		used[v] = 1;
		tot += s + 1;
		taken += 1;
		if(taken <= k){
			ll r = taken;
			int bmax = n - tot;
			ll bbest = min(ll(n-r) * ll(r), ll(n-r-bmax) * ll(r-bmax));
			int b2 = min(max(0, n/2), bmax);
			bbest = min(bbest, ll(n-r-b2) * ll(r-b2));
			ans = max(ans, bbest);
		}
	}
	assert(tot == n);
	if(taken <= k){
		ll z = max(min(k, n/2), taken);
		ans = max(ans, ll(n-z) * ll(z));
	}
	cout << ans << '\n';
}