#include <iostream>
#include <vector>

const int N = 5000;
std::vector<int> topo;
std::vector<int> conns[N];
bool visited[N];

void dfs1(int i) {
	if (visited[i]) return;
	visited[i] = true;
	for (auto t : conns[i]) dfs1(t);
	topo.push_back(i);
}
void dfs2(int i) {
	if (! visited[i]) return;
	visited[i] = false;
	for (auto t : conns[i]) dfs2(t);
}

int main() {
	int n, m, s;
	std::cin >> n >> m >> s;
	--s;
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
	}
	for (int i = 0; i < n; ++i) dfs1(i);

	int ans = 0;
	dfs2(s);
	while(topo.size() > 0) {
		int b = topo.back();
		topo.pop_back();
		if (visited[b]) {
			dfs2(b);
			++ans;
		}
	}
	std::cout << ans << '\n';
}