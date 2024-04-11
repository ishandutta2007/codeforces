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

void solve(){
	int n;
	cin >> n;
	vector<vector<int> > edges(n);
	vector<int> buds;
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	y_combinator(
		[&](auto self, int v, int p) -> int {
			int nl = 0;
			for(int w : edges[v]){
				if(w == p) continue;
				int res = self(w, v);
				if(res){
					nl++;
				}
			}
			if(v != 0){
				if(nl || p == 0){
					buds.push_back(nl);
					return 0;
				} else {
					return 1;
				}
			} else {
				return 0;
			}
		}
	)(0, -1);
	int nonzero = 0;
	int zero = 0;
	int sum = 0;
	for(int x : buds){
		if(x){
			nonzero++;
		} else {
			zero++;
		}
		sum += x;
		if(!x) sum += 1;
	}
	if(zero > 0) nonzero += 1;
	cout << (sum - (nonzero - 1)) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}