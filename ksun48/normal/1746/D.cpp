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
	int N, K;
	cin >> N >> K;
	vector<int> par(N);
	vector<vector<int> > ch(N);
	for(int i = 1; i < N; i++){
		cin >> par[i];
		par[i]--;
		ch[par[i]].push_back(i);
	}
	vector<ll> score(N);
	for(ll& x : score) cin >> x;
	map<pair<ll, int>, ll> dp;
	ll f = y_combinator(
		[&](auto self, int v, ll cur) -> ll {
			if(!dp.count({v, cur})){
				ll ans = score[v] * cur;
				if(ch[v].size() > 0){
					vector<ll> diffs;
					ll z = cur / ch[v].size();
					for(int w : ch[v]){
						ll s1 = self(w, z);
						ll s2;
						if(cur % ch[v].size() > 0){
							s2 = self(w, z+1);
						} else {
							s2 = s1;
						}
						ans += s1;
						diffs.push_back(s2 - s1);
					}
					sort(diffs.rbegin(), diffs.rend());
					for(int j = 0; j < (cur % ch[v].size()); j++){
						ans += diffs[j];
					}
				}
				dp[{v, cur}] = ans;
			}
			return dp[{v, cur}];
		}
	)(0, K);
	cout << f << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}