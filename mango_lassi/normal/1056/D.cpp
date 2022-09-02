#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1e5;
vector<int> conns[N];
vector<int> leaf;

void dfs(int i, int p) {
	for (auto t : conns[i]) {
		if (t == p) continue;
		dfs(t, i);
		leaf[i] += leaf[t];
	}
	if (conns[i].size() == 1 && i != p) ++leaf[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	if (n == 1) {
		cout << "1\n";
	} else {
		leaf.resize(n);
		for (int i = 1; i < n; ++i) {
			int p;
			cin >> p;
			--p;
			conns[p].push_back(i);
			conns[i].push_back(p);
		}
		dfs(0, 0);

		sort(leaf.begin(), leaf.end());
		for (int i = 0; i < n; ++i) cout << leaf[i] << ' '; cout << '\n';
	}
}