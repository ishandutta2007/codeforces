#include <iostream>
#include <vector>
#include <algorithm>

const int N = (int)(1e5);
const int K = 100;
const int inf = 2 * N;

std::vector<int> inds[K];
int md[K][N];
std::vector<int> conns[N];

int main() {
	int n, m, k, s;
	std::cin >> n >> m >> k >> s;
	
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		--a;
		inds[a].push_back(i);
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) md[i][j] = inf;
		std::vector<int> que;
		for (auto j : inds[i]) {
			md[i][j] = 0;
			que.push_back(j);
		}
		for (int g = 0; g < n; ++g) {
			int j = que[g];
			for (auto t : conns[j]) {
				if (md[i][t] == inf) {
					md[i][t] = md[i][j] + 1;
					que.push_back(t);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		std::vector<int> vals (k);
		for (int j = 0; j < k; ++j) vals[j] = md[j][i];
		sort(vals.begin(), vals.end());
		long long cost = 0;
		for (int j = 0; j < s; ++j) cost += vals[j];
		std::cout << cost << ' ';
	}
	std::cout << '\n';
}