#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, m, k;
vector<P> G[200005];
llint eu[200005], ev[200005];

vector<llint> g[200005];

llint dist[200005];
bool valid[200005];
vector<P> vec;

void dijkstra()
{
	for(int i = 1; i <= n; i++) dist[i] = inf;
	dist[1] = 0;
	
	priority_queue< P, vector<P>, greater<P> > Q;
	Q.push( make_pair(0, 1) );
	
	int v, d;
	while(Q.size()){
		d = Q.top().first;
		v = Q.top().second;
		Q.pop();
		if(dist[v] < d) continue;
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i].first] > d + 1){
				dist[G[v][i].first] = d + 1;
				Q.push( make_pair(dist[G[v][i].first], G[v][i].first) );
			}
		}
	}
}

llint id = 0;
vector< vector<int> > ans;

bool use[200005];
bool dfs(int i)
{
	if(i == vec.size()-1){
		ans.push_back( vector<int>() );
		for(int j = 0; j < m; j++){
			ans[id].push_back(use[j]);
		}
		id++;
		return id < k;
	}
	
	int v = vec[i].second;
	for(int j = 0; j < g[v].size(); j++){
		use[g[v][j]] = true;
		if(!dfs(i+1)) return false;
		use[g[v][j]] = false;
	}
	return true;
}

int main(void)
{
	cin >> n >> m >> k;
	llint u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].push_back(make_pair(v, i));
		G[v].push_back(make_pair(u, i));
		eu[i] = u, ev[i] = v;
	}
	
	dijkstra();
	
	for(int i = 0; i < m; i++){
		if(abs(dist[eu[i]] - dist[ev[i]]) == 1) valid[i] = true;
	}
	for(int i = 1; i <= n; i++){
		vec.push_back(make_pair(dist[i], i));
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			if(valid[G[i][j].second]){
				if(dist[i] > dist[G[i][j].first]){
					g[i].push_back(G[i][j].second);
				}
			}
		}
	}
	
	dfs(0);
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}