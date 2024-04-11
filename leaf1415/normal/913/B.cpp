#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> G[1005];

bool dfs(int v)
{
	int cnt = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[G[v][i]].size() == 0) cnt++;
		else if(!dfs(G[v][i])) return false;
	}
	return cnt >= 3;
}

int main(void)
{
	cin >> n;
	int p;
	for(int i = 2; i <= n; i++){
		cin >> p;
		G[p].push_back(i);
	}
	
	if(dfs(1)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}