#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 123457;

int TOTAL;

vi ady[maxn];
bool special[maxn];
bool dead[maxn];
int degree[maxn];
int dist1[maxn];
int dist2[maxn];

pii dfs(int s, int f, int *dist){
	if (f == -1) dist[s] = 0;
	pii ans(dist[s], s);
	for (auto u : ady[s]) if (u != f && !dead[u]){
		dist[u] = dist[s] + 1;
		ans = max(ans, dfs(u, s, dist));
	}
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	TOTAL = m;
	for (int i = 1; i < n; ++i){
		int u, v;
		cin >>  u >> v;
		ady[u].push_back(v);		
		ady[v].push_back(u);
		degree[u]++; degree[v]++;
	}

	int start;
	for (int i = 0; i < m; ++i){
		int u; cin >> u;
		start = u;
		special[u] = true;
	}

	queue<int> q;

	for (int i = 1; i <= n; ++i)
		if (degree[i] == 1 && !special[i]) q.push(i);

	int tot = n;

	while (!q.empty()){
		auto u = q.front(); q.pop();
		dead[u] = true; --tot;
		for (auto v : ady[u]){
			degree[v]--;
			if (degree[v] == 1 && !special[v])
				q.push(v); 
		}
	}

	pii cur1 = dfs(dfs(start, -1, dist1).second, -1, dist2);
	pii cur2 = dfs(cur1.second, -1, dist1);
	assert(cur1.first == cur2.first);
	vector<int> center;

	for (int i = 1; i <= n; ++i){
		if (!dead[i] && max(dist1[i], dist2[i]) == (cur1.first + 1) / 2){
			center.push_back(i);
		}
	}

	dfs(center[0], -1, dist1);
	dfs(center[center.size() == 2 ? 1 : 0], -1, dist2);

	int ans = -1;
	for (int i = 1; i <= n && ans == -1; ++i){
		if (!dead[i] && min(dist1[i], dist2[i]) == cur1.first / 2)
			ans = i;
	}

	cout << ans << endl;
	cout << (tot - 1) * 2 - cur1.first << endl;

	return 0;
}