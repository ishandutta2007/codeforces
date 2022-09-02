#include <iostream>
#include <vector>

const int W = 100;
const int H = 100;
const int inf = 1e9 + 7;
int vals [W][H];
int min_rows [H];
int min_cols [W];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int h, w;
	std::cin >> h >> w;

	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			std::cin >> vals[x][y];
		}
	}

	for (int x = 0; x < w; ++x) {
		min_cols[x] = inf;
		for (int y = 0; y < h; ++y) {
			min_cols[x] = std::min(min_cols[x], vals[x][y]);
		}
	}
	for (int y = 0; y < h; ++y) {
		min_rows[y] = inf;
		for (int x = 0; x < w; ++x) {
			min_rows[y] = std::min(min_rows[y], vals[x][y]);
		}
	}

	// row? ind
	std::vector< std::pair<bool, int> > moves;
	if (w > h) {
		for (int y = 0; y < h; ++y) {
			for (int i = 0; i < min_rows[y]; ++i) {
				moves.push_back(std::make_pair(true, y+1));
			}
			for (int x = 0; x < w; ++x) {
				vals[x][y] -= min_rows[y];
			}
		}
	} else {
		for (int x = 0; x < w; ++x) {
			for (int i = 0; i < min_cols[x]; ++i) {
				moves.push_back(std::make_pair(false, x+1));
			}
			for (int y = 0; y < h; ++y) {
				vals[x][y] -= min_cols[x];
			}
		}
	}
	
	for (int x = 0; x < w; ++x) {
		min_cols[x] = inf;
		for (int y = 0; y < h; ++y) {
			min_cols[x] = std::min(min_cols[x], vals[x][y]);
		}
	}
	for (int y = 0; y < h; ++y) {
		min_rows[y] = inf;
		for (int x = 0; x < w; ++x) {
			min_rows[y] = std::min(min_rows[y], vals[x][y]);
		}
	}

	if (w <= h) {
		for (int y = 0; y < h; ++y) {
			for (int i = 0; i < min_rows[y]; ++i) {
				moves.push_back(std::make_pair(true, y+1));
			}
			for (int x = 0; x < w; ++x) {
				vals[x][y] -= min_rows[y];
			}
		}
	} else {
		for (int x = 0; x < w; ++x) {
			for (int i = 0; i < min_cols[x]; ++i) {
				moves.push_back(std::make_pair(false, x+1));
			}
			for (int y = 0; y < h; ++y) {
				vals[x][y] -= min_cols[x];
			}
		}
	}

	bool can = true;
	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y) {
			if (vals[x][y]) {
				can = false;
			}
		}
	}
	if (can) {
		std::cout << moves.size() << '\n';
		for (int i = 0; i < moves.size(); ++i) {
			std::cout << (moves[i].first ? "row " : "col ") << moves[i].second << '\n';
		}
	} else {
		std::cout << "-1\n";
	}
}