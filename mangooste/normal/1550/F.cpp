#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q, s, d;
	cin >> n >> q >> s >> d;
	vector<int> a(n);
	set<pair<int, int>> st;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.emplace(a[i], i);
	}

	vector<int> dist(n, INT_MAX);
	dist[--s] = 0;
	set<array<int, 3>> pq{{0, s, -1}};

	auto relax = [&](int v) {
		if (v == -1) return;

		for (int x : {a[v] - d, a[v] + d}) {
			auto relax = [&](int u) {
				int new_d = max(dist[v], abs(a[u] - x));
				dist[u] = min(dist[u], new_d);
				pq.insert({new_d, u, v});
			};

			auto it = st.lower_bound({x, -1});
			if (it != st.end()) relax(it->second);
			if (it != st.begin()) relax((--it)->second);
		}
	};

	while (!pq.empty()) {
		auto [cur_d, v, from] = *pq.begin();
		pq.erase(pq.begin());
		st.erase({a[v], v});
		relax(from);
		if (cur_d == dist[v]) relax(v);
	}

	while (q--) {
		int i, k;
		cin >> i >> k;
		cout << (dist[--i] <= k ? "YES" : "NO") << '\n';
	}
}