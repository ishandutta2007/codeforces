#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e5;
const int Q = 1e5;
vector<pair<ll, int>> ques[N];
vector<int> deps[N];
int ins[N];
int res[Q];

void combine(vector<int>& a, vector<int>& b) {
	if (a.size() < b.size()) swap(a, b);
	for (int j = 1; j <= b.size(); ++j) {
		a[a.size() - j] += b[b.size() - j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		--as[i];
		++ins[as[i]];
	}

	int q;
	cin >> q;
	for (int j = 0; j < q; ++j) {
		ll m;
		int y;
		cin >> m >> y;
		ques[y-1].emplace_back(m, j);
	}

	// Answer trees
	vector<int> que; // queue of nodes with in-degree zero
	for (int i = 0; i < n; ++i) {
		deps[i] = {1}; // only self at depth 0
		if (ins[i] == 0) que.push_back(i);
	}
	for (int j = 0; j < que.size(); ++j) {
		// Answer queries
		int i = que[j];
		for (auto pr : ques[i]) {
			ll m = pr.first;
			if (deps[i].size() <= m) res[pr.second] = 0;
			else res[pr.second] = deps[i][deps[i].size() - (m+1)];
		}

		// Combine to parent
		deps[i].push_back(0); // Increase depth
		combine(deps[as[i]], deps[i]);

		--ins[as[i]];
		if (ins[as[i]] == 0) que.push_back(as[i]);

		// Clear memory
		deps[i].clear();
		deps[i].shrink_to_fit();
	}

	// Answer cycles
	for (int i = 0; i < n; ++i) {
		if (ins[i] == 0) continue; // Not part of a cycle
		int len = 0;

		// Build values on their first loop
		vector<int> cur;
		for (int j = i;;) {
			ins[j] = 0;
			++len;

			vector<int> bu = deps[j]; // make a backup
			combine(cur, bu);
			cur.push_back(0);
			j = as[j];
			if (j == i) break;
		}

		// Let the counts travel around the circle
		for (int t = 1; t + len <= cur.size(); ++t) {
			cur[cur.size() - t - len] += cur[cur.size() - t];
		}

		// Answer queries
		for (int j = i;;) {
			combine(cur, deps[j]);
			for (auto pr : ques[j]) {
				ll ind = (ll)cur.size() - (pr.first+1);
				if (ind < 0) {
					ind %= len;
					if (ind < 0) ind += len;
				}
				res[pr.second] = cur[ind];
			}

			cur.push_back(0);
			j = as[j];
			if (j == i) break;
		}
	}

	for (int i = 0; i < q; ++i) cout << res[i] << '\n';
}