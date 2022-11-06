#include <algorithm>
#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <vector>

const int N = 2e5 + 5;
const int sN = 500;

int n, K[N], w[N];
std::vector<int> ele[N];
std::vector<int> all;

std::vector<int> large;
std::vector<int> small;
std::unordered_map<int, int> rec[N];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", K + i), ele[i].resize(K[i]);
		for (auto& it : ele[i]) scanf("%d", &it);
	}
	
	all.clear();
	for (int i = 1; i <= n; i++)
		all.insert(all.end(), ele[i].begin(), ele[i].end());
	std::sort(all.begin(), all.end());
	all.erase(std::unique(all.begin(), all.end()), all.end());
	for (int i = 1; i <= n; i++) for (auto& it : ele[i])
		it = std::lower_bound(all.begin(), all.end(), it) - all.begin() + 1;
	for (int i = 1; i <= int(all.size()); i++) w[i] = 0, rec[i].clear();
	
	int gap = (int)sqrt(n);
	small.clear(), large.clear();
	for (int i = 1; i <= n; i++)
		if (K[i] > gap) large.push_back(i);
		else small.push_back(i);
	for (int i = 1; i <= n; i++)
		std::sort(ele[i].begin(), ele[i].end());
	
	for (auto i : large) {
		for (auto it : ele[i]) w[it] = 1;
		for (auto j : large) if (i < j) {
			int vaild = 0;
			for (auto it : ele[j]) if (w[it] == 1) ++vaild;
			if (vaild >= 2) { printf("%d %d\n", i, j); return; }
		}
		for (auto it : ele[i]) w[it] = 0;
	} // large - large
	
	for (auto i : large) {
		for (auto it : ele[i]) w[it] = 1;
		for (auto j : small) {
			int vaild = 0;
			for (auto it : ele[j]) if (w[it] == 1) ++vaild;
			if (vaild >= 2) { printf("%d %d\n", i, j); return; }
		}
		for (auto it : ele[i]) w[it] = 0;
	} // large - small
	
	for (auto s : small) {
		for (int i = 0; i < K[s]; i++)
			for (int j = i + 1; j < K[s]; j++) {
				auto it = rec[ele[s][i]].find(ele[s][j]);
				if (it != rec[ele[s][i]].end()) { printf("%d %d\n", it->second, s); return; }
				rec[ele[s][i]][ele[s][j]] = s;
			}
	} // small - small
	
	puts("-1");
}

signed main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}