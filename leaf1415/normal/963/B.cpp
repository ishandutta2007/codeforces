#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> G[200005];
bool used[200005];

void del(int v, int prev)
{
	cout << v << endl;
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i]]) continue;
		if(G[v][i] == prev) continue;
		del(G[v][i], v);
	}
}

void dfs(int v, int prev)
{
	int deg = 0;
	if(prev != -1) deg++;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i]]) continue;
		if(G[v][i] == prev) continue;
		dfs(G[v][i], v);
		if(!used[G[v][i]]) deg++;
	}
	if(deg % 2 == 0) del(v, prev);
}

int main(void)
{
	cin >> n;
	int p;
	for(int i = 1; i <= n; i++){
		cin >> p;
		if(p != 0){
			G[i].push_back(p);
			G[p].push_back(i);
		}
	}
	
	if(n % 2){
		cout << "YES" << endl;
		dfs(1, -1);
	}
	else{
		cout << "NO" << endl;
	}
	
	return 0;
}