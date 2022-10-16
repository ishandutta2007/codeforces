#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<pair<int,int64>> vi;

const int maxn = 100100;
const int64 oo = 0x3f3f3f3f3f3f3f3f;

int64 dist[maxn];
int to[maxn];

vi ady[maxn];

void dijkstra(int n){
	priority_queue<pair<int64,int>> PQ;
	memset(dist, 0x3f3f3f3f, sizeof dist);
	memset(to, -1, sizeof to);

	dist[n] = 0;
	PQ.push({0, n});

	while (!PQ.empty()){
		auto cur = PQ.top();
		PQ.pop();

		int64 d = -cur.first;
		int cn = cur.second;

		if (dist[cn] < d)
			continue;

		for (auto nxt : ady[cn]){
			if (dist[cn] + nxt.second < dist[nxt.first]){
				dist[nxt.first] = dist[cn] + nxt.second;
				to[nxt.first] = cn;
				PQ.push({-dist[nxt.first], nxt.first});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// freopen("data.in", "r", stdin);		

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i){
		int u, v;
		int64 w;
		cin >> u >> v >> w;
		ady[u].push_back({v, w});
		ady[v].push_back({u, w});
	}

	dijkstra(n);

	if (dist[1] == oo)
		cout << -1 << endl;
	else{
		cout << 1;
		int cur = 1;
		do{
			cur = to[cur];
			cout << " " << cur;
		} while(cur != n);
		cout << endl;
	}

	return 0;
}