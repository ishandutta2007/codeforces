#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> G[100005];

int main(void)
{
	cin >> n;
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int root = 0;
	for(int i = 1; i <= n; i++){
		if(G[i].size() >= 3){
			if(root){
				cout << "No" << endl;
				return 0;
			}
			else root = i;
		}
	}
	if(root == 0){
		for(int i = 1; i <= n; i++){
			if(G[i].size() == 1){
				root = i;
				break;
			}
		}
	}
	
	vector<int> leaf;
	for(int i = 1; i <= n; i++){
		if(i == root) continue;
		if(G[i].size() == 1) leaf.push_back(i);
	}
	
	cout << "Yes" << endl;
	cout << leaf.size() << endl;
	for(int i = 0; i < leaf.size(); i++){
		cout << root << " " << leaf[i] << endl;
	}
	
	return 0;
}