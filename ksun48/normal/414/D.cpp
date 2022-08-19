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
	int n, k, p;
	cin >> n >> k >> p;
	vector<vector<int> > edges(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<int> depths;
	y_combinator(
		[&](auto self, int v, int par, int d) -> void {
			if(d > 0) depths.push_back(d);
			for(int w : edges[v]){
				if(w == par) continue;
				self(w, v, d+1);
			}
		}
	)(0, -1, 0);
	int best = 1;
	sort(depths.rbegin(), depths.rend());
	int ccost = 0;
	int j = 0;
	int cval = depths.front();
	for(int i = 0; i < (int)depths.size(); i++){
		while(j < (int)depths.size() && ccost + (cval - depths[j]) <= p){
			ccost += cval - depths[j];
			j++;
		}
		best = max(best, j-i);
		if(i + 1 < (int)depths.size()){
			ccost -= (j-i-1) * (cval - depths[i+1]);
			cval = depths[i+1];			
		}
	}
	best = min(best, k);
	cout << best << '\n';
}