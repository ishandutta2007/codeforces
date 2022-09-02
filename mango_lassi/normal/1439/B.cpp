#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// returns number of elements strictly smaller than v in vec
template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

const int N = 2 * (int)1e5;
vector<int> conns[N];
int deg[N];

void ansClique(const vector<int>& cliq) {
	cout << 2 << '\n';
	for (auto v : cliq) cout << v+1 << ' '; cout << '\n';
}
void ansSubset(const vector<int>& subset) {
	cout << 1 << ' ' << subset.size() << '\n';
	for (auto v : subset) cout << v+1 << ' '; cout << '\n';
}
void ansFail() {
	cout << -1 << '\n';
}

bool subseq(const vector<int>& a, const vector<int>& b) {
	for (auto i : b) {
		int j = bins(a, i);
		if (j == a.size() || a[j] != i) return false;
	}
	return true;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	// cout << n << ' ' << m << ' ' << k << '\n';

	// Remove all vertices with degree < k-1. Repeat until nothing changes
	// While there exists a vertex with degree exactly k-1, check if its neighbours form a clique.
	//	If they do, return that clique
	//	If they do not, remove that vertex
	// If any vertices remain, return them as a set where every vertex has at least k neighbours in the set
	// Otherwise, fail
	
	// After the first phase, at most n/(k-1) vertices and at least k vertices remain, and in the second phase, we do O(k^2) work per vertex
	// -> A O(n sqrt n) algorithm

	for (int i = 0; i < n; ++i) {
		conns[i].clear();
		conns[i].shrink_to_fit();
	}
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;

		// cout << a << ' ' << b << '\n';

		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	vector<int> que;
	for (int i = 0; i < n; ++i) {
		deg[i] = conns[i].size();
		if (deg[i] < k-1) que.push_back(i);
	}


	for (int j = 0; j < que.size(); ++j) {
		int i = que[j];
		for (auto t : conns[i]) {
			--deg[t];
			if (deg[t] == k-2) que.push_back(t);
		}
		deg[i] = -1;
	}

	que.clear();
	que.shrink_to_fit();

	// for (int i = 0; i < n; ++i) cerr << deg[i] << ' '; cerr << '\n';

	for (int i = 0; i < n; ++i) {
		if (deg[i] <= -1) continue;

		int r = 0;
		for (int j = 0; j + r < conns[i].size(); ++j) {
			swap(conns[i][j], conns[i][j + r]);
			if (deg[conns[i][j]] <= -1) {
				++r;
				--j;
			}
		}
		conns[i].resize((int)conns[i].size() - r);
		conns[i].shrink_to_fit();
		conns[i].push_back(i);
		sort(conns[i].begin(), conns[i].end());

		deg[i] = conns[i].size();
		if (deg[i] <= k) que.push_back(i);
	}

	for (int j = 0; j < que.size(); ++j) {
		int i = que[j];
		if (deg[i] == k) {
			vector<int> cliq;
			for (auto t : conns[i]) {
				if (deg[t] > -1) cliq.push_back(t);
			}
			
			/*
			cerr << "test clique ";
			for (auto v : cliq) cerr << v << ' '; cerr << '\n';
			*/

			bool is_clique = 1;
			for (auto t : conns[i]) {
				if (deg[t] <= -1) continue;
				
				if (! subseq(conns[t], cliq)) {
					is_clique = 0;
					break;
				}
			}
			if (is_clique) {
				ansClique(cliq);
				return;
			}
		}
		for (auto t : conns[i]) {
			--deg[t];
			if (deg[t] == k) que.push_back(t);
		}
		deg[i] = -1;
	}

	// for (int i = 0; i < n; ++i) cerr << deg[i] << ' '; cerr << '\n';

	vector<int> res;
	for (int i = 0; i < n; ++i) {
		if (deg[i] > -1) res.push_back(i);
	}
	if (! res.empty()) {
		ansSubset(res);
	} else {
		ansFail();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	// cout << t << '\n';

	for (int ti = 0; ti < t; ++ti) solve();

}