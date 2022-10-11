#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int d;
	cin >> d;
	int n = (1 << d) - 2;
	if (n == 2)
		return cout << "2\n1 2\n", 0;

	vector<vector<int>> g(n);
	vector<int> deg(n, 0);
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].push_back(u);
		g[u].push_back(v);
		deg[v]++, deg[u]++;
	}

	for (int i = 0; i < n; i++)
		if (deg[i] > 4)
			return cout << "0\n", 0;

	unordered_map<int, vector<int>> mapa;
	for (int i = 0; i < n; i++)
		mapa[deg[i]].push_back(i);

	int last = (1 << d - 1);
	if (mapa[4].size()) {
		if (mapa[4].size() != 1)
			return cout << "0\n", 0;

		if (!(mapa[2].size() == 1 && mapa[1].size() == last && mapa[3].size() == n - 2 - last))
			return cout << "0\n", 0;

		int maybe = mapa[4][0];

		vector<int> now = mapa[1];
		vector<char> used(n, 0);
		for (auto v : now)
			used[v] = 1;

		bool can = true;
		for (int i = 0; i < d - 1; i++) {
			vector<int> nnow;
			for (auto v : now)
				if (v == maybe && can) {
					can = false;
					nnow.push_back(maybe);
				}

			for (auto v : now)
				if (v != maybe)
					for (auto u : g[v])
						if (!used[u]) {
							used[u] = 1;
							nnow.push_back(u);
						}

			if (nnow.size() != now.size() / 2)
				return cout << "0\n", 0;
			now = nnow;
		}

		cout << "1\n" << maybe + 1 << '\n';
		return 0;
	}

	if (mapa[1].size() == last - 1) {
		if (mapa[2].size() != 2 || mapa[3].size() != n - last - 1)
			return cout << "0\n", 0;
 
		vector<int> valid;
		for (auto v : mapa[2]) {
			int cnt = 0;
			for (auto u : g[v])
				cnt += (deg[u] == 1);
			if (cnt == 1)
				valid.push_back(v);
		}
 
		if (valid.size() != 1)
			return cout << "0\n", 0;

		int maybe = valid[0];

		vector<int> now = mapa[1];
		now.push_back(now.back());
		vector<char> used(n, 0);
		for (auto v : now)
			used[v] = 1;

		for (int i = 0; i < d - 1; i++) {
			vector<int> nnow;
			for (auto v : now)
				for (auto u : g[v])
					if (!used[u]) {
						used[u] = 1;
						nnow.push_back(u);
					}

			if (nnow.size() != now.size() / 2)
				return cout << "0\n", 0;
			now = nnow;
		}

		cout << "1\n" << valid[0] + 1;
		return 0;
	}

	if (mapa[1].size() != last)
		return cout << "0\n", 0;

	vector<int> now = mapa[1];
	vector<char> used(n, 0);
	for (auto v : now)
		used[v] = 1;

	for (int i = 0; i < d - 2; i++) {
		vector<int> nnow;
		for (auto v : now)
			for (auto u : g[v])
				if (!used[u]) {
					used[u] = 1;
					nnow.push_back(u);
				}

		if (nnow.size() != now.size() / 2)
			return cout << "0\n", 0;
		now = nnow;
	}

	sort(now.begin(), now.end());
	if (now.size() != 2)
		cout << "0\n";
	else
		cout << "2\n" << now[0] + 1 << ' ' << now[1] + 1 << '\n';
}