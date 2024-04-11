#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, m, k;
llint a[200005];
vector<llint> G[200005];
llint distS[200005], distT[200005];
P p[200005];

void bfs(llint dist[], llint S)
{
	for(int i = 1; i <= n; i++) dist[i] = inf;
	dist[S] = 0;
	
	queue<llint> Q;
	Q.push(S);
	
	llint v;
	while(Q.size()){
		v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i]] < inf) continue;
			dist[G[v][i]] = dist[v] + 1;
			Q.push(G[v][i]);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++) cin >> a[i];
	
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	bfs(distS, 1);
	bfs(distT, n);
	
	for(int i = 1; i <= k; i++) p[i] = P(distS[a[i]], distT[a[i]]);
	sort(p+1, p+k+1);
	
	llint ans = 0, mx = -inf;
	for(int i = k; i >= 1; i--){
		ans = max(ans, p[i].first + mx + 1);
		mx = max(mx, p[i].second);
	}
	ans = min(distS[n], ans);
	cout << ans << endl;
	
	return 0;
}