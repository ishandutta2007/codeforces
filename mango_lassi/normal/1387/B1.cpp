#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
vector<int> conns[N];
int dep[N];
int par[N];
int res[N];

void dfs(int i, int p = -1) {
	par[i] = p;
	for (auto t : conns[i]) {
		if (t == p) continue;
		dep[t] = dep[i] + 1;
		dfs(t, i);
	}
}

// Greedy works: always swap deepest original with its parent

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Tree DP: from every branch, we want min cost with one coming out, and with zero coming out

	int n;
	cin >> n;

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	dfs(0);

	vector<pair<int, int>> ord(n);
	for (int i = 0; i < n; ++i) ord[i] = {-dep[i], i};
	sort(ord.begin(), ord.end());
	
	int sum = 0;
	for (int i = 0; i < n; ++i) res[i] = i;
	for (int j = 0; j < n; ++j) {
		int i = ord[j].second;
		if (res[i] == i) {
			if (i == 0) {
				swap(res[ord[j-1].second], res[i]);
				sum += 2;
			} else {
				swap(res[par[i]], res[i]);
				sum += 2;
			}
		}
	}

	cout << sum << '\n';
	for (int i = 0; i < n; ++i) cout << res[i] + 1 << ' '; cout << '\n';
}