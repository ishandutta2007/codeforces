#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<pii> dist(n, {oo, 0});

	dist[0] = {0, 0};

	vector<vector<pii>> adj(n);

	for (int i = 0; i < m; ++i){
		int u, v;
		int64 w;
		cin >> u >> v >> w;
		u--; v--;

		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}


	for (int i = 0; i < k; ++i){
		int u;
		int64 w;
		cin >> u >> w;
		u--;

		dist[u].first = min(dist[u].first, w);
		dist[u].second = 1;
	}

	set<pair<pii,int>> q;

	for (int i = 0; i < n; ++i)
		q.insert({dist[i], i});

	int answer = 0;

	while (!q.empty()){
		auto cur = *q.begin();

		q.erase(q.begin());

		pii d = cur.first;
		int u = cur.second;

		if (d.second) answer++;

		for (auto e : adj[u]){
			int v = e.second;
			int64 w = e.first;

			if (pii(w + d.first, 0) < dist[v]){
				q.erase({dist[v], v});
				dist[v] = pii(w + d.first, 0);
				q.insert({dist[v], v});
			}
		}
	}

	cout << k - answer << endl;

	return 0;
}