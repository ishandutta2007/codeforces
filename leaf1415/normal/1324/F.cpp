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
#include <utility>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<int, int> P;

int n;
vector<int> G[200005];
int a[200005];
map<P, int> mp;

void dfs(int v, int p)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v);
	}
	
	int dp = a[v];
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		int u = G[v][i];
		dp += max(0, mp[P(v, u)]);
	}
	mp[P(p, v)] = dp;
}

void dfs2(int v, int p)
{
	int sum = 0;
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i];
		sum += max(0, mp[P(v, u)]);
	}
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i];
		mp[P(u, v)] = sum - max(0, mp[P(v, u)]) + a[v];
	}
	
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs2(G[v][i], v);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 0) a[i] = -1;
	}
	int u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, -1);
	dfs2(1, -1);
	
	/*for(auto it = mp.begin(); it != mp.end(); it++){
		cout << it->first.first << " " << it->first.second << " " << it->second << endl;
	}*/
	
	for(int i = 1; i <= n; i++){
		llint ans = a[i];
		for(int j = 0; j < G[i].size(); j++){
			ans += max(0, mp[P(i, G[i][j])]);
		}
		cout << ans << " ";
	}
	cout << endl;
	
	return 0;
}