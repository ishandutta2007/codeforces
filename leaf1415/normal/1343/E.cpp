#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, m, a, b, c;
llint p[200005], psum[200005];
vector<llint> G[200005];
llint distA[200005], distB[200005], distC[200005];

void bfs(int S, llint dist[])
{
	queue<int> Q;
	Q.push(S);
	
	for(int i = 1; i <= n; i++) dist[i] = inf;
	dist[S] = 0;
	
	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i]] < inf/2) continue;
			Q.push(G[v][i]);
			dist[G[v][i]] = dist[v] + 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m >> a >> b >> c;
		for(int i = 1; i <= m; i++) cin >> p[i];
		sort(p+1, p+m+1);
		for(int i = 1; i <= m; i++) psum[i] = psum[i-1] + p[i];
		
		for(int i = 1; i <= n; i++) G[i].clear();
		llint u, v;
		for(int i = 1; i <= m; i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		bfs(a, distA);
		bfs(b, distB);
		bfs(c, distC);
		
		llint ans = inf;
		for(int i = 1; i <= n; i++){
			if(distB[i]+distA[i]+distC[i] > m) continue;
			llint sum = psum[distB[i]]*2 + psum[distB[i]+distA[i]+distC[i]] - psum[distB[i]];
			ans = min(ans, sum);
		}
		cout << ans << "\n";
	}
	flush(cout);
	return 0;
}