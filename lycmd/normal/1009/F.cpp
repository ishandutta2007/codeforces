#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int n,fa[N],dep[N],hs[N],top[N],ans[N];
vector<int>e[N];
map<int,deque<int> >f;
void dfs1(int x,int f){
	fa[x]=f,dep[x]=1;
	for(int y:e[x]){
		if(y==f)continue;
		dfs1(y,x),dep[x]=max(dep[x],dep[y]+1);
		if(!hs[x]||dep[hs[x]]<dep[y])
			hs[x]=y;
	}
}
void dfs2(int x,int tp){
	top[x]=tp;
	if(!hs[x])return;
	dfs2(hs[x],tp);
	for(int y:e[x])
		if(y^fa[x]&&y^hs[x])
	    	dfs2(y,y);
}
void solve(int x){
	if(hs[x])
		solve(hs[x]),ans[x]=ans[hs[x]]+1;
	f[top[x]].push_front(1);
	int&res=ans[x]; 
	if(f[top[x]][res]==1)ans[x]=0;
	for(int y:e[x]){
		if(y==fa[x]||y==hs[x])
			continue;
		solve(y);
		for(int i=1;i<=f[y].size();i++){
			f[top[x]][i]+=f[y][i-1];
			if(f[top[x]][i]>f[top[x]][res]||f[top[x]][i]==f[top[x]][res]&&i<ans[x])
				res=i;
		}
		f.erase(y);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs1(1,0),dfs2(1,1),solve(1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<"\n";
}