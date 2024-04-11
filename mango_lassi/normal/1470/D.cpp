#include <bits/stdc++.h>
using namespace std;

const int N = 3 * (int)1e5;
vector<int> conns[N];
bool act[N];
bool adj[N];

void addInd(int i, vector<int>& res, vector<int>& que) {
	if (adj[i]) return;
	res.push_back(i);
	for (auto t : conns[i]) {
		if (adj[t]) continue;
		adj[t] = 1;
		for (auto t2 : conns[t]) {
			if (act[t2]) continue;
			act[t2] = 1;
			que.push_back(t2);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	vector<int> res;
	vector<int> que = {0};
	act[0] = 1;
	for (int j = 0; j < que.size(); ++j) {
		addInd(que[j], res, que);
	}
	
	bool fail = 0;
	for (int i = 0; i < n; ++i) {
		if (!act[i] && !adj[i]) fail = 1;
	}

	if (fail) cout << "NO\n";
	else {
		cout << "YES\n";
		cout << res.size() << '\n';
		for (auto v : res) cout << v+1 << ' '; cout << '\n';
	}

	for (int j = 0; j < n; ++j) {
		conns[j].clear();
		act[j] = 0;
		adj[j] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}