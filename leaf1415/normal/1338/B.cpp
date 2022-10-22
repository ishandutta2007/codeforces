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

llint n;
vector<llint> G[100005];
llint color[100005];
vector<llint> vec;

void dfs(int v, int p, int c)
{
	color[v] = c;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v, -c);
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, -1, 1);
	
	for(int i = 1; i <= n; i++){
		if(G[i].size() == 1) vec.push_back(color[i]);
	}
	sort(vec.begin(), vec.end());
	
	llint ans, ans2 = 0;
	if(vec.front() == vec.back()) ans = 1;
	else ans = 3;
	
	for(int i = 1; i <= n; i++){
		bool flag = false;
		for(int j = 0; j < G[i].size(); j++){
			llint v = G[i][j];
			if(G[i].size() >= 2 && G[v].size() == 1) flag = true;
			if(v < i) continue;
			if(G[i].size() >= 2 && G[v].size() >= 2) ans2++;
		}
		if(flag) ans2++;
	}
	cout << ans << " " << ans2 << endl;
	
	return 0;
}