#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 410;

bool adj[maxn][maxn];
int dist[maxn];

int bfs(int e, int f){
	queue<int> q; q.push(1);
	memset(dist, oo, sizeof dist);
	dist[1] = 0;
	while (!q.empty()){
		int u = q.front(); q.pop();
		if (u == f) return dist[f];
		for (int i = 2; i <= f; ++i){
			if (adj[u][i] == e && dist[i] == oo)
			{
				dist[i] = dist[u] + 1;
				q.push(i);
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		adj[u][v] = adj[v][u] = true;
	}

	cout << bfs(0, n) + bfs(1, n) - 1 << endl;

	return 0;
}