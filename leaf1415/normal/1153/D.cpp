#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, lnum;
int a[300005];
bool leaf[300005];
vector<int> G[300005];

int dfs(int v)
{
	if(G[v].size() == 0) return lnum;
	
	int ret;
	if(a[v] == 0) ret = lnum+1;
	else ret = 1;
	
	int res; vector<int> vec;
	for(int i = 0; i < G[v].size(); i++){
		res = dfs(G[v][i]);
		if(a[v] == 0) ret -= (lnum-res+1);
		else ret = max(ret, res);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int p;
	for(int i = 2; i <= n; i++){
		cin >> p;
		G[p].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		if(G[i].size() == 0){
			leaf[i] = true;
			lnum++;
		}
	}
	
	cout << dfs(1) << endl;
	return 0;
}