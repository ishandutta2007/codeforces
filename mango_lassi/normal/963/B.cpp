#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 2 * (int)1e5;
vector<int> conns[N];
int siz[N];

int dfs(int i, int p) {
	siz[i] = 1;
	for (auto t : conns[i]) {
		if (t != p) siz[i] += dfs(t, i);
	}
	return siz[i];
}

// Since number of nodes in tree is odd, any node with even degree divides the graph
// into an even number of odd degree subtrees, and an even number of even degree subtrees.
// solve the even degree subtrees as if the node was a leaf, then remove the node.
void solve(int i, int p, vector<int>& res) {
	for (auto t : conns[i]) {
		if (t != p && siz[t] % 2 == 0) solve(t, i, res);
	}
	res.push_back(i);
	for (auto t : conns[i]) {
		if (t != p && siz[t] % 2 == 1) solve(t, i, res);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		if (p != -1) {
			conns[i].push_back(p);
			conns[p].push_back(i);
		}
	}

	// Possible IFF we have an odd number of nodes
	// To output a solution, find any even-degree node that
	// divides the tree into odd sizes.
	if (n % 2 == 0) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		vector<int> res;
		dfs(0, 0);
		solve(0, 0, res);
		for (auto i : res) cout << i+1 << '\n';
	}
}