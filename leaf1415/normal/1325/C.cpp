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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;
struct edge{
	llint to, id;
	edge(){}
	edge(llint a, llint b){
		to = a, id = b;
	}
};

llint n;
vector<edge> G[100005];
llint ans[100005];
llint dist[100005];

void dfs(int v, int p, int d)
{
	dist[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p) continue;
		dfs(G[v][i].to, v, d+1);
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint u, v;
	rep(i, 0, n-1){
		cin >> u >> v;
		G[u].push_back(edge(v, i));
		G[v].push_back(edge(u, i));
	}
	
	bool flag = false;
	rep(j, 0, n-1) ans[j] = -1;
	Rep(i, 1, n){
		if(G[i].size() >= 3){
			flag = true;
			ans[G[i][0].id] = 0;
			ans[G[i][1].id] = 1;
			ans[G[i][2].id] = 2;
			break;
		}
	}
	
	llint id = 3;
	if(!flag) id = 0;
	rep(j, 0, n-1){
		if(ans[j] == -1) ans[j] = id++;
	}
	rep(j, 0, n-1) cout << ans[j] << endl;
	
	return 0;
}