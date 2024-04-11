#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

int sub(int x, int y) {
	x -= y;
	if (x < 0) x += MOD;
	return x;
}

int mult(int x, int y) {
	return int64_t(x) * y % MOD;	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M; cin >> N >> M;
	vector<vector<int>> adj(N);
	vector<set<int>> go(N);
	vector<int> nimber(N);
	vector<int> deg(N);
	for (int i = 0; i < M; ++i) {
		int v, u; cin >> v >> u;
		--v, --u;
		adj[u].emplace_back(v);
		deg[v] ++;
	}
	queue<int> bfs; for (int z = 0; z < N; ++z) if (deg[z] == 0) bfs.emplace(z);
	while (!bfs.empty()) {
		int v = bfs.front(); bfs.pop();
		while (go[v].count(nimber[v])) nimber[v] ++;
		for (int u : adj[v]) {
			go[u].emplace(nimber[v]);
			if (--deg[u] == 0) {
				bfs.emplace(u);
			}
		}
	}
	const int B = 512;
	auto inv = [&](int x) {
	  int y = MOD-2;
	  int ans = 1;
	  while (y) {
	     if (y & 1) ans = mult(ans, x);
	     x = mult(x, x);
	     y >>= 1;
	  }
	  return ans;
	};
	vector<int> freq(B); for (int v : nimber) freq[v] ++;
	int coeff = inv(N+1);
	vector<vector<int>> mat(B, vector<int>(B+1));
	for (int i = 0; i < B; ++i) {
	   mat[i][i] = 1;
	   for (int j = 0; j < B; ++j) {
	      mat[i][j] = add(mat[i][j], mult(MOD - freq[i ^ j], coeff));
	   }
	   if (i == 0) mat[i][B] = coeff;
	}
	for (int i = 0; i < B; ++i) {
	   for (int j = i; j < B; ++j) {
	      if (mat[j][i] > 0) {
	         swap(mat[i], mat[j]);
	         break;
	      }
	   }
	   for (int j = i+1; j < B; ++j) {
	      int coeff = mult(inv(mat[i][i]), MOD - mat[j][i]);
	      for (int k = i; k <= B; ++k) {
	         mat[j][k] = add(mat[j][k], mult(coeff, mat[i][k]));
	      }
	   }
	}
	vector<int> ans(B);
	for (int i = B-1; i >= 0; --i) {
	   int cur = mat[i][B];
	   for (int j = i+1; j < B; ++j) cur = sub(cur, mult(mat[i][j], ans[j]));
	   ans[i] = mult(cur, inv(mat[i][i]));
	}
	cout << sub(1, ans[0]) << '\n';
	return 0;
}