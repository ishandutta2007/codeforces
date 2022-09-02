#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
vector<int> conns[N];
int bip[N];

void dfs(int i, int p = -1) {
	for (auto t : conns[i]) {
		if (t == p) continue;
		bip[t] = bip[i] ^ 1;
		dfs(t, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// just 1, 2, 3 always works (as long as n > 2): root at a vertex with deg > 1, solve children, then set weights to edges to children
	// just 1 or 1, 2 works IFF the tree is bipartite

	// What about the maximum?
	// Number inner vertices, set weight of edge to 2^i + 2^j where i, j are the numbers of its endpoints
	// Works IFF n > 2. Let M be the number of inner vertices, then this adds M-1 + #number of inner vertices with leaf children
	// This is optimal, since all leaf children of a vertex must have the same edge value

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	dfs(0);
	int low = 1;
	int high = -1;
	int val = -1;
	for (int i = 0; i < n; ++i) {
		if (conns[i].size() == 1) {
			if (val == -1) val = bip[i];
			else if (val != bip[i]) low = 3;
		} else {
			++high;
			bool lc = 0;
			for (auto t : conns[i]) {
				if (conns[t].size() == 1) lc = 1;
			}
			if (lc) ++high;
		}
	}
	cout << low << ' ' << high << '\n';
}