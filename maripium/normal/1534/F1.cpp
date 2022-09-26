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
	int N, M; cin >> N >> M;
	vector<string> G(N); 
	for (int i = 0; i < N; ++i) cin >> G[i];
	vector<int> A(M); for (int &a : A) cin >> a;
	auto enc = [&](int x, int y) {
		return x * M + y;
	};
	auto getG = [&](int v) {
		int x = v / M;
		int y = v % M;
		return G[x][y] == '#';
	};
	vector<vector<int>> sands(M);
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			if (G[r][c] == '#') sands[c].push_back(r);
		}
	}

	vector<vector<int>> adj(N * M);
	vector<vector<int>> radj(N * M);
	auto add_edge = [&](int x, int y, int nx, int ny) {
		adj[enc(x, y)].push_back(enc(nx, ny));
		radj[enc(nx, ny)].push_back(enc(x, y));
	};

	for (int c = 0; c < M; ++c) {
		for (int i = 0; i + 1 < int(sands[c].size()); ++i) {
			add_edge(sands[c][i], c, sands[c][i + 1], c);
			if (sands[c][i] + 1 == sands[c][i + 1]) {
				add_edge(sands[c][i + 1], c, sands[c][i], c);
			}
		}
		for (int r : sands[c]) {
			for (int nc : {c - 1, c + 1}) if (0 <= nc && nc < M) {
				auto it = lower_bound(sands[nc].begin(), sands[nc].end(), r);
				if (it != sands[nc].end()) {
					add_edge(r, c, *it, nc);
				}
			}
		}
	}

	cerr << "Added Edges\n";
	vector<int> ord;
	vector<char> was(N * M);
	auto dfs = y_combinator([&](auto self, int v) -> void {
		was[v] = 1;
		assert(getG(v));
		for (int u : adj[v]) if (!was[u]) self(u);
		ord.push_back(v);
	});

	for (int i = 0; i < N * M; ++i) if (!was[i] && getG(i)) dfs(i);
	reverse(ord.begin(), ord.end());
	vector<int> comp(N * M, -1);
	int C = 0;
	auto rdfs = y_combinator([&](auto self, int v) -> void {
		assert(getG(v));
		comp[v] = C;
		for (int u : radj[v]) if (comp[u] == -1) {
			self(u);
		}
	});
	for (int v : ord) if (comp[v] == -1) {
		rdfs(v);
		C++;
	}
	vector<bool> ok(C, true);
	for (int i = 0; i < N * M; ++i) if (getG(i)) {
		for (int j : adj[i]) if (comp[i] != comp[j]) ok[comp[j]] = false;
	}
	cout << count(ok.begin(), ok.end(), true) << '\n';
}