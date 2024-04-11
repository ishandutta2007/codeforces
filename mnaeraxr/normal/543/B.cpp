#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define SZ(x) ((int)x.size())
#define DB(x) cout << #x << "=" << x << endl
#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1e-7;
const int MOD = (int)1e9 + 7;
const int MAXN = 3010;
const int oo = 1 << 25;

vi ady[MAXN];
int dist[MAXN][MAXN];
int n, m;

void bfs(int s){
	for (int i = 1; i <= n; ++i)
		dist[s][i] = oo;

	dist[s][s] = 0;
	queue<int> Q;
	Q.push(s);

	while (!Q.empty()){
		int cur = Q.front(); Q.pop();
		for (auto nxt : ady[cur]){
			if (dist[s][nxt] < oo) continue;
			dist[s][nxt] = dist[s][cur] + 1;
			Q.push(nxt);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		ady[u].push_back(v);
		ady[v].push_back(u);
	}

	int s1, t1, l1;
	int s2, t2, l2;
	cin >> s1 >> t1 >> l1;
	cin >> s2 >> t2 >> l2;

	for (int i = 1; i <= n; ++i)
		bfs(i);


	if (dist[s1][t1] > l1 || dist[s2][t2] > l2){
		cout << -1 << endl;
		exit(0);
	}

	int best = m - dist[s1][t1] - dist[s2][t2];

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			int d1 = dist[s1][i] + dist[i][j] + dist[j][t1];
			int d2 = dist[s2][i] + dist[i][j] + dist[j][t2];
			if (d1 <= l1 && d2 <= l2)
				best = max(best, m - d1 - d2 + dist[i][j]);

			int d3 = dist[t2][i] + dist[i][j] + dist[j][s2];
			if (d1 <= l1 && d3 <= l2)
				best = max(best, m - d1 - d3 + dist[i][j]);

		}
	}

	cout << best << endl;

	return 0;
}