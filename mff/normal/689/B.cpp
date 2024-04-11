#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200010;

vi adj[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= n; ++i){
		int v; cin >> v;
		adj[i].push_back(v);
		if (i < n) adj[i].push_back(i + 1);
		if (i > 1) adj[i].push_back(i - 1);
	}

	vector<int> dist(n + 1, oo);
	dist[1] = 0;
	queue<int> q; q.push(1);

	while (!q.empty()){
		int u = q.front(); q.pop();

		for (auto v : adj[u]){
			if (dist[v] > dist[u] + 1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << dist[i] << " ";
	cout << endl;


	return 0;
}