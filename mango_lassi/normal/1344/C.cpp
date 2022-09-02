#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e5;
vector<int> conns[N][2];
int used[N][2];

bool checkCycles(int i, int s) {
	if (used[i][s] != 0) return (used[i][s] != 1); // false = fail
	used[i][s] = 1;
	for (auto t : conns[i][s]) {
		if (! checkCycles(t, s)) return false;
	}
	used[i][s] = 2;
	return true;
}
void dfs(int i, int s) {
	if (used[i][s] == 0) return;
	used[i][s] = 0;
	for (auto t : conns[i][s]) dfs(t, s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Make a DAG of the conditions
	// If A has a path to B, and A appears before B, then B MUST NOT be given quantifier "FOR ALL"
	// The same holds if B has a path to A.
	// Otherwise, we can assign arbitrarily

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a][0].push_back(b);
		conns[b][1].push_back(a);
	}
	
	// 1. Check if there are cycles. If there are, answer "IMPOSSIBLE"
	// 	To check for cycles, just DFS, and upon spotting a active vertex, return FALSE

	bool fail = false;
	for (int i = 0; i < n; ++i) {
		for (int s = 0; s < 2; ++s) {
			if (! checkCycles(i, s)) fail = 1;
		}
	}

	if (fail) cout << -1 << '\n';
	else {
		int cou = 0;
		string res(n, '_');
		for (int i = 0; i < n; ++i) {
			if (used[i][0] && used[i][1]) {
				++cou;
				res[i] = 'A';
			} else {
				res[i] = 'E';
			}
			dfs(i, 0);
			dfs(i, 1);
		}
		cout << cou << '\n' << res << '\n';
	}
}