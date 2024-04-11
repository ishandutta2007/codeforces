#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;

const int N = 2 * (int)1e5;
vector<int> conns[N];
vector<pair<int, int>> res;
bool visited[N];
bool forced[N];

void dfs(int i, bool ed) {
	for (auto t : conns[i]) {
		if (visited[t] == ed) {
			if (ed) res.push_back({i+1, t+1});
			visited[t] = !ed;
			dfs(t, ed);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, d;
	cin >> n >> m >> d;
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	// D must be degree of node 1
	int must = 0;
	visited[0] = 1;
	for (auto t : conns[0]) {
		if (! visited[t]) {
			forced[t] = true;
			visited[t] = true;
			dfs(t, false);
			++must;
		}
	}
	for (auto t : conns[0]) {
		if ((! forced[t]) && (must < d)) {
			forced[t] = true;
			++must;
		}
	}
	if (must != d) {
		cout << "NO\n";
	} else {
		cout << "YES\n";

		visited[0] = 0;
		for (auto t : conns[0]) {
			if (forced[t]) {
				res.push_back({1, t+1});
				visited[t] = false;
			}
		}
		for (auto t : conns[0]) {
			if (forced[t]) {
				dfs(t, true);
			}
		}
		for (auto pr : res) cout << pr.first << ' ' << pr.second << '\n';
	}
}