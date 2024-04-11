#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define llint long long
 
using namespace std;
 
llint n, m, s;
llint w[200005];
vector<llint> G[200005];
bool cycle[200005];
bool used[200005];
llint order[200005];
llint sum[200005];

llint id = 1;
bool dfs(int v, int p)
{
	order[v] = id++;
	//cout << v << " " << order[v] << endl;
	bool ret = false;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(order[G[v][i]] != 0 && order[G[v][i]] < order[v]){
			ret = true;
			continue;
		}
		if(order[G[v][i]] == 0) ret |= dfs(G[v][i], v);
	}
	//cout << v << " " << ret << endl;
	return cycle[v] = ret;
}

llint dfs2(int v, int p)
{
	//cout << v << endl;
	used[v] = true;
	llint ret = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(used[G[v][i]]) continue;
		ret = max(ret, dfs2(G[v][i], v));
	}
	ret += w[v];
	//cout << v << " " << ret << endl;
	return sum[v] = ret;
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> w[i];
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cin >> s;
	
	dfs(s, -1);
	dfs2(s, -1);
	
	/*for(int i = 1; i <= n; i++) cout << cycle[i] << " "; cout << endl;
	for(int i = 1; i <= n; i++) cout << order[i] << " "; cout << endl;
	for(int i = 1; i <= n; i++) cout << sum[i] << " "; cout << endl;
	*/
	
	llint ans = 0, mx = 0;
	for(int i = 1; i <= n; i++){
		if(cycle[i]) ans += w[i];
		else mx = max(mx, sum[i]);
	}
	ans += mx;
	cout << ans << endl;
	
	return 0;
}