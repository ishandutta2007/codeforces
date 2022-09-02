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

const int N = 5 * (int)1e5;
const int K = 5 * (int)1e5;
vector<int> conns[N];
vector<int> groups[K];
int group[N];
int bip[N];
bool fails[N];

void dfs(int i, int v) {
	if (bip[i] != 0) fails[group[i]] |= (bip[i] != v);
	else {
		bip[i] = v;
		for (auto t : conns[i]) {
			if (group[t] == group[i]) dfs(t, v ^ 1);
		}
	}
}

bool dfs2(int i, vector<int>& prt, const vector<vector<int>>& g) {
	for (auto t : g[i]) {
		if (prt[t] == -1) {
			prt[t] = prt[i] ^ 1;
			bool res = dfs2(t, prt, g);
			if (! res) return false;
		} else {
			if (prt[t] == prt[i]) return false;
		}
	}
	return true;
}

bool solve(vector<pair<int, int>>& edges) {
	int m = edges.size();
	for (int i = 0; i < m; ++i) {
		int a = edges[i].first;
		int b = edges[i].second;
		edges.push_back({a, a ^ 1});
		edges.push_back({b, b ^ 1});
	}
	sort(edges.begin(), edges.end());
	edges.erase(unique(edges.begin(), edges.end()), edges.end());
	m = edges.size();

	vector<int> inds;
	for (auto pr : edges) {
		inds.push_back(pr.first);
		inds.push_back(pr.second);
	}
	sort(inds.begin(), inds.end());
	inds.erase(unique(inds.begin(), inds.end()), inds.end());
	int n = inds.size();
	
	// Solve naively for graph with n nodes and m edges
	vector<vector<int>> g(n);
	for (auto& pr : edges) {
		int a = bins(inds, pr.first);
		int b = bins(inds, pr.second);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> prt(n, -1);
	bool res = 1;
	for (int i = 0; i < n; ++i) {
		if (prt[i] != -1) continue;
		prt[i] = 0;
		res &= dfs2(i, prt, g);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	// Graph induced by two groups must be bipartite 

	// Call groups
	//	type A, if they are internally bipartite
	//	type B otherwise

	// Groups of type B don't work with any other group
	// If there are no edges between pairs of groups of type A, they work together
	// We handle edges from groups of type A to subtract pairs that don't work

	for (int i = 0; i < n; ++i) {
		cin >> group[i];
		--group[i];
		groups[group[i]].push_back(i);
	}

	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	int v = 2;
	for (int i = 0; i < n; ++i) {
		if (bip[i] != 0) continue;
		dfs(i, v);
		v += 2;
	}

	ll as = 0;
	for (int j = 0; j < k; ++j) {
		if (! fails[j]) ++as;
	}

	ll res = as * (as - 1) / 2; // divide by 2 later

	// Remove pairs that don't work
	for (int j = 0; j < k; ++j) {
		if (fails[j]) continue;

		vector<pair<int, pair<int, int>>> edges;
		for (auto i : groups[j]) {
			for (auto t : conns[i]) {
				if (group[t] < j && !fails[group[t]]) edges.push_back({group[t], {bip[t], bip[i]}});
			}
		}
		sort(edges.begin(), edges.end());

		for (int x = 0; x < edges.size();) {
			int y = x;
			while(y < edges.size() && edges[y].first == edges[x].first) ++y;
			vector<pair<int, int>> vec(y-x);
			for (int i = 0; i < y-x; ++i) vec[i] = edges[x + i].second;

			if (! solve(vec)) {
				--res;
			}
			x = y;
		}
	}
	cout << res << '\n';
}