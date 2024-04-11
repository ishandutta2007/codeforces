#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,k,cur,v[N],in[N],h[N],vis[N];
queue<int>q;
vector<int>e[N],g[N],ans;
void dfs(int x){
	vis[x]=1;
	for(int y:e[x])
		if(!vis[y])dfs(y);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	while(k--){
		int x;cin>>x;v[x]=1;
	}
	for(int i=1,t,x;i<=n;i++)
		for(cin>>t;t--;)
			cin>>x,g[x].push_back(i),e[i].push_back(x),in[i]++;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		h[x]=++cur;
		for(int y:g[x])
			if(!--in[y])
				q.push(y);
	}
	for(int i=1;i<=n;i++)
		if(in[i]&&v[i])
			cout<<"-1\n",exit(0);
	for(int i=1;i<=n;i++)
		if(v[i])
			dfs(i);
	for(int i=1;i<=n;i++)
		if(vis[i])
			ans.push_back(i);
	sort(ans.begin(),ans.end(),[&](int x,int y){
		return h[x]<h[y];
	});
	cout<<ans.size()<<"\n";
	for(int x:ans)cout<<x<<" ";
}