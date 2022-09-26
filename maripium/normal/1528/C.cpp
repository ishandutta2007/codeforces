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
		vector<int> A(N - 1); for (int &a : A) cin >> a, --a;
		vector<int> B(N - 1); for (int &b : B) cin >> b, --b;

		vector<int> L(N), R(N);
		vector<vector<int>> adj(N);
		for (int i = 1; i < N; ++i) {
			adj[B[i - 1]].push_back(i);
		} 
		int timer = 0;
		y_combinator([&](auto self, int v) -> void {
			L[v] = timer++;
			for (int u : adj[v]) self(u);
			R[v] = timer;
		})(0);

		for (int i = 0; i < N; ++i) adj[i].clear();
		for (int i = 1; i < N; ++i) adj[A[i - 1]].push_back(i);

		int ans = 0;
		set<pair<int, int>> st;
		y_combinator([&](auto self, int v) -> void {
			bool add = true;
			optional<pair<int, int>> par = nullopt;
			auto it = st.lower_bound(make_pair(L[v], R[v]));
			if (it != st.end() && it->second <= R[v]) {
				add = false;
			}
			if (add) {
				auto it = st.lower_bound(make_pair(L[v], R[v]));
				if (it != st.begin() && prev(it)->second >= R[v]) {
					par = {*prev(it)};
				}
			}

//			cerr << "at " << v << '\n'; 
			if (add) {
				st.insert(make_pair(L[v], R[v]));
			}
			if (par) {
//				cerr << "remove " << par->first << ' ' << par->second << '\n';
				st.erase(*par);
			}
			ans = max(ans, int(st.size()));
			for (int u : adj[v]) self(u);
			if (add) st.erase(make_pair(L[v], R[v]));
			if (par) st.insert(*par);
		})(0);
		cout << ans << '\n';
	}	
	return 0;
}