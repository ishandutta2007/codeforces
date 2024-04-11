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

void solve(){
	int n;
	cin >> n;
	vector<vector<int> > edges(n);
	vector<ll> l(n), r(n);
	for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	pair<ll, ll> res = y_combinator(
		[&](auto self, int v, int p) -> pair<ll, ll> {
			ll lcost = 0;
			ll rcost = 0;
			for(int w : edges[v]){
				if(w == p) continue;
				auto [a, b] = self(w, v);
				lcost += max(abs(l[v] - l[w]) + a, abs(l[v] - r[w]) + b);
				rcost += max(abs(r[v] - l[w]) + a, abs(r[v] - r[w]) + b);
			}
			return {lcost, rcost};
		}
	)(0, -1);
	cout << max(res.first, res.second) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}