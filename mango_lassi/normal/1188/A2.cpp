#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 1e5;
vector<pair<int, ll>> conns[N];
vector<pair<ll, pair<int, int>>> ops;
ll par_w[N];

// Returns a leaf from below
int dfs(int i, int p, int r) {
	if (conns[i].size() == 1 && i != r) {
		ops.push_back({par_w[i], {i, r}});
		return i;
	} else {
		ll sum = 0;
		vector<int> leaves;
		for (auto pr : conns[i]) {
			int t = pr.first;
			if (t == p) continue;
			par_w[t] = pr.second;
			sum += par_w[t];

			int leaf = dfs(t, i, r);
			if (leaf == -1) return -1;
			else leaves.push_back(leaf);
		}
		if (i != r && sum != par_w[i]) {
			if (leaves.size() <= 1) return -1;
			ll h = (par_w[i] - sum) / 2;
			ops.push_back({-h, {leaves[0], leaves[1]}});
			ops.push_back({h, {r, leaves[0]}});
			ops.push_back({h, {r, leaves[1]}});
		}
		return leaves[0];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		ll v;
		cin >> a >> b >> v;
		--a; --b;
		conns[a].push_back({b, v});
		conns[b].push_back({a, v});
	}

	int j = -1;
	for (int i = 0; j == -1; ++i) {
		if (conns[i].size() == 1) j = i;
	}

	ll res = dfs(j, j, j);
	if (res == -1) cout << "NO\n";
	else {
		cout << "YES\n";
		cout << ops.size() << '\n';
		for (auto it : ops) {
			cout << it.second.first+1 << ' ' << it.second.second+1 << ' ' << it.first << '\n';
		}
	}
}