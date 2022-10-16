#include <bits/stdc++.h>

using namespace std;
 
const int kMaxN = 110;
 
bool can_reach[kMaxN][kMaxN * kMaxN];
bool is_ordered[kMaxN][kMaxN * kMaxN];
int num_children[kMaxN][kMaxN * kMaxN];
 
void Preproc() {
	can_reach[1][1] = true;
	for (int len = 1; len < kMaxN; ++len) {
		for (int nintvs = 1; nintvs <= len * len; ++nintvs) {
			if (!can_reach[len][nintvs]) {
				continue;
			}
 
			// Ordered nodes; there must be at least two children.
			for (int k = 2; len + k <= kMaxN; ++k) {
				const int new_len = len + k - 1;
				const int new_nintvs = nintvs + k * (k + 1) / 2 - 1;
				can_reach[new_len][new_nintvs] = true;
				is_ordered[new_len][new_nintvs] = true;
				num_children[new_len][new_nintvs] = k;
			}
 
			// Unordered nodes; at least four children.
			for (int k = 4; len + k <= kMaxN; ++k) {
				const int new_len = len + k - 1;
				const int new_nintvs = nintvs + k;
				can_reach[new_len][new_nintvs] = true;
				is_ordered[new_len][new_nintvs] = false;
				num_children[new_len][new_nintvs] = k;
			}
		}
	}
}

// Build a Divide-Combine Tree given the length of the permutation an num of intervals.
// Then, run a DFS on it in order to recover the permutation.
void Construct(int len, int nintvs) {
	vector<int> roots(len);
	const int init_len = len;
	iota(roots.begin(), roots.end(), 0);

	// Is the node an ordered node?
	vector<bool> node_ordered(len);

	// Children of the node, in yet undetermined order.
	vector<vector<int>> node_children(len);

	while (len > 1) {
		assert(can_reach[len][nintvs]);
		const int k = num_children[len][nintvs];
		const int new_root = node_children.size();
		vector<int> children(roots.end() - k, roots.end());
		roots.erase(roots.end() - k, roots.end());
		node_children.push_back(children);
		roots.push_back(new_root);

		if (is_ordered[len][nintvs]) {
			node_ordered.push_back(true);
			len -= (k - 1);
			nintvs -= k * (k + 1) / 2 - 1;
		} else {
			node_ordered.push_back(false);
			len -= (k - 1);
			nintvs -= k;
		}
	}

	vector<int> answer;

	// The [ordered_inc] argument here is negated in each recursive call
	//   in order to disallow putting increasing nodes as children
	//   of increasing nodes, and decreasing nodes as children of decreasing
	//   nodes.
	function<void(int, bool)> Dfs = [&](int v, bool ordered_inc) {
		if (v < init_len) {
			answer.push_back(v + 1);
		} else if (node_ordered[v]) {
			if (ordered_inc) {
				// Case 1: increasing node.
				for (int child : node_children[v]) {
					Dfs(child, !ordered_inc);
				}
			} else {
				// Case 2: decreasing node.
				const int sz = node_children[v].size();
				for (int i = sz - 1; i >= 0; --i) {
					Dfs(node_children[v][i], !ordered_inc);
				}
			}
		} else {
			// Case 3: unordered node. Put the children in a specific order in order
			//   to avoid any additional intervals.
			const int sz = node_children[v].size();
			vector<int> order;
			for (int start : {1, 0}) {
				for (int i = start; i < sz; i += 2) {
					order.push_back(i);
				}
			}
			if (sz % 2 == 1) {
				swap(order[sz - 2], order[sz - 1]);
			}
			for (int i : order) {
				Dfs(node_children[v][i], !ordered_inc);
			}
		}
	};
 
	Dfs(roots[0], true);
 
	for (int v : answer) {
		cout << v << " ";
	}
	cout << "\n";
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Preproc();

	int q;
	cin >> q;

	while (q--) {
		int n, k;
		cin >> n >> k;
 
		if (!can_reach[n][k]) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			Construct(n, k);
		}
	}
}