#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int n,cur,fa[N],sz[N],hs[N],dep[N],tp[N],bt[N],sq[N],id[N];
vector<int>e[N];
int ask(char c,int x){
	return cout<<c<<" "<<x<<endl,cin>>x,x;
} 
void dfs1(int x,int pre){
	sz[x]=1,dep[x]=dep[pre]+1;
	for(int y:e[x]){
		if(y==pre)
			continue;
		dfs1(y,fa[y]=x),sz[x]+=sz[y];
		if(!hs[x]||sz[hs[x]]<sz[y])
			hs[x]=y;
	}
}
void dfs2(int x,int t){
	tp[x]=t,bt[t]=x,sq[id[x]=++cur]=x;
	if(hs[x])
		dfs2(hs[x],t);
	for(int y:e[x])
		if(y^fa[x]&&y^hs[x])
			dfs2(y,y);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1,x,y;i<n;i++)
		cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	dfs1(1,0),dfs2(1,1);
	for(int d=ask('d',1)+1,p=1;;p=ask('s',p)){
		int t=ask('d',bt[p]);
		p=sq[id[p]-dep[p]+(dep[bt[p]]+d-t)/2];
		if(dep[p]==d)
			cout<<"! "<<p<<endl,exit(0);
	}
}