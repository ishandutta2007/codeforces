#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> G[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n == 2){
		cout << "YES" << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		if(G[i].size() == 2){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	
	return 0;
}