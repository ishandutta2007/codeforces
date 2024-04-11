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

struct edge{
	llint to, type;
	edge(){}
	edge(llint a, llint b){
		to = a, type = b;
	}
};

llint n, m;
map<P, llint> mp;
vector<edge> G[500005];
llint dist[500005];
llint ans[500005];

void bfs()
{
	queue<llint> Q;
	Q.push(n);
	
	for(int i = 1; i <= n; i++) dist[i] = inf;
	dist[n] = 0;
	
	while(Q.size()){
		llint v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			llint u = G[v][i].to, t = G[v][i].type;
			if(dist[u] < inf/2) continue;
			if(ans[u] != -1){
				if((t&(1<<ans[u])) == 0) continue;
			}
			else{
				if(t == 1){
					ans[u] = 1;
					continue;
				}
				if(t == 2){
					ans[u] = 0;
					continue;
				}
				ans[u] = 0;
			}
			Q.push(u);
			dist[u] = dist[v] + 1;
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v, t;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> t;
		mp[P(u, v)] |= 1<<t;
	}
	
	for(auto it = mp.begin(); it != mp.end(); it++){
		P e = it->first;
		G[e.second].push_back(edge(e.first, it->second));
	}
	
	for(int i = 1; i <= n; i++) ans[i] = -1;
	bfs();
	
	for(int i = 1; i <= n; i++) if(ans[i] == -1) ans[i] = 0;
	
	if(dist[1] > inf/2) cout << -1 << endl;
	else cout << dist[1] << endl;
	
	for(int i = 1; i <= n; i++) cout << ans[i]; cout << endl;
	
	return 0;
}