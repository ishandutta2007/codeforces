#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> P;

int n;
int a[300005];
vector<int> G[300005];
int R, B;

int ans;
P dfs(int v, int pre)
{
	P ret = make_pair(0, 0);
	if(a[v] == 1) ret.first++;
	if(a[v] == 2) ret.second++;
	
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		P res = dfs(G[v][i], v);
		if(res.first == R && res.second == 0) ans++;
		if(res.first == 0 && res.second == B) ans++;
		ret.first += res.first, ret.second += res.second;
	}
	return ret;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++){
		if(a[i] == 1) R++;
		if(a[i] == 2) B++;
	}
	
	int u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, -1);
	cout << ans << endl;
	
	return 0;
}