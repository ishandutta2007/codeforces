/*input
7 6 3 2
1 2 3 3 2 2 1
1 2
2 3
3 4
2 5
5 6
6 7

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 100005
#define bit(x,y) ((x>>y)&1LL)
#define For(i,l,r) for(int i=l; i<r; i++)

int n, m, k, s;
vector<int> type[105];
vector<vector<int> > a(N);
int dis[N][105];

queue<int> q;
void buildTree(int id) {
	for (int i = 1; i <= n; i++) dis[i][id] = 1e9;
	for (auto it : type[id]) {
		dis[it][id] = 0;
		q.push(it);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto it : a[u]) {
			if (dis[it][id] > dis[u][id] + 1) {
				dis[it][id] = dis[u][id] + 1;
				q.push(it);
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k >> s;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		type[t].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= k; i++) {
		buildTree(i);
	}
	for (int i = 1; i <= n; i++) {
		sort(dis[i] + 1, dis[i] + k + 1);
		int cost = 0;
		for (int j = 1; j <= s; j++) cost += dis[i][j];
		cout << cost << sp;
	}
}