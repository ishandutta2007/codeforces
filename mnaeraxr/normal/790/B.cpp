#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

int n, k;
int64 answer;

vi adj[ maxn ];

pair<vector<int64>, vector<int64>> dfs(int u, int p){
	vector<int64> freq(k);
	vector<int64> dist(k);

	freq[0]++;

	for (auto v : adj[u]){
		if (v == p) continue;

		auto cur = dfs(v, u);
		vector<int64> f(k), d(k);

		for (int i = 0; i < k; ++i){
			f[ (i + 1) % k ] = cur.first[i];
			d[ (i + 1) % k ] = cur.second[i];
		}

		d[0] += f[0];

		for (int i = 0; i < k; ++i){
			for (int j = 0; j < k; ++j){
				int64 cdist = dist[i] * f[j];
				      cdist += d[j] * freq[i];
				      cdist += 1LL * (i + j + k - 1) / k * freq[i] * f[j];

				answer += cdist;
			}
		}

		for (int i = 0; i < k; ++i){
			freq[i] += f[i];
			dist[i] += d[i];
		}
	}

	return {freq, dist};
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i + 1 < n; ++i){
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	answer = 0;
	dfs(1, -1);

	cout << answer << endl;

	return 0;
}
/*
3 2
1 2
2 3
 */