#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;

const int N = 2 * (int)1e5;
vector<int> conns[N];
vector<pair<int, int>> res;
bool visited[N];

void dfs(int i) {
	for (auto t : conns[i]) {
		if (! visited[t]) {
			res.push_back({i+1, t+1});
			visited[t] = true;
			dfs(t);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	int mi = 0;
	for (int i = 1; i < n; ++i) {
		if (conns[i].size() > conns[mi].size()) mi = i;
	}

	visited[mi] = true;
	for (auto t : conns[mi]) {
		res.push_back({mi+1, t+1});
		visited[t] = true;
	}
	for (auto t : conns[mi]) dfs(t);

	for (auto pr : res) cout << pr.first << ' ' << pr.second << '\n';
}