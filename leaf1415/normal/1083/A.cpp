#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint n;
llint w[300005];
vector<edge> G[300005];

P dfs(llint v, llint pre)
{
	P ret = make_pair(0, w[v]);
	vector<llint> vec;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == pre) continue;
		P res = dfs(G[v][i].to, v);
		ret.first = max(ret.first, res.first);
		ret.first = max(ret.first, res.second);
		vec.push_back(res.second - G[v][i].cost);
	}
	if(vec.size() > 0){
		sort(vec.rbegin(), vec.rend());
		ret.second = max(ret.second, vec[0] + w[v]);
		if(vec.size() >= 2) ret.first = max(ret.first, vec[0]+vec[1]+w[v]);
	}
	return ret;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> w[i];
	llint u, v, c;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v >> c;
		G[u].push_back(edge(v, c));
		G[v].push_back(edge(u, c));
	}
	
	P ans = dfs(1, -1);
	cout << max(ans.first, ans.second) << endl;
	
	return 0;
}