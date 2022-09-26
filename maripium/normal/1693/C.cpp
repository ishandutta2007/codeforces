#include <bits/stdc++.h>

#include<bits/extc++.h>

template <typename K, typename V, typename Comp = std::less<K>>
using order_statistic_map = __gnu_pbds::tree<
	K, V, Comp,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>;

template <typename K, typename Comp = std::less<K>>
using order_statistic_set = order_statistic_map<K, __gnu_pbds::null_type, Comp>;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<vector<int>> inEdges(N);
	vector<order_statistic_set<pair<int, int>>> outDists(N);

	const int INF = 1e9;

	vector<int> v(M);
	for (int e = 0; e < M; ++e) {
		int u; cin >> v[e] >> u;
		--v[e], --u;
		inEdges[u].push_back(e);
		outDists[v[e]].insert({INF, e});
	} 

	vector<bool> used(N);

	vector<int> dist(N, INF);

	set<pair<int, int>> dists;
	for (int i = 0; i < N; ++i) dists.insert({INF, i});

	dists.erase({INF, N - 1});
	dist[N - 1] = 0;
	dists.insert({0, N - 1});

	for (int z = 0; z < N; ++z) {
		auto [d, u] = *dists.begin();
		dists.erase(dists.begin());
		used[u] = true;

		for (int e : inEdges[u]) {
			outDists[v[e]].erase({INF, e});
			outDists[v[e]].insert({dist[u], e});

			int newDist = 1 + dist[u] + outDists[v[e]].size() - outDists[v[e]].order_of_key({dist[u], INF});
			if (dist[v[e]] > newDist) {
				dists.erase({dist[v[e]], v[e]});
				dist[v[e]] = newDist;
				dists.insert({dist[v[e]], v[e]});
			}
		}
	}

	cout << dist[0] << '\n';
	return 0;
}