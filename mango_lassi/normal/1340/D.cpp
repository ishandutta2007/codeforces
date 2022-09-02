#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
vector<int> conns[N];
vector<pair<int, int>> res;
int high;

void dfs(int i, int p, int cur) {
	int tar = cur - 1;
	int rem = (int)conns[i].size() - 1;

	res.emplace_back(i, cur);
	for (auto t : conns[i]) {
		if (t == p) continue;

		if (cur == high) {
			res.emplace_back(i, tar - rem);
			cur = tar - rem;
		}

		++cur;
		dfs(t, i, cur);
		res.emplace_back(i, cur);
		--rem;
	}
	if (cur != tar) res.emplace_back(i, tar);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	//	Assume that from any subtree, if entering at time x, it is at least possible to
	//		- return at any time 1 <= t <= x
	//		- as long as d <= m
	//	-> maximum t is max(d)

	high = 0;
	for (int i = 0; i < n; ++i) high = max(high, (int)conns[i].size());

	for (int i = 0; i < conns[0].size(); ++i) {
		res.emplace_back(0, i);
		dfs(conns[0][i], 0, i+1);
	}
	res.emplace_back(0, (int)conns[0].size());

	cout << res.size() << '\n';
	for (auto pr : res) cout << pr.first + 1 << ' ' << pr.second << '\n';
}