#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int ans = 0;
vector<int> edges[200000];
int vis[200000];
int vcount = 0;
int ecount = 0;
void dfs(int i){
	if(vis[i]) return;
	vis[i] = 1;
	vcount++;
	ecount += edges[i].size();
	for(int a = 0; a < edges[i].size(); a++) dfs(edges[i][a]);
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		vis[i] = 0;
	}
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edges[a-1].push_back(b-1);
		edges[b-1].push_back(a-1);
	}
	for(int i = 0; i < n; i++){
		vcount = 0;
		ecount = 0;
		dfs(i);
		if(vcount > ecount/2){
			ans++;
		}
	}
	cout << ans << endl;
}