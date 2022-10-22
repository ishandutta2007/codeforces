#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector<int> G[100005];

int dfs(int v, int prev)
{
	int ret = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == prev) continue;
		ret += dfs(G[v][i], v);
	}
	if(prev != -1 && ret % 2 == 0) ans++;
	return ret;
}

int main(void)
{
	cin >> n;
	int x, y;
	for(int i = 0; i < n-1; i++){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if(n % 2){
		cout << -1 << endl;
		return 0;
	}
	
	ans = 0;
	dfs(1, -1);
	cout << ans << endl;
	return 0;
}