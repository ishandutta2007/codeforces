#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define llint long long

using namespace std;

llint n;
vector<llint> G[1005];
bool used[1005];

llint dfs(llint v, llint p)
{
	llint res;
	vector<llint> vec;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i]]) continue;
		vec.push_back(G[v][i]);
	}
	if(vec.size() >= 2){
		cout << "? " << vec[0] << " " << vec[1] << endl;
		cin >> res;
		if(res == vec[0]){
			used[v] = true;
			return dfs(vec[0], v);
		}
		else if(res == vec[1]){
			used[v] = true;
			return dfs(vec[1], v);
		}
		else{
			used[vec[0]] = used[vec[1]] = true;
			return dfs(v, -1);
		}
	}
	if(vec.size() == 0) return v;
	if(vec.size() == 1){
		if(vec[0] == p){
			cout << "? " << vec[0] << " " << v << endl;
			cin >> res;
			return res;
		}
		else return dfs(vec[0], v);
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
	int ans = dfs(1, -1);
	cout << "! " << ans << endl;

	return 0;
}