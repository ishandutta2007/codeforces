#include<bits/stdc++.h>
#define int long long
using namespace std;
int ok,ans[100005];
vector<pair<int,int>> edge[100005];
void dfs(int now,int fa,int w){
	if(edge[now].size()>2){ok=0;return ;}
	if(ok==0)return ;
	if(w==0)
		if(edge[now].size()==2)ans[edge[now][0].second]=2,dfs(edge[now][0].first,now,2),ans[edge[now][1].second]=5,dfs(edge[now][1].first,now,5);
		else ans[edge[now][0].second]=2,dfs(edge[now][0].first,now,2);
	else{
		for(int i=0;i<edge[now].size();i++){
			int v=edge[now][i].first,id=edge[now][i].second;
			if(v==fa)continue;
			if(w==2)ans[id]=5;
			else ans[id]=2;
			dfs(v,now,ans[id]);
		}
	}
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)edge[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back({v,i});
			edge[v].push_back({u,i});
		}
		ok=1;
		dfs(1,0,0);
		if(ok==0)cout<<-1;
		else for(int i=1;i<n;i++)cout<<ans[i]<<" ";
		cout<<endl;
	}
}