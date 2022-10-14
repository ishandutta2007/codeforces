#include<bits/stdc++.h>
using namespace std;
int const N=300010;
int t,n,lf,sz[N],fa[N];
vector<int>e[N],c;
void dfs(int x,int pre){
	sz[x]=1,fa[x]=pre;
	for(int y:e[x]){
		if(y==pre)continue;
		dfs(y,x),sz[x]+=sz[y];
	}
	if(sz[x]==1)lf=x;
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,0),c.clear();
		for(int i=1;i<=n;i++){
			int mx=n-sz[i];
			for(int y:e[i])
				if(y^fa[i])
					mx=max(mx,sz[y]);
			if(mx<=n/2)
				c.push_back(i);
		}
		if(c.size()==1)
			cout<<lf<<" "<<fa[lf]<<"\n"<<lf<<" "<<fa[lf]<<"\n";
		else
			dfs(c[0],c[1]),cout<<lf<<" "<<fa[lf]<<"\n"<<lf<<" "<<c[1]<<"\n";
	}
}