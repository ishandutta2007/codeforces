#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 5000 + 10;

vi adj[maxn];
int dist[maxn][maxn];

void bfs(int s){
	queue<int> q;
	dist[s][s] = 0; q.push(s);

	while (!q.empty()){
		int u = q.front(); q.pop();

		for (auto v : adj[u]){
			if (dist[s][v] > dist[s][u] + 1){
				dist[s][v] = dist[s][u] + 1;
				q.push(v);
			}
		}
	}
}

int n, m;

struct shovel{
	int64 u, tot, pri;

	bool operator <(const shovel &a) const{
		return pri < a.pri;
	}
};

vector<shovel> S;

bool solve(int s, int64 tot, int64 mon, int tm){
	for (auto sho : S){
		if (dist[s][sho.u] > tm) continue;

		int64 w = min(tot, sho.tot);

		if (w * sho.pri <= mon){
			tot -= w;
			mon -= w * sho.pri;

			if (tot == 0) break;
		}
		else break;
	}

	return tot == 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(dist, oo, sizeof dist);

	for (int i = 1; i <= n; ++i)
		bfs(i);

	int k; cin >> k;
	for (int i = 0; i < k; ++i){
		int64 u, p, c;
		cin >> u >> p >> c;
		S.push_back({u, p, c});
	}

	sort(S.begin(), S.end());

	int q; cin >> q;

	while (q--){
		int64 g, r, a;
		cin >> g >> r >> a;

		if (!solve(g, r, a, n))
			cout << -1 << endl;
		else{
			int l = -1, h = n;
			while (l + 1 < h){
				int m = (l + h) / 2;
				if (solve(g, r, a, m))
					h = m;
				else
					l = m;
			}

			cout << h << endl;
		}
	}

	return 0;
}