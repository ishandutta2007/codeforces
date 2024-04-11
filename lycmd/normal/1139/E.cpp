#include<bits/stdc++.h>
using namespace std;
int const N=5010;
int n,m,q,a[N],b[N],c[N],vis[N],ans[N],in[N],mat[N];
vector<int>e[N];
int dfs(int x){
	for(int y:e[x]){
		if(in[y])continue;
		in[y]=1;
		if(!~mat[y]||dfs(mat[y]))
			return mat[y]=x,1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	cin>>q;
	for(int i=1;i<=q;i++)
		cin>>c[i],vis[c[i]]=1;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			e[a[i]].push_back(b[i]);
	memset(mat,-1,sizeof mat);
	for(int i=q,cur=0;i;i--){
		while(dfs(cur))
			cur++,memset(in,0,sizeof in);
		memset(in,0,sizeof in);
		ans[i]=cur,e[a[c[i]]].push_back(b[c[i]]);
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
}