#include <iostream>
#include <vector>

const int N = 2 * (int)1e5;

long long val[N];
std::vector<int> els[N];
int n, m;

long long dist(long long a, long long b) {
	if (b < a) return b - a + m;
	else return b - a;
}

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> val[i];
		els[val[i] % m].push_back(i);
	}
	std::vector<int> carried;
	long long need = n / m;
	long long cost = 0;
	for (int i = 0; i < 2 * m; ++i) {
		// std::cout << i << ' ' << cou[i % m] << ' ' << carry << '\n';
		while((els[i % m].size() < need) && (carried.size() > 0)) {
			int bi = carried.back();
			carried.pop_back();
			els[i % m].push_back(bi);

			long long di = dist(val[bi] % m, i);
			val[bi] += di;
			cost += di;
		}
		while(els[i % m].size() > need) {
			carried.push_back(els[i % m].back());
			els[i % m].pop_back();
		}
	}
	std::cout << cost << '\n';
	for (int i = 0; i < n; ++i) std::cout << val[i] << ' '; std::cout << '\n';
}