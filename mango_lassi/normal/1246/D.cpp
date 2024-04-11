#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 1e5;
bool solved[N];
vector<int> conns[N];
vector<int> ops;

void recSolve(vector<int>& nxt, int i) {
	if (solved[i]) return;
	solved[i] = true;

	for (int ti = 0; ti < conns[i].size(); ++ti) {
		if (conns[i][ti] == nxt[i]) {
			swap(conns[i][ti], conns[i][0]);
		}
	}
	for (auto t : conns[i]) {
		if (t == nxt[i]) continue;
		ops.push_back(nxt[i]);
		nxt[t] = nxt[i];
		nxt[i] = t;
		recSolve(nxt, t);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Reverse process, turn tree into bamboo

	// Cost = n - depth

	// To achieve this, just always move the deepest chain on top of everything.
	// Every operation increases depth by one, so cost is reduced by one.
	// Additionally, every operation increases depth by at most one, and the depth of the bamboo is n.
	// Therefore this is optimal.

	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		conns[p].push_back(i);
	}

	int mi = 0;
	vector<int> dep(n, 1);
	for (int i = 0; i < n; ++i) {
		for (auto t : conns[i]) dep[t] += dep[i];
		if (dep[i] > dep[mi]) mi = i;
	}

	vector<int> path = {mi};
	vector<int> nxt(n, -1);
	for (int i = n-1; i >= 0; --i) {
		for (auto t : conns[i]) {
			if (t == path.back()) {
				path.push_back(i);
				break;
			}
		}
	}
	for (int j = (int)path.size() - 1; j >= 0; --j) {
		if (j-1 >= 0) nxt[path[j]] = path[j-1];
		recSolve(nxt, path[j]);
	}

	for (int j = 0; j != -1; j = nxt[j]) cout << j << ' '; cout << '\n';
	cout << ops.size() << '\n';
	for (int j = (int)ops.size() - 1; j >= 0; --j) cout << ops[j] << ' '; cout << '\n';
}