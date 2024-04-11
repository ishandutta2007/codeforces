#include<bits/stdc++.h>
using namespace std;
int const N=500010,B=22,M=5000010;
int n,dep[N],s[N],sz[N],hs[N],ans[N],f[M];
vector<pair<int,int> >e[N];
void dfs(int x){
	sz[x]=1;
	for(auto[y,k]:e[x]){
		s[y]=k^s[x],dep[y]=dep[x]+1;
		dfs(y),sz[x]+=sz[y];
		if(!hs[x]||sz[hs[x]]<sz[y])
			hs[x]=y;
	}
}
void clear(int x){
	f[s[x]]=-0x3f3f3f3f;
	for(auto[y,k]:e[x])clear(y);
}
void upd(int x,int rt){
	ans[rt]=max(ans[rt],dep[x]+f[s[x]]);
	for(int i=0;i<B;i++)
		ans[rt]=max(ans[rt],dep[x]+f[s[x]^1<<i]);
	for(auto[y,k]:e[x])upd(y,rt);
}
void add(int x){
	f[s[x]]=max(f[s[x]],dep[x]);
	for(auto[y,k]:e[x])add(y);
}
void solve(int x){
	for(auto[y,k]:e[x])
		if(y^hs[x])
			solve(y),clear(y);
	if(hs[x])solve(hs[x]);
	for(auto[y,k]:e[x])
		if(y^hs[x])
			upd(y,x),add(y);
	f[s[x]]=max(f[s[x]],dep[x]);
	ans[x]=max(ans[x],dep[x]+f[s[x]]);
	for(int i=0;i<B;i++)
		ans[x]=max(ans[x],dep[x]+f[s[x]^1<<i]);
	ans[x]-=dep[x]*2;
	for(auto[y,k]:e[x])
		ans[x]=max(ans[x],ans[y]);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=2;i<=n;i++){
		int x;char c;cin>>x>>c;
		e[x].push_back({i,1<<(c-97)});
	}
	memset(f,0xc0,sizeof f);
	dfs(1),solve(1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}