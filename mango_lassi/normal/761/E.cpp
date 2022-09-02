#include <iostream>
#include <vector>
#include <utility>

const int N = 30;
std::vector<int> conns[N];
std::pair<long long, long long> cords [N]; 

std::pair<long long, long long> dirs[4];

void build(int ind, int ban, int prev, long long dist) {
	int dir = 0;
	for (int i = 0; i < (int)(conns[ind].size()); ++i) {
		int t = conns[ind][i];
		if (t == prev) { continue; }
		if (dir == ban) { ++dir; }
		cords[t] = std::make_pair(cords[ind].first + dirs[dir].first * dist, cords[ind].second + dirs[dir].second * dist);
		build(t, (dir + 2) % 4, ind, dist / 2);
		++dir;
	}
}

int main() {
	dirs[0] = std::make_pair(1, 0);
	dirs[1] = std::make_pair(0, 1);
	dirs[2] = std::make_pair(-1, 0);
	dirs[3] = std::make_pair(0, -1);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::vector<int> vec;
		conns[i] = vec;
	}

	int a, b;
	for (int i = 0; i < n-1; ++i) {
		std::cin >> a >> b;
		--a;
		--b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	int max = 0;
	int ind = 0;
	for (int i = 0; i < n; ++i) {
		if ((int)(conns[i].size()) > max) {
			max = conns[i].size();
			ind = i;
		}
	}
	if (max > 4) {
		std::cout << "NO\n";
	} else {
		cords[ind] = std::make_pair(0, 0);
		build(ind, -1, -1, 1ll<<32);
		std::cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			std::cout << cords[i].first << " " << cords[i].second << "\n";
		}
	}

}