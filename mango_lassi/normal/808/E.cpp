#include <iostream>
#include <vector>
#include <algorithm>

const int N = 1e5;
long long w[N];
long long c[N];

std::vector<std::pair<long long, int> > items;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		std::cin >> w[i] >> c[i];
		items.push_back(std::make_pair( -6 * c[i] / w[i], i));
	}
	std::sort(items.begin(), items.end());
	long long vals [10];
	for (int i = 0; i < 10; ++i) {
		vals[i] = 0;
	}
	int base = 0; // Vals are values for base, base+1, ..., base+9
	int high = 0; // Highest point with non-zero number in vals
	for (int i = 0; i < (int)items.size(); ++i) {
		// Find index
		int ind = items[i].second;
		// Go up
		for (int j = 9 - w[ind]; j >= 0; --j) {
			if (vals[j]) {
				vals[j + w[ind]] = std::max(vals[j + w[ind]], vals[j] + c[ind]);
			}
		}
		// Handle base case
		if (base == 0) {
			vals[w[ind]] = std::max(vals[w[ind]], vals[0] + c[ind]);
		}
		// Move back so that only the first 6 slots have been filled
		high += w[ind];
		if (high > 5) {
			int dist = std::max(std::min(high - 5, m - base - 9), 0);
			base += dist;
			high -= dist;
			for (int j = 0; j < dist; ++j) {
				vals[j] = 0;
			}
			for (int j = dist; j < 10; ++j) {
				long long tmp = vals[j];
				vals[j] = 0;
				vals[j - dist] = tmp;
			}
		}
	}
	long long max = 0;
	for (int i = base; (i <= m) && (i < base + 10); ++i) {
		if (vals[i - base] > max) {
			max = vals[i - base];
		}
	}
	std::cout << max << '\n';
}