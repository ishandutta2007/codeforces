#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
vector<pair<int, int>> conns[N];
int ind[N-1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].emplace_back(b, i);
		conns[b].emplace_back(a, i);
	}
	int x = -1;
	for (int i = 0; i < n; ++i) {
		if (conns[i].size() >= 3) x = i;
	}
	if (x == -1) {
		for (int i = 0; i < n-1; ++i) cout << i << ' '; cout << '\n';
	} else {
		for (int j = 0; j < 3; ++j) ind[conns[x][j].second] = j+1;
		int cur = 4;
		for (int i = 0; i < n-1; ++i) {
			if (! ind[i]) {
				ind[i] = cur;
				++cur;
			}
		}
		for (int i = 0; i < n-1; ++i) cout << ind[i]-1 << ' '; cout << '\n';
	}
}