#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int T = 2 * (1e5);
int count [T + 1];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k, q;
	std::cin >> n >> k >> q;
	
	std::vector<std::pair<int, int> > events;

	for (int i = 0; i < n; ++i) {
		int a, b;
		std::cin >> a >> b;
		events.push_back(std::make_pair(a, 1));
		events.push_back(std::make_pair(b+1, -1));
	}
	std::sort(events.begin(), events.end());
	int c = 0;
	int ind = 0;
	count[0] = 0;
	for (int i = 1; i <= T; ++i) {
		while( (ind < events.size()) && (events[ind].first == i) ) {
			c += events[ind].second;
			++ind;
		}
		if (c >= k) {
			count[i] = count[i-1] + 1;
		} else {
			count[i] = count[i-1];
		}
	}
	for (int j = 0; j < q; ++j) {
		int a, b;
		std::cin >> a >> b;
		std::cout << count[b] - count[a-1] << '\n';
	}
}