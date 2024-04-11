#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<pii> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 300010;

set<pii> bridges;
vi adj[maxn];
int lo[maxn], num[maxn];
int mk[maxn];
int tmr;

void dfs(int u, int f){
	lo[u] = num[u] = tmr++;
	for (auto e : adj[u]){
		int v = e.first;
		if (f == v) continue;

		if (!num[v]){
			dfs(v, u);
			if (num[v] == lo[v]){
				bridges.insert({u, v});
			}
		}
		lo[u] = min(lo[u], lo[v]);
	}
}

bool isBridge(int u, int v){
	return bridges.count(pii(u, v)) || bridges.count(pii(v, u));
}

int solve(int u, int fin){
	queue<int> q;
	q.push(u);
	mk[u] = true;

	vector<pii> nxt;

	int ans = 0;

//	cout << "start bfs: " << u << endl;

	while (!q.empty()){
		u = q.front(); q.pop();

//		cout << "get: " << u << endl;

		if (u == fin) ans |= 1;

		for (auto e : adj[u]){
			int v = e.first;
			if (!mk[v] && isBridge(u, v)) nxt.push_back(e);
			else{
				if (e.second) ans |= 2;
				if (!mk[v]){
					mk[v] = true;
					q.push(v);
				}
			}
		}
	}

	if (ans & 1)
		return ans;

	for (auto e : nxt){
		int cur = solve(e.first, fin);

		if (cur & 1){
			ans |= cur;
			if (e.second) ans |= 2;
			return ans;
		}

	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	int a, b; cin >> a >> b;

	tmr = 1;
	dfs(1, -1);

	if (solve(a, b) == 3) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
/*
6 6
1 2 1
2 3 0
2 6 1
3 4 0
6 4 0
4 5 0
2 5
 */