#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> G[200005];
int a[200005];
int val[200005];

int main(void)
{
	cin >> n;
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 0; i < n; i++) cin >> a[i];
	val[1] = 1;
	
	int cur = 1, give = 2;
	for(int i = 0; i < n; i++){
		int v = a[i];
		//cout << v << " " << cur << " " << give << endl;
		if(val[v] == cur+1) cur++;
		else if(val[v] != cur){
			cout << "No" << endl;
			return 0;
		}
		bool flag = false;
		for(int j = 0; j < G[v].size(); j++){
			if(val[G[v][j]] == 0){
				val[G[v][j]] = give;
				flag = true;
			}
		}
		if(flag) give++;
	}
	//for(int i = 1; i <= n; i++) cout << val[i] << " "; cout << endl;
	cout << "Yes" << endl;
	return 0;
}