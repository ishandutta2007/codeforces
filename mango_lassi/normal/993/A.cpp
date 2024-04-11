#include <iostream>

const int N = 4;
const int M = 300;
const int K = 120;
std::pair<int, int> pol[2][N];
int app[M][M];
bool use[M][M];

int norm(int v) {
	return (v < 0 ? -1 : (v == 0 ? 0 : 1));
}

int dfs(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= M) return 0;
	if (use[x][y]) return 0;
	use[x][y] = true;
	if (app[x][y] != 0) return app[x][y];
	int res = 0;
	res |= dfs(x-1, y);
	res |= dfs(x+1, y);
	res |= dfs(x, y-1);
	res |= dfs(x, y+1);
	return res;
}

int main() {
	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < N; ++i) {
			int x, y;
			std::cin >> x >> y;
			x += K;
			y += K;
			pol[j][i] = {x, y};
		}
		for (int i = 0; i < N; ++i) {
			int ni = (i + 1) % N;
			int x = pol[j][i].first;
			int y = pol[j][i].second;
			int tx = pol[j][ni].first;
			int ty = pol[j][ni].second;
			int dx = norm(tx - x);
			int dy = norm(ty - y);
			while((x != tx) || (y != ty)) {
				app[x][y] |= (1<<j);
				x += dx;
				y += dy;
			}
		}
	}
	int found = dfs(0, 0);
	if (found == 3) {
		found = 0;
		for (int x = 0; x < M; ++x) {
			for (int y = 0; y < M; ++y) {
				if (app[x][y] == 3) found = 3;
			}
		}
	} else {
		found = 3;
	}
	if (found == 3) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}