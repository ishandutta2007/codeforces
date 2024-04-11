#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
const int N = 1e6;
const int M = 1e6;
set<pair<int, int>> cheap[N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cheap[i].insert({-1,0});
	}
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a; --b;
		auto it = cheap[a].lower_bound({w, 0});
		--it; // We always have a weight -1 in these, so this can't break
		int cou = 1 + (*it).second;
		// You can get a path with cou edges and cost w at node b
		
		// Cheaper
		it = cheap[b].lower_bound({w, 0});
		--it;
		if ((*it).second >= cou) continue;
		
		// Equal
		it = cheap[b].lower_bound({w, 0});
		if ((it != cheap[b].end()) && ((*it).first == w)) {
			if ((*it).second >= cou) continue; // Theirs is equal or better
			cheap[b].erase(it); // Ours is better
		}
		
		// More expensive
		while(true) {
			it = cheap[b].lower_bound({w+1, 0});
			if (it == cheap[b].end()) break;
			if ((*it).second <= cou) {
				cheap[b].erase(it);
			} else {
				break;
			}
		}

		cheap[b].insert({w, cou});
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		auto it = cheap[i].end();
		--it;
		ans = max(ans, (*it).second);
	}
	std::cout << ans << '\n';
}