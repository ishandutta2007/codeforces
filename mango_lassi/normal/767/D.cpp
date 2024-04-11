#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int N = 1e6;
const int M = 1e6;
long long below[N + M];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	long long k;
	std::cin >> n >> m >> k;

	std::vector<long long> home;
	std::vector<std::pair<long long, int> > shop;
	for (int i = 0; i < n; ++i) {
		long long d;
		std::cin >> d;
		home.push_back(d);
	}
	for (int i = 1; i <= m; ++i) {
		long long d;
		std::cin >> d;
		shop.push_back(std::make_pair(d, i));
	}
	std::sort(home.begin(), home.end());
	std::sort(shop.begin(), shop.end());
	std::vector<long long> comb;
	int a = 0;
	for (int i = 0; i < shop.size(); ++i) {
		while((a < home.size()) && (home[a] < shop[i].first)) {
			comb.push_back(home[a]);
			++a;
		}
		comb.push_back(shop[i].first);
	}
	for (int i = a; i < home.size(); ++i) {
		comb.push_back(home[i]);
	}
	a = 0;
	std::vector<int> min;
	for (int i = 0; i < comb.size(); ++i) {
		int d = comb[i];
		while ((a < home.size()) && (home[a] <= d)) {
			++a;
		}
		below[i] = a;
		long long lee = ((d + 1) * k) - a;
		while(!min.empty()) {
			int top = min[min.size() - 1];
			if (((comb[top] + 1) * k - below[top]) >= lee) {
				min.pop_back();
			} else {
				break;
			}
		}
		min.push_back(i);
	}
	a = 0;
	int top = min[0];
	long long lee = (comb[top] + 1) * k - below[top];
	if (lee < 0) {
		std::cout << "-1\n";
	} else {
		std::vector<int> add;
		for (int i = 0; i < shop.size(); ++i) {
			if (lee == 0) {
				while((i < shop.size()) && (shop[i].first <= comb[top])) {
					++i;
				}
				if (i == shop.size()) {
					break;
				}
				++a;
				top = min[a];
				lee = (comb[top] + 1) * k - below[top] - add.size();	
			}
			add.push_back(shop[i].second);
			--lee;
		}
		std::cout << add.size() << "\n";
		for (int i = 0; i < add.size(); ++i) {
			std::cout << add[i] << " ";
		}
		std::cout << "\n";
	}
}