#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint n, x, y;
vector<llint> G[300005];
llint cnt[300005];

llint dfs(llint v, llint prev)
{
	llint ret = 1;
	for(llint i = 0; i < G[v].size(); i++){
		if(G[v][i] == prev) continue;
		ret += dfs(G[v][i], v);
	}
	return cnt[v] = ret;
}

int main(void)
{
	cin >> n >> x >> y;
	llint a, b;
	for(llint i = 0; i < n-1; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs(x, -1);
	llint xnum = cnt[y];
	dfs(y, -1);
	llint ynum = cnt[x];
	
	cout << n * (n-1) - xnum * ynum << endl;
	return 0;
}