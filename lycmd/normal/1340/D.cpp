#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,mx;
vector<int>e[N];
vector<pair<int,int> >ans;
void dfs(int x,int fa,int cur){
	int t=cur;
	ans.push_back({x,t});
	for(int y:e[x]){
		if(y==fa)continue;
		if(t==mx)ans.push_back({x,t=mx-e[x].size()});
		dfs(y,x,++t),ans.push_back({x,t});
	}
	if(fa&&t!=cur-1)
		ans.push_back({x,cur-1});
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		mx=max(mx,(int)e[i].size());
	dfs(1,0,0);
	cout<<ans.size()<<"\n";
	for(auto i:ans)
		cout<<i.first<<" "<<i.second<<"\n";
}