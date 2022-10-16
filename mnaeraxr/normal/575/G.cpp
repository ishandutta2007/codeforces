#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100100;
const int oo = 0x3f3f3f3f;

int n, m;
vector<pii> ady[maxn];
int dist[3][maxn];
int mk[maxn];
bool zero[maxn];
queue<int> nodes[2];
int from[maxn];

void bfs(int s, int *d, bool mode){
	for (int i = 0; i < n; ++i)
		d[i] = oo;
	queue<int> q;

	if (mode){
		queue<int> t;
		t.push(s);
		zero[s] = true;
		while (!t.empty()){
			int cur = t.front(); t.pop();
			
			d[cur] = 0;
			q.push(cur);

			for (auto nxt : ady[cur]){
				if (!zero[nxt.first] && nxt.second == 0){
					zero[nxt.first] = true;
					t.push(nxt.first);
					from[nxt.first] = cur;
				}
			}
		}
	}
	else{		
		d[s] = 0;
		q.push(s);
	}
	while (!q.empty()){
		int cur = q.front(); q.pop();
		for (auto nxt : ady[cur]){
			if (d[nxt.first] > d[cur] + 1){
				d[nxt.first] = d[cur] + 1;
				q.push(nxt.first);
			}
		}
	}
	assert(d[0] < oo && d[n - 1] < oo);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		ady[u].push_back(pii(v, w));
		ady[v].push_back(pii(u, w));
	}

	bfs(0, dist[0], false);
	bfs(n - 1, dist[1], true);
	bfs(n - 1, dist[2], false);

	int cur = 0, prev = 1;
	int sz = dist[0][n - 1];
	for (int i = 0; i < n; ++i){
		if (zero[i] && dist[0][i] < sz)
			sz = dist[0][i];
	}
	for (int i = 0; i < n; ++i){
		if (zero[i] && dist[0][i] == sz){
			nodes[0].push(i);
		}
	}

	for (int i = 0; i < n; ++i)
		mk[i] = 10;

	bool start = true;

	// cout << "SZ: " << sz << endl;

	for (int i = 0; i < sz; ++i){
		cur ^= 1; prev ^= 1;

		int v = 10;
		nodes[cur] = queue<int>();

		// cout << "DIST: " << sz << endl;
		while (!nodes[prev].empty()){
			int nxt = nodes[prev].front(); nodes[prev].pop();
			// cout << nxt << endl;
			for (auto neig : ady[nxt]){
				// cout << "neig: " << neig.first << " " << neig.second << endl;
				if (mk[neig.first] > neig.second && 
					dist[0][neig.first] == sz - i - 1 && 
					dist[0][neig.first] + dist[1][neig.first] == dist[1][0]){
					// cout << neig.first << " " << neig.second << endl;
					mk[neig.first] = neig.second;
					if (neig.second < v){
						nodes[cur] = queue<int>();
						v = neig.second;
						// cout << "REMOVE ALL" << endl;
					}
					if (neig.second == v){
						nodes[cur].push(neig.first);
						// cout << "PUSH " << neig.first << endl;
						from[neig.first] = nxt;
					}
				}

				if (mk[neig.first] == neig.second && neig.second == v &&
					dist[0][neig.first] == sz - i - 1 && 
					dist[0][neig.first] + dist[1][neig.first] == dist[1][0]){
					if (dist[2][ nxt ] < dist[2][ from[neig.first] ])
						from[neig.first] = nxt;
				}
			}
		}
		if (v != 0)
			start = false;

		if (!start)
			cout << v;
	}

	if (start)
		cout << 0;

	cout << endl;

	vector<int> ans;
	int cn = 0;
	while (cn != n - 1){
		ans.push_back(cn);
		cn = from[cn];
	}
	ans.push_back(cn);

	cout << ans.size() << endl;
	for (auto v : ans) 
		cout << v << " ";
	cout << endl;

	return 0;
}