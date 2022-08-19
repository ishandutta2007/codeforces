#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef long long LL;
vector<pair<int,int> > edges[100020];
int vis[100020];
int parent[100020];
int problem[100020];
int dfs(int k){
	vis[k] = 1;
	for(int i = 0; i < edges[k].size(); i++){
		if(!vis[edges[k][i].first]){
			parent[edges[k][i].first] = k;
			problem[edges[k][i].first] = edges[k][i].second;
			dfs(edges[k][i].first);
		}
	}
	//cout << k << " " << parent[k] << endl;
}
int vis2[100020];
int main(){
  int n;
  for(int i = 0; i < 100020; i++) vis[i] = vis2[i] = 0;
  cin >> n;
  for(int i = 0; i < n-1; i++){
	  int x, y, t;
	  cin >> x >> y >> t;
	  edges[x-1].push_back(make_pair(y-1, t-1));
	  edges[y-1].push_back(make_pair(x-1, t-1));
  }
  parent[0] = -1;
  problem[0] = 0;
  dfs(0);
  vis2[0] = 1;
  for(int i = 1; i < n; i++){
	  if(problem[i] && ! vis2[i]){
		  int cur = i;
		  while(!vis2[cur]){
			  if(cur != i) vis2[cur] = 1;
			  cur = parent[cur];
			  problem[cur] = 0;
		  }
	  }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) ans += problem[i];
  cout << ans << endl;
  for(int i = 0; i < n; i++) if(problem[i]) cout << i+1 << " ";
  cout << endl;
}