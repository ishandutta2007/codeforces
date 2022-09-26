#include <bits/stdc++.h>

using namespace std;

struct UF {
	vector<int> par;
	UF(int N = 0) : par(N) {
		iota(par.begin(), par.end(), 0);
	}
	int get_par(int v) {
		while (v != par[v]) {
			v = par[v] = par[par[v]];
		}
		return v;
	}
	bool merge(int v, int u) {
		v = get_par(v);
		u = get_par(u);
		if (v == u) {
			return false;
		} else {
			par[u] = v;
			return true;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	
	while (T--) {
		int N, M; cin >> N >> M;
		vector<array<int, 2>> edges(M);
		UF uf(N);
		vector<int> tree;
		vector<int> ntree;
		for (int i = 0; i < M; ++i) {
			cin >> edges[i][0] >> edges[i][1];
			--edges[i][0];
			--edges[i][1];
			if (uf.merge(edges[i][0], edges[i][1])) {
				tree.push_back(i);
			} else {
				ntree.push_back(i);
			}
		} 

		int ans = 2 * N + 1;
		string best;
		int S = int(ntree.size());
		for (int m = 0; m < 1 << S; ++m) {
			int cur = 2 * N;
			UF uf0(N);
			UF uf1(N);
			string col(M, '~');
			for (int i = 0; i < S; ++i) {
				int e = ntree[i];
				if (m >> i & 1) {
					col[e] = '1';
					cur -= uf1.merge(edges[e][0], edges[e][1]);
				} else {
					col[e] = '0';
					cur -= uf0.merge(edges[e][0], edges[e][1]);
				}
			}
			for (int e : tree) {
				if (uf0.merge(edges[e][0], edges[e][1])) {
					col[e] = '0';
					cur--;
				} else {
					col[e] = '1';
					cur -= uf1.merge(edges[e][0], edges[e][1]);
				}
			}
			if (cur < ans) {
				ans = cur;
				best = col;
			}
		}
		cout << best << '\n';
	}
	return 0;
}