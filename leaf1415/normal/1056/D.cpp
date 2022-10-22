#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> G[100005];
vector<int> vec;
int num[100005];

int dfs(int v)
{
	if(G[v].size() == 0) return num[v] = 1;
	int ret = 0;
	for(int i = 0; i < G[v].size(); i++){
		ret += dfs(G[v][i]);
	}
	return num[v] = ret;
}

int main(void)
{
	cin >> n;
	int p;
	for(int i = 2; i <= n; i++){
		cin >> p;
		G[p].push_back(i);
	}
	
	dfs(1);
	for(int i = 1; i <= n; i++){
		vec.push_back(num[i]);
	}
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
	cout << endl;
	
	return 0;
}