#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdio.h>
#include <map>
#define llint long long
#define inf 1e9

using namespace std;
typedef pair<llint, llint> P;

llint n;
vector<int> G[200005];
map<P, llint> mp, mp2;

llint dfs(int v, int p)
{
	llint ret = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		llint res = dfs(G[v][i], v);
		mp[make_pair(v, G[v][i])] = res;
		ret += res;
	}
	return ret;
}
void rdfs(int v, int p)
{
	llint sum = 0;
	for(int i = 0; i < G[v].size(); i++){
		sum += mp[make_pair(v, G[v][i])];
	}
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		mp[make_pair(G[v][i], v)] = sum - mp[make_pair(v, G[v][i])] + 1;
	}
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		rdfs(G[v][i], v);
	}
}

llint dfs2(int v, int p)
{
	llint sum = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		sum += mp[make_pair(v, G[v][i])];
	}
	llint ret = sum;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		llint res = dfs2(G[v][i], v);
		mp2[make_pair(v, G[v][i])] = res;
		ret += res;
	}
	return ret;
}
void rdfs2(int v, int p)
{
	llint sum = 1;
	for(int i = 0; i < G[v].size(); i++){
		sum += mp[make_pair(v, G[v][i])];
	}
	llint sum2 = 0;
	for(int i = 0; i < G[v].size(); i++){
		sum2 += mp2[make_pair(v, G[v][i])];
	}
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		mp2[make_pair(G[v][i], v)] = sum2 - mp2[make_pair(v, G[v][i])] + sum - mp[make_pair(v, G[v][i])];
	}
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		rdfs2(G[v][i], v);
	}
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	scanf("%d", &n); //cin >> n;
	int u, v;
	for(int i = 1; i <= n-1; i++){
		scanf("%d %d", &u, &v);
		//cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, -1), rdfs(1, -1); 
	dfs2(1, -1), rdfs2(1, -1);
	
	/*for(auto x : mp) cout << x.first.first << " " << x.first.second << " " << x.second << endl;
	cout << endl;
	for(auto x : mp2) cout << x.first.first << " " << x.first.second << " " << x.second << endl;*/
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		llint sum = 0;
		for(int j = 0; j < G[i].size(); j++) sum += mp2[make_pair(i, G[i][j])] + mp[make_pair(i, G[i][j])] + 1;
		ans = max(ans, sum);
	}
	printf("%I64d\n", ans);
	//cout << ans << endl;
	
	return 0;
}