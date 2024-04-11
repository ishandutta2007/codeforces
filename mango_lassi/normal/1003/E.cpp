#include <iostream>
#include <vector>

const int N = 4 * (int)1e5;
std::vector<int> conns[N];

// To minimize diameter, always have maximum branching
bool build(int i, int& j, int jl, int deg_lim, int dep_min, int dep_max) {
	// std::cout << "BUILD " << i << ' ' << j << ' ' << jl << ' ' << deg_lim << ' ' << dep_min << ' ' << dep_max << '\n';
	bool res = (dep_min <= 1);
	if (dep_max == 1) return res;
	for (int s = 0; s < deg_lim - 1; ++s) {
		if (j == jl) return res;
		conns[i].push_back(j);
		++j;
		res |= build(j-1, j, jl, deg_lim, dep_min-1, dep_max-1);
	}
	return res;
}


int main() {
	int n, d, k;
	std::cin >> n >> d >> k;
	int j = 1;
	int dep = d / 2;
	bool fail = false;
	fail |= (d >= n);
	for (int i = 0; (i < k) && (j < n) && (!fail); ++i) {
		if (j == n) break;
		int cur_dep = dep;
		if (dep * 2 != d) {
			++cur_dep;
			--d;
		}
		if (cur_dep == 0) break;
		int lim = (i == 0 ? n - dep : n);
		int dmi = (i < 2 ? cur_dep : 1);
		conns[0].push_back(j);
		++j;
		bool sub = build(j-1, j, lim, k, dmi, cur_dep);
		fail |=! sub;
	}
	if (fail || j != n) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			for (auto t : conns[i]) {
				if (t > i) std::cout << (i+1) << ' ' << (t+1) << '\n';
			}
		}
	}
}