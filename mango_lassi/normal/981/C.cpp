#include <iostream>
#include <vector>

const int N = 2 * (int)(1e5);
std::vector<int> conns[N];

void dfs(int i, int p, int r) {
	if (conns[i].size() == 1 && conns[i][0] == p) {
		std::cout << (i + 1) << ' ' << (r + 1) << '\n';
	} else {
		for (auto t : conns[i]) {
			if (t == p) continue;
			dfs(t, i, r);
		}
	}
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		std::cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	int ind = -1;
	for (int i = 0; i < n; ++i) {
		if (conns[i].size() > 2) {
			if (ind != -1) {
				std::cout << "No\n";
				return 0;
			}
			ind = i;
		}
	}
	if (ind == -1) ind = 0;
	std::cout << "Yes\n";
	std::cout << conns[ind].size() << '\n';
	dfs(ind, ind, ind);
}