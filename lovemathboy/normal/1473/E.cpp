#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main() {
	int tc;
	//scanf("%d", &tc);
	//while (tc--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<vector<pair<int, int> > > adj;
		adj.resize(4*n+5);
		int i1, i2, i3;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &i1, &i2, &i3);
			adj[i1].push_back(make_pair(i2, i3));
			adj[i2].push_back(make_pair(i1, i3));
			adj[i1].push_back(make_pair(i2+n, 0));
			adj[i2].push_back(make_pair(i1+n, 0));
			adj[i1].push_back(make_pair(i2+2*n, 2*i3));
			adj[i2].push_back(make_pair(i1+2*n, 2*i3));
			adj[i1].push_back(make_pair(i2+3*n, i3));
			adj[i2].push_back(make_pair(i1+3*n, i3));
			adj[i1+n].push_back(make_pair(i2+n, i3));
			adj[i2+n].push_back(make_pair(i1+n, i3));
			adj[i1+n].push_back(make_pair(i2+3*n, 2*i3));
			adj[i2+n].push_back(make_pair(i1+3*n, 2*i3));
			adj[i1+2*n].push_back(make_pair(i2+3*n, 0));
			adj[i2+2*n].push_back(make_pair(i1+3*n, 0));
			adj[i1+2*n].push_back(make_pair(i2+2*n, i3));
			adj[i2+2*n].push_back(make_pair(i1+2*n, i3));
			adj[i1+3*n].push_back(make_pair(i2+3*n, i3));
			adj[i2+3*n].push_back(make_pair(i1+3*n, i3));
		}
		vector<long long> dis;
		dis.resize(4*n+5, 101234567890123456LL);
		dis[1] = 0;
		priority_queue<pair<long long, int> > pq;
		pq.push(make_pair(0, 1));
		while (!pq.empty()) {
			int x = pq.top().second;
			long long d = -pq.top().first;
			pq.pop();
			if (dis[x] != d) continue;
			for (int i = 0; i < adj[x].size(); i++) {
				int v = adj[x][i].first;
				int w = adj[x][i].second;
				if (dis[v] > d + w) {
					dis[v] = d + w;
					pq.push(make_pair(-(d + w), v));
				}
			}
		}
		for (int i = 3*n+2; i <= 4*n; i++) {
			printf("%lld ", dis[i]);
		}
	//}
	return 0;
}