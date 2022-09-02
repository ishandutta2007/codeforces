#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	
	vector<int> par(n);
	for (int i = 0; i < n; ++i) {
		cin >> par[i];
		--par[i];
	}

	bool fail = 0;
	vector<int> nxt(n, -1), pre(n, -1);
	for (int j = 0; j < k; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (nxt[a] != -1) fail = 1;
		if (pre[b] != -1) fail = 1;
		nxt[a] = b;
		pre[b] = a;
	}

	vector<int> rev, perm(n, -1);

	for (int i = 0; i < n; ++i) {
		if (pre[i] != -1) continue;

		for (int j = i; j != -1 && !fail; j = nxt[j]) {
			if (perm[j] != -1) fail = 1; // cycle
			perm[j] = rev.size();
		}
		rev.push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		if (perm[i] == -1) fail = 1;
	}

	if (fail) {
		cout << 0 << '\n';
		return;
	}

	int m = rev.size();
	vector<vector<int>> g(m);
	for (int i = 0; i < n; ++i) {
		if (pre[i] != -1) continue;

		set<int> reqs, seen;
		for (int j = i; j != -1; j = nxt[j]) {
			if (reqs.find(j) != reqs.end()) fail = 1;
			seen.insert(j);

			if (par[j] != -1) {
				if (seen.find(par[j]) == seen.end()) {
					reqs.insert(par[j]);
					g[perm[par[j]]].push_back(perm[j]);
				}
			}
		}
	}

	vector<int> ins(m, 0), que, res;
	for (int i = 0; i < m; ++i) {
		for (auto t : g[i]) ++ins[t];
	}
	for (int i = 0; i < m; ++i) {
		if (ins[i] == 0) que.push_back(i);
	}

	for (int j = 0; j < que.size(); ++j) {
		int ind = que[j];
		for (int i = rev[ind]; i != -1; i = nxt[i]) res.push_back(i);
		for (auto t : g[ind]) {
			--ins[t];
			if (ins[t] == 0) que.push_back(t);
		}
	}

	if (res.size() < n) fail = 1;

	if (fail) {
		cout << 0 << '\n';
		return;
	} else {
		for (auto i : res) cout << i+1 << ' '; cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}