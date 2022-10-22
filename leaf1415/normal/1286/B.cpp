#include <iostream>
#include <cstdlib>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

llint n;
vector<llint> G[2005];
llint root, c[2005];
llint a[2005];

vector<llint> dfs(llint v)
{
	vector<llint> ret, tmp;
	for(int i = 0; i < G[v].size(); i++){
		tmp = dfs(G[v][i]);
		ret.insert(ret.end(), tmp.begin(), tmp.end());
	}
	if(c[v] > ret.size()){
		cout << "NO" << endl;
		exit(0);
	}
	ret.insert(ret.begin() + c[v], v);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint p;
	for(int i = 1; i <= n; i++){
		cin >> p >> c[i];
		if(p == 0) root = i;
		else G[p].push_back(i);
	}
	
	vector<llint> ans = dfs(root);
	
	cout << "YES" << endl;
	for(int i = 0; i < ans.size(); i++) a[ans[i]] = i+1;
	for(int i = 1; i <= n; i++) cout << a[i] << " ";  cout << endl;
	
	return 0;
}