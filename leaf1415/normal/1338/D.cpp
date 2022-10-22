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
#define inf 1e18
#define rep(x, s, t) for(int (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(int (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<int, int> P;

int n;
vector<int> G[100005];
map<P, int> mp[2];

void dfs(int v, int p)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v);
	}
	
	int mx = 0, cnt = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		mx = max(mx, mp[0][P(v, G[v][i])]);
		mx = max(mx, mp[1][P(v, G[v][i])]);
		cnt++;
	}
	mp[0][P(p, v)] = mx + cnt - 1;
	
	mx = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		int u = G[v][i];
		mx = max(mx, mp[0][P(v, u)]);
	}
	mp[1][P(p, v)] = mx+1;
}

int lmax[100005], rmax[100005];
void dfs2(int v, int p)
{
	int m = G[v].size();
	
	int mx = 0; lmax[0] = 0;
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i];
		mx = max(mx, mp[0][P(v, u)]);
		mx = max(mx, mp[1][P(v, u)]);
		lmax[i+1] = mx;
	}
	mx = 0; rmax[m+1] = 0;
	for(int i = (int)G[v].size()-1; i >= 0; i--){
		int u = G[v][i];
		mx = max(mx, mp[0][P(v, u)]);
		mx = max(mx, mp[1][P(v, u)]);
		rmax[i+1] = mx;
	}
	
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		int u = G[v][i];
		mp[0][P(u, v)] = max(lmax[i], rmax[i+2]) + m-2;
	}
	
	
	
	
	mx = 0; lmax[0] = 0;
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i];
		mx = max(mx, mp[0][P(v, u)]);
		lmax[i+1] = mx;
	}
	mx = 0; rmax[m+1] = 0;
	for(int i = (int)G[v].size()-1; i >= 0; i--){
		int u = G[v][i];
		mx = max(mx, mp[0][P(v, u)]);
		rmax[i+1] = mx;
	}
	
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		int u = G[v][i];
		mp[1][P(u, v)] = max(lmax[i], rmax[i+2]) + 1;
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
	int u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, -1);
	dfs2(1, -1);
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			int u = G[i][j];
			ans = max(ans, mp[0][P(i, u)] + 1);
		}
	}
	cout << ans << endl;
	
	return 0;
}