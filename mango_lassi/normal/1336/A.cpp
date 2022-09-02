#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e5;
vector<int> conns[N];
vector<int> siz, dep;

void dfs(int i, int p) {
	dep[i] = dep[p] + 1;
	for (auto t : conns[i]) {
		if (t == p) continue;
		dfs(t, i);
		siz[i] += siz[t];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	siz.resize(n, 1);
	dep.resize(n, 0);
	dfs(0, 0);

	for (int i = 0; i < n; ++i) dep[i] -= siz[i];
	sort(dep.begin(), dep.end());

	ll res = 0;
	for (; k > 0; --k) {
		res += dep.back();
		dep.pop_back();
	}
	cout << res << '\n';
}