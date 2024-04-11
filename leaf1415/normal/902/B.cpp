#include <iostream>
#include <vector>

using namespace std;

int n;
int C[10005];
vector<int> G[10005];

int dfs(int v, int c)
{
	int ret = 0;
	if(c != C[v]){
		c = C[v];
		ret++;
	}
	
	for(int i = 0; i < G[v].size(); i++){
		ret += dfs(G[v][i], c);
	}
	return ret;
}

int main(void)
{
	cin >> n;
	int p;
	for(int i = 2; i <= n; i++){
		cin >> p;
		G[p].push_back(i);
	}
	for(int i = 1; i <= n; i++) cin >> C[i];
	
	cout << dfs(1, 0) << endl;
	return 0;
}