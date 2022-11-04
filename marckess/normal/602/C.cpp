#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

vvi adj;
int n, m, a, b;

int bfs (int c) {
	vi dist(n+1, -1);
	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while (q.size()) {
		int i = q.front();
		q.pop();

		for (int j = 1; j <= n; j++) {
			if (adj[i][j] == c && dist[j] == -1) {
				dist[j] = dist[i] + 1;
				q.push(j);
			}
		}
	}

	return dist[n];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	adj = vvi(n+1, vi(n+1));

	while (m--) {
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	cout << bfs(1 - adj[1][n]) << endl;

	return 0;
}