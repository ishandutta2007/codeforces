#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<int> A(N); for (int &a : A) cin >> a;
		vector<vector<int>> outEdges(N);
		vector<vector<int>> inEdges(N);
		for (int i = 0; i < M; ++i) {
			int x, y; cin >> x >> y;
			--x, --y;
			outEdges[x].push_back(y);
			inEdges[y].push_back(x);
		}

		auto solve = [&]() {
			for (int z = 0; z < N; ++z) {
				vector<int> S;
				for (int x = 0; x < N; ++x) if (A[x] > 0) S.push_back(x);
				if (S.empty()) return z;
				for (int x : S) {
					A[x]--;
					for (int y : outEdges[x]) A[y]++;
				}
			}

			vector<int> B(N);
			
			const int MOD = 998244353;
			queue<int> bfs;
			vector<int> outDeg(N);
			for (int i = 0; i < N; ++i) {
				outDeg[i] = int(outEdges[i].size());
				if (outDeg[i] == 0) {
					B[i] = 1;
					bfs.push(i);
				}
			}

			while (!bfs.empty()) {
				int v = bfs.front(); bfs.pop();
				for (int u : inEdges[v]) {
					B[u] += B[v];
					if (B[u] >= MOD) B[u] -= MOD;
					if (--outDeg[u] == 0) {
						bfs.push(u);
					} 
				}
			}

			int ans = N;
			for (int v = 0; v < N; ++v) ans = (ans + int64_t(A[v]) * B[v]) % MOD;
			return ans;
		};

		cout << solve() << '\n';
	}
	return 0;	
}