#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,k,ans,sz[N],mx[N],vis[N],cnt[N];
vector<int>e[N],dep;
int getcore(int x,int fa,int tot){
	mx[x]=0,sz[x]=1;
	int r=0;
	for(int y:e[x]){
		if(y==fa||vis[y])continue;
		int p=getcore(y,x,tot);
		if(!r||mx[r]>mx[p])r=p;
		sz[x]+=sz[y],mx[x]=max(mx[x],sz[y]);
	}
	mx[x]=max(mx[x],tot-sz[x]);
	if(!r||mx[r]>mx[x])r=x;
	return r;
}
void dfs(int x,int fa,int d){
	if(d>k)return;
	dep.push_back(d);
	for(int y:e[x]){
		if(y==fa||vis[y])continue;
		dfs(y,x,d+1);
	}
}
void calc(int x){
	dep.clear();
	cnt[0]=1;
	for(int y:e[x]){
		if(vis[y])continue;
		int p=dep.size();
		dfs(y,x,1);
		for(int i=p;i<dep.size();i++)
			ans+=cnt[k-dep[i]];
		for(int i=p;i<dep.size();i++)
			cnt[dep[i]]++;
	}
	for(int k:dep)
		cnt[k]--;
}
void solve(int x){
	vis[x]=1,calc(x);
	for(int y:e[x]){
		if(vis[y])continue;
		solve(getcore(y,x,sz[y]));
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	solve(getcore(1,0,n));
	cout<<ans<<"\n";
}