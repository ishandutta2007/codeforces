#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> G[100005];
priority_queue<int, vector<int>, greater<int> > Q;
bool used[100005];

void bfs()
{
	used[1] = true;
	
	Q.push(1);
	while(Q.size()){
		int v = Q.top();
		Q.pop();
		cout << v << " ";
		for(int i = 0; i < G[v].size(); i++){
			if(used[G[v][i]]) continue;
			Q.push(G[v][i]);
			used[G[v][i]] = true;
		}
	}
}

int main(void)
{
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	bfs();
	cout << endl;
	
	return 0;
}