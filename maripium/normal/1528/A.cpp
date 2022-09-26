#include <bits/stdc++.h>

using namespace std;

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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<array<int, 2>> A(N);
		for (int i = 0; i < N; ++i) cin >> A[i][0] >> A[i][1];
		vector<vector<int>> adj(N);
		for (int i = 0; i + 1 < N; ++i) {
			int v, u; cin >> v >> u;
			adj[--v].push_back(--u);
			adj[u].push_back(v);
		}
		auto ans = y_combinator([&](auto self, int v) -> array<int64_t, 2> {
			array<int64_t, 2> ans{};
			for (int u : adj[v]) {
				adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
				auto nans = self(u);
				for (int x = 0; x < 2; ++x) {
					int64_t cur = 0;
					for (int y = 0; y < 2; ++y) {
						cur = max(cur, nans[y] + abs(A[v][x] - A[u][y]));
					}
					ans[x] += cur;
				}
			}
			return ans;
		})(0);
		cout << max(ans[0], ans[1]) << '\n';
	}	
	return 0;
}