#include<bits/stdc++.h>
using namespace std;
int const N=333333;
int n,m,q,f[N],fa[N],fid[N],dep[N],cnt[N],deg[N];
vector<int>e[N],id[N],r1,r2,rt[N];
inline int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
inline void dfs(int x){
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		if(y==fa[x])continue;
		fid[y]=id[x][i],dep[y]=dep[x]+1,fa[y]=x,dfs(y);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		int fx=find(x),fy=find(y);
		if(fx!=fy)
			f[fx]=fy,e[x].push_back(y),e[y].push_back(x),id[x].push_back(i),id[y].push_back(i);
	}
	dfs(1);
	cin>>q;
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		r1.clear(),r2.clear();
		while(dep[x]>dep[y])r1.push_back(x),cnt[fid[x]]^=1,x=fa[x];
		while(dep[y]>dep[x])r2.push_back(y),cnt[fid[y]]^=1,y=fa[y]; 
		while(x!=y)
			r1.push_back(x),cnt[fid[x]]^=1,x=fa[x],r2.push_back(y),cnt[fid[y]]^=1,y=fa[y];
		r1.push_back(x);
		reverse(r2.begin(),r2.end());
		for(int i=0;i<r2.size();i++)
			r1.push_back(r2[i]);
		rt[i]=r1;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<e[i].size();j++)
			deg[i]^=cnt[id[i][j]];
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=deg[i];
	ans>>=1;
	if(ans)cout<<"NO\n"<<ans;
	else{
		cout<<"YES\n";
		for(int i=1;i<=q;i++,cout<<"\n"){
			cout<<rt[i].size()<<"\n";
			for(int j=0;j<rt[i].size();j++)
				cout<<rt[i][j]<<" ";
		}
	}
}