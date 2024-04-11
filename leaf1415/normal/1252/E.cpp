#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
vector<llint> G[100005];
llint depth[100005];
vector<llint> ans, ans2;

llint dfs(llint v)
{
	depth[v] = 0;
	for(int i = 0; i < G[v].size(); i++){
		depth[v] = max(depth[v], dfs(G[v][i]) + 1);
	}
	return depth[v];
}

void dfs2(llint v)
{
	if(G[v].size() == 0){
		ans2.push_back(v);
		return;
	}
	
	vector<P> vec;
	for(int i = 0; i < G[v].size(); i++){
		vec.push_back(make_pair(depth[G[v][i]], G[v][i]));
	}
	sort(vec.rbegin(), vec.rend());
	
	for(int i = 0; i < (int)vec.size()-1; i++){
		G[vec[i+1].second].push_back(vec[i].second);
		depth[vec[i+1].second] = depth[vec[i].second] + 1;
		ans.push_back(vec[i].second);
	}
	dfs2(vec.back().second);
	ans2.push_back(v);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint p;
	for(int i = 1; i < n; i++){
		cin >> p;
		G[p].push_back(i);
	}
	
	dfs(0);
	dfs2(0);
	
	reverse(ans.begin(), ans.end());
	reverse(ans2.begin(), ans2.end());
	
	for(int i = 0; i < ans2.size(); i++) cout << ans2[i] << " "; cout << endl;
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}