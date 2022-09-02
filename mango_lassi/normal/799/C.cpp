#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int N = 1e5;
const int inf = 1e9 + 7;
int cost [2];
int tota [2];
int best [2][N];
int seco [2][N];
std::vector<std::pair<int, int> > vals [2];

int main() {
	tota[0] = -inf;
	tota[1] = -inf;
	int n;
	std::cin >> n >> cost[0] >> cost[1];
	for (int i = 0; i < n; ++i) {
		int b, p; char t;
		std::cin >> b >> p >> t;
		if (t == 'C') {
			vals[0].push_back(std::make_pair(p, b));
			if (p <= cost[0]) {
				tota[0] = std::max(tota[0], b);
			}
		} else {
			vals[1].push_back(std::make_pair(p, b));
			if (p <= cost[1]) {
				tota[1] = std::max(tota[1], b);
			}
		}
	}
	for (int i = 0; i < 2; ++i) {
		std::sort(vals[i].begin(), vals[i].end());
	}
	for (int j = 0; j < 2; ++j) {
		if (! vals[j].empty()) {
			best[j][0] = vals[j][0].second;
			seco[j][0] = -inf;
			for (int i = 1; i < vals[j].size(); ++i) {
				best[j][i] = best[j][i-1];
				seco[j][i] = seco[j][i-1];
				int b = vals[j][i].second;
				if (b >= best[j][i]) {
					seco[j][i] = best[j][i];
					best[j][i] = b;
				} else if (b > seco[j][i]) {
					seco[j][i] = b;
				}
			}
		}
	}
	int max = -1;
	for (int j = 0; j < 2; ++j) {
		int b = vals[j].size() - 1;
		for (int a = 0; a < vals[j].size(); ++a) {
			while((a < b) && (vals[j][a].first + vals[j][b].first > cost[j])) {
				--b;
			}
			if (a >= b) {
				break;
			}
			max = std::max(max, best[j][a] + ((best[j][a] == best[j][b]) ? (seco[j][b]) : (best[j][b])));
		}
	}
	max = std::max(tota[0] + tota[1], max);
	if (max <= -1) {
		std::cout << "0\n";
	} else {
		std::cout << max << '\n';
	}
}