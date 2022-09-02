#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e5;
vector<pair<int, int>> conns[N];
vector<int> ins[N];

const int K = 9;
const int S = K * (K + 1) / 2;
vector<int> bans[S];
int used[S];

int encode(int deg, int ind) {
	return (deg * (deg - 1)) / 2 + ind;
}

int recSolve(int i, int c, int k, int s) {
	// Base cases
	if (c >= k) return 1;
	if (i >= s) return 0;

	// Do not use
	int res = recSolve(i+1, c, k, s);
	if (used[i]) return res;

	// Use
	for (auto t : bans[i]) ++used[t];
	// cerr << "+ " << i << '\n';
	res += recSolve(i+1, c+1, k, s);
	// cerr << "- " << i << '\n';
	for (auto t : bans[i]) --used[t];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a; --b;
		conns[a].emplace_back(w, b);
	}

	// After selecting a tuple, we need there to be exactly one edge into and out of every vertex
	// this is a sufficient and necessary condition

	// Since every vertex will have exactly one outgoing edge no matter what, it suffices to have
	// in-degree exactly one. If vertex x has parents a and b, and is the ch(a, x)th child of a,
	// and the ch(b, x)th child of b, then we have the condition NOT ans[deg(a)][ch(a, x)] && ans[deg(b)][ch(b, x)]

	// And these conditions are sufficient!
	// Only 9! = 362880 choices, this allows us to brute-force through all of them.

	for (int i = 0; i < n; ++i) {
		sort(conns[i].begin(), conns[i].end());

		int d = conns[i].size();
		for (int j = 0; j < d; ++j) {
			int t = conns[i][j].second;
			ins[t].emplace_back(encode(d, j));
		}
	}

	// Init bans
	for (int i = 0; i < n; ++i) {
		sort(ins[i].begin(), ins[i].end());

		// Ban, then erase duplicates
		for (int j = 0; j+1 < ins[i].size(); ++j) {
			if (ins[i][j] == ins[i][j+1]) ++used[ins[i][j]];
		}
		ins[i].erase(unique(ins[i].begin(), ins[i].end()), ins[i].end());

		for (int a = 0; a < ins[i].size(); ++a) {
			for (int b = a+1; b < ins[i].size(); ++b) {
				bans[ins[i][a]].push_back(ins[i][b]);
			}
		}
	}

	for (int d = 1; d <= k; ++d) {
		for (int j = 0; j < d; ++j) {
			int i = encode(d, j);
			for (int t = j+1; t < d; ++t) bans[i].push_back(encode(d, t));
		}
	}

	int s = k * (k+1) / 2;
	for (int i = 0; i < s; ++i) {
		sort(bans[i].begin(), bans[i].end());
		bans[i].erase(unique(bans[i].begin(), bans[i].end()), bans[i].end());
	}

	// Now we just brute-force
	ll res = recSolve(0, 0, k, s);
	cout << res << '\n';
}