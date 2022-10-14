#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,mx,s,fa[N],col[N],sz[N],hs[N],ans[N],cnt[N];
vector<int>e[N];
void iniths(int x,int f){
	sz[x]=1;
	for(int y:e[x]){
		if(y==f)continue;
		iniths(y,fa[y]=x),sz[x]+=sz[y];
		if(!hs[x]||sz[hs[x]]<sz[y])
			hs[x]=y;
	}
}
void dfs(int x,int tp){
	if(++cnt[col[x]]>mx)
		mx=cnt[col[x]],s=col[x];
	else if(cnt[col[x]]==mx)
		s+=col[x];
	for(int y:e[x]){
		if(y==fa[x]||y==tp)
			continue;
		dfs(y,tp);
	}
}
void clear(int x){
	cnt[col[x]]--;
	for(int y:e[x]){
		if(y==fa[x])continue;
		clear(y);
	}
}
void solve(int x){
	if(!e[x].size())
		return;
	for(int y:e[x]){
		if(y==fa[x]||y==hs[x])
			continue;
		solve(y),clear(y),mx=s=0;
	}
	if(hs[x])
		solve(hs[x]);
	dfs(x,hs[x]),ans[x]=s;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>col[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	iniths(1,0);
	solve(1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
}