#include <iostream>
#include <vector>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[300005];
vector<llint> G[300005];

P dfs(int v, int pre)
{
	P ret = make_pair(a[v], -inf);
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		P res = dfs(G[v][i], v);
		if(res.first > 0) ret.first += res.first;
		ret.second = max(ret.second, max(res.first, res.second));
	}
	return ret;
}

llint k = 0;
llint dfs2(int v, int pre, llint ans)
{
	llint ret = a[v];
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		llint res = dfs2(G[v][i], v, ans);
		if(res > 0) ret += res;
	}
	if(ret == ans) k++, ret = 0;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	P ret = dfs(1, -1);
	llint ans = max(ret.first, ret.second);
	dfs2(1, -1, ans);
	cout << ans*k << " " << k << endl;
	
	return 0;
}