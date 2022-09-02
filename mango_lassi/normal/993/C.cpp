#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int H = 20 + (int)(1e4);
const int M = 60;

int yi[2][M];
int dst[2*M];

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		v = (v + H) * 2;
		yi[0][i] = v;
	}
	for (int i = 0; i < m; ++i) {
		int v;
		std::cin >> v;
		v = (v + H) * 2;
		yi[1][i] = v;
	}
	std::vector<std::pair<int, std::pair<int, int>>> wins;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			int mi = (yi[0][a] + yi[1][b]) / 2;
			wins.push_back({mi, {a, b}});
		}
	}
	std::sort(wins.begin(), wins.end());
	std::vector<std::pair<int, std::vector<int>>> dlist;
	for (int i = 0; i < wins.size(); ++i) {
		if (dlist.empty() || (wins[i].first != dlist.back().first)) {
			dlist.push_back({wins[i].first, {}});
		}
		dlist.back().second.push_back(wins[i].second.first);
		dlist.back().second.push_back(wins[i].second.second + M);
	}
	for (int i = 0; i < dlist.size(); ++i) {
		std::sort(dlist[i].second.begin(), dlist[i].second.end());
		dlist[i].second.erase(std::unique(dlist[i].second.begin(), dlist[i].second.end()), dlist[i].second.end());
	}
	int best = 0;
	int cou = 0;
	for (int a = 0; a < dlist.size(); ++a) {
		for (int i : dlist[a].second) {
			++dst[i];
			if (dst[i] == 1) ++cou;
		}

		best = std::max(best, cou);

		for (int b = a + 1; b < dlist.size(); ++b) {
			for (int i : dlist[b].second) {
				++dst[i];
				if (dst[i] == 1) ++cou;
			}

			best = std::max(best, cou);

			for (int i : dlist[b].second) {
				--dst[i];
				if (dst[i] == 0) --cou;
			}
		}
		for (int i : dlist[a].second) {
			--dst[i];
			if (dst[i] == 0) --cou;
		}
	}
	std::cout << best << '\n';
}