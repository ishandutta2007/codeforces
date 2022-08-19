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
	vector<int> color(n);
	for(int i = 0; i < n; i++){
		cin >> color[i];
		color[i]--;
	}
	vector<vector<int> > edges(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int s = 0;
	int e = n;
	while(s + 1 < e){
		int m = (s + e) / 2;
		pair<int,int> res = y_combinator(
			[&](auto self, int v, int p) -> pair<int,int> {
				int m0a = 1, m0b = 1;
				int m1a = 1, m1b = 1;
				for(int w : edges[v]){
					if(w == p) continue;
					pair<int,int> z = self(w, v);
					m0b = max(m0b, z.first);
					if(m0b > m0a) swap(m0a, m0b);
					m1b = max(m1b, z.second);
					if(m1b > m1a) swap(m1a, m1b);
				}
				int r0 = 1e8;
				int r1 = 1e8;
				if(color[v] != 1 && m0a + m0b-1 <= 2*m-1){
					r0 = m0a;
				}
				if(color[v] != 0 && m1a + m1b-1 <= 2*m-1){
					r1 = m1a;
				}
				r0 = min(r0, r1 + 1);
				r1 = min(r1, r0 + 1);
				return {r0, r1};
			}
		)(0, -1);
		if(res.first <= n || res.second <= n){
			e = m;
		} else {
			s = m;
		}
	}
	cout << e << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}